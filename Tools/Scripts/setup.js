'use strict';

/**
 * Sets up a Windows machine for Titanium Mobile Windows/HAL/TitaniumKit development.
 *
 * @module setup
 *
 * @copyright
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * @requires node-appc
 */
const async = require('async'),
	fs = require('fs'),
	colors = require('colors'), // eslint-disable-line no-unused-vars
	http = require('http'),
	path = require('path'),
	request = require('request'),
	temp = require('temp'),
	wrench = require('wrench'),
	appc = require('node-appc'),
	HOME = process.env.HOME || process.env.USERPROFILE || process.env.APPDATA,
	spawn = require('child_process').spawn, // eslint-disable-line security/detect-child-process
	os = require('os'),
	SYMBOLS = {
		OK: '✓',
		ERROR: '✖'
	},
	// Constants
	WIN_8_1 = '8.1',
	WIN_10 = '10.0',
	// Default JSC URL to build for Win 8.1.
	JSC_81_URL = 'http://timobile.appcelerator.com.s3.amazonaws.com/jscore/dist/JavaScriptCore-Windows-1472849469.zip',
	// Default JSC URL for building against Win 10
	JSC_10_URL = 'http://timobile.appcelerator.com.s3.amazonaws.com/jscore/dist/JavaScriptCore-Windows-1472849469-win10.zip',
	JSC_DIR = 'JavaScriptCore', // directory inside zipfile
	GTEST_URL = (os.platform() === 'win32') ? 'http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-windows.zip' : 'http://timobile.appcelerator.com.s3.amazonaws.com/gtest-1.7.0-osx.zip',
	GTEST_DIR = (os.platform() === 'win32') ? 'gtest-1.7.0-windows' : 'gtest-1.7.0-osx', // directory inside zipfile
	BOOST_URL = 'http://nchc.dl.sourceforge.net/project/boost/boost/1.60.0/boost_1_60_0.zip',
	BOOST_DIR = 'boost_1_60_0'; // directory inside zipfile

// With node.js on Windows: use symbols available in terminal default fonts
if (os.platform() === 'win32') {
	SYMBOLS.OK = '\u221A';
	SYMBOLS.ERROR = '\u00D7';
}

function downloadURL(url, callback) {
	console.log('Downloading %s', url.cyan);

	const tempName = temp.path({ suffix: '.zip' }),
		tempDir = path.dirname(tempName);
	fs.existsSync(tempDir) || wrench.mkdirSyncRecursive(tempDir);

	const tempStream = fs.createWriteStream(tempName),
		req = request({ url: url });

	req.pipe(tempStream);

	req.on('error', function (err) {
		fs.existsSync(tempName) && fs.unlinkSync(tempName);
		console.log();
		console.error('Failed to download URL: %s', err.toString() + '\n');
		process.exit(1);
	});

	req.on('response', function (req) {
		if (req.statusCode >= 400) {
			// something went wrong, abort
			console.log();
			console.error('Request failed with HTTP status code %s %s\n', req.statusCode, http.STATUS_CODES[req.statusCode] || '');
			process.exit(1);
		} else if (req.headers['content-length']) {
			// we know how big the file is, display the progress bar
			let total = parseInt(req.headers['content-length']),
				bar;

			if (!process.argv.indexOf('--quiet') && !process.argv.indexOf('--no-progress-bars')) {
				bar = new appc.progress('  :paddedPercent [:bar] :etas', {
					complete: '='.cyan,
					incomplete: '.'.grey,
					width: 40,
					total: total
				});
			}

			req.on('data', function (buffer) {
				bar && bar.tick(buffer.length);
			});

			tempStream.on('close', function () {
				if (bar) {
					bar.tick(total);
					console.log('\n');
				}
				callback(tempName);
			});
		} else {
			// we don't know how big the file is, display a spinner
			let busy;

			if (!process.argv.indexOf('--quiet') && !process.argv.indexOf('--no-progress-bars')) {
				busy = new appc.busyindicator();
				busy.start();
			}

			tempStream.on('close', function () {
				busy && busy.stop();
				this.logger.log();
				callback(tempName);
			});
		}
	});
}

function extract(filename, installLocation, keepFiles, callback) {
	console.log('Extracting to %s', installLocation.cyan);

	let bar;

	appc.zip.unzip(filename, installLocation, {
		visitor: function (entry, i, total) {
			if (i === 0) {
				if (!process.argv.indexOf('--quiet') && !process.argv.indexOf('--no-progress-bars')) {
					bar = new appc.progress('  :paddedPercent [:bar]', {
						complete: '='.cyan,
						incomplete: '.'.grey,
						width: 40,
						total: total
					});
				}
			}
			bar && bar.tick();
		}
	}, function (err, extracted, total) {
		if (err) {
			keepFiles || fs.unlinkSync(filename);
			console.log();
			console.error('Failed to unzip');
			String(err).trim().split('\n').forEach(console.error);
			console.log();
			process.exit(1);
		} else {
			if (bar) {
				bar.tick(total);
				console.log('\n');
			}
			keepFiles || fs.unlinkSync(filename);
			callback();
		}
	});
}

function setENV(key, value, next) {
	if (os.platform() === 'win32') {
		// Set the env var "permanently" for user
		const prc = spawn('setx', [ key, value ]);
		// prc.stdout.on('data', function (data) {
		//   console.log(data.toString());
		// });

		prc.on('close', function (code) {
			if (code !== 0) {
				next('Failed to run SETX');
			} else {
				// FIXME Can't seem to run SET to also set for current session!
				console.log((SYMBOLS.OK + ' ' + key + ' set').green);
				next();
			}
		});
	} else {
		// FIXME Batch together all the changes and modify the ~/.bash_profile for the user (after making a copy)?
		console.log('Please set the environment variable %s to %s', key, value);
		console.log('The easiest way to achieve this to to append the following to your ~/.bash_profile:\n\nexport %s=%s\n', key, value);
		next();
	}
}

/**
 * Used to determine if there is an existing install of JSC and it's fromt he same URL as we want.
 */
/**
 * [isUpToDate description]
 * @param  {String}  destination Destination for the file
 * @param  {String}  url         URL to be stashed
 * @return {Boolean}             [description]
 */
function isUpToDate(destination, url) {
	var urlFile = path.join(destination, 'SOURCE_URL'),
		contents = '';
	if (!fs.existsSync(destination) || !fs.existsSync(urlFile)) {
		return false;
	}
	// read contents of urlFile
	contents = fs.readFileSync(urlFile).toString();
	// check if it's the same as url
	return contents === url;
}

function writeSourceURL(destination, url) {
	var urlFile = path.join(destination, 'SOURCE_URL');
	fs.existsSync(destination) || wrench.mkdirSyncRecursive(destination);
	fs.writeFileSync(urlFile, url);
}

/**
 * Common logic for downloading a zip file from an URL for a dependency and setting up the right ENV var to point at the unzipped folder.
 * @param {String} envKey The ENV variable key we should look at or set
 * @param {String} defaultDest The default location to install if no ENV var is set (first time)
 * @param {String} expectedDir Expected enclosing directory isnide the zipfile. Used to rename the extract directory to the expected path in ENV
 * @param {String} url the URL of the zip file to download.
 * @param {Function} next callback function
 **/
function downloadIfNecessary(envKey, defaultDest, expectedDir, url, next) {
	var envValue = process.env[envKey],
		destination = '';

	// retrieve environment variable
	if (typeof envValue !== 'undefined') {
		destination = path.normalize(envValue);
	} else {
		// set environment variable
		destination = defaultDest;
		setENV(envKey, defaultDest, function (err) {
			if (err) {
				return next(err);
			}
		});
	}

	// Does it already exist, and is it up to date?
	if (!isUpToDate(destination, url)) {
		// TODO What if we have local copy already in renamed folder? Look for that first!
		downloadURL(url, function (filename) {
			// What if it _does_ exist and is out of date? We should "wipe it", or move it...
			if (fs.existsSync(destination)) {
				const urlFile = path.join(destination, 'SOURCE_URL');
				if (fs.existsSync(urlFile)) {
					const contents = fs.readFileSync(urlFile);
					const base = path.basename(contents.slice(7), '.zip');
					const byURL = path.normalize(path.join(destination, '..', base));
					console.log('Destination for ' + url + ' already exists, moving existing directory to ' + byURL + ' before extracting.');
					if (!fs.existsSync(byURL)) {
						wrench.copyDirSyncRecursive(destination, byURL);
					}
				}
				wrench.rmdirSyncRecursive(destination);
			}
			// Extract to parent of destination...
			const dest = path.normalize(path.join(destination, '..'));
			extract(filename, dest, true, function () {
				// Need to rename the extracted directory to match our expected destination!
				var extractedDir = path.join(dest, expectedDir);
				wrench.copyDirSyncRecursive(extractedDir, destination);

				writeSourceURL(destination, url);
				next();
			});
		});
	} else {
		// Nothing to do, we're all set
		console.log((SYMBOLS.OK + ' ' + envKey + ' set').green);
		next();
	}
}

/**
 * Downloads Boost headers from BOOST_URL if necessary, and sets BOOST_ROOT env var to it.
 * @param {String} 		[url] 	override source URL to grab Boost from
 * @param {Function} 	next	callback function when finished
 */
function setupBoost(url, next) {
	if (typeof url === 'function') {
		next = url;
		url = BOOST_URL;
	}

	console.log('Setting up Boost libraries...');
	const boostRoot = path.join(HOME, 'boost');
	downloadIfNecessary('BOOST_ROOT', boostRoot, BOOST_DIR, url, next);
}

/**
 * Downloads GTest from GTEST_URL if necessary, and sets GTEST_ROOT env var to it.
 * @param {String} 		[url] 	override source URL to grab GTest from.
 * @param {Function} 	next 	callback function when finished
 */
function setupGTest(url, next) {
	if (typeof url === 'function') {
		next = url;
		url = GTEST_URL;
	}

	console.log('Setting up GTest...');
	const gtestRoot = path.join(HOME, 'gtest');
	downloadIfNecessary('GTEST_ROOT', gtestRoot, GTEST_DIR, url, next);
}

/**
 * Downloads JavaScriptCore from JSC_URL if necessary, and sets JavaScriptCore_HOME env var to it.
 * @param {String}		sdkVersion 	'8.1' || '10'
 * @param {String}		[url] 		override source URL to grab JSC from.
 * @param {Function} 	next 		callback function when finished
 */
function setupJSC(sdkVersion, url, next) {
	if (typeof url === 'function') {
		next = url;
		url = JSC_URL; // TODO find this url or remove
	}

	console.log('Setting up JavaScriptCore pre-built libraries...');
	// Download to directory pegged to sdk version
	const jscHome = path.join(HOME, 'JavaScriptCore-' + sdkVersion);
	// Set env specific to windows sdk version
	downloadIfNecessary('JavaScriptCore_' + sdkVersion + '_HOME', jscHome, JSC_DIR, url, function (e) {
		if (e) {
			return next(e);
		}
		// Then set generic overall env var to the extracted JSC
		setENV('JavaScriptCore_HOME', jscHome, function (err) {
			if (err) {
				return next(err);
			}
		});
	});
}

/**
 * Modifies PATH to include bin folder of included cmake.
 * @param {Function}	next	callback function when finisheds
 **/
function setupCMake(next) {
	console.log('Appending included cmake to PATH...');
	const cmakeBinPath = path.join(__dirname, '..', '..', 'cli', 'vendor', 'cmake', 'bin');
	if (process.env.PATH.indexOf(cmakeBinPath) === -1) {
		console.log('Appending %s to PATH', cmakeBinPath);
		setENV('PATH', process.env.PATH + ';' + cmakeBinPath, next);
	} else {
		// If we can find cmake.exe on PATH, don't append it
		console.log((SYMBOLS.OK + ' Included cmake on PATH').green);
		next();
	}
}

/**
 * @param {Object}		[overrides]			Object containing various URLs to override defaults
 * @param {String}		[overrides.boost] 	Source URL to use for Boost
 * @param {String}		[overrides.gtest] 	Source URL to use for GTest
 * @param {String}		[overrides.jsc] 	Source URL to use for JavaScriptCore
 * @param {Function} 	callback 			callback function when finished
 **/
function setup(overrides, callback) {
	if (typeof overrides === 'function') {
		callback = overrides;
		overrides = {};
	}
	// We could change this to parallel, but we'd have to ditch the progress bars above
	async.series([
		function (next) {
			setupBoost(overrides.boost, next);
		},
		function (next) {
			setupGTest(overrides.gtest, next);
		},
		function (next) {
			if (os.platform() === 'win32') {
				setupJSC(overrides.sdkVersion, overrides.jsc, next);
			} else {
				next();
			}
		},
		// Add the included cmake bin dir to the user's PATH?
		setupCMake
		// TODO Download a VS2013/VS2015 version? (It's Huuuuuuge! Many GB!)
	], callback);
}

// public API
exports.setup = setup;
exports.setupBoost = setupBoost;
exports.setupGTest = setupGTest;
exports.setupJSC = setupJSC;
exports.setupCMake = setupCMake;

// When run as single script.
if (module.id === '.') {
	(function () {
		var program = require('commander');

		program
			.version('0.0.1')
			.option('-j, --javascriptcore [javascriptcore]', 'Override the source URL for JavaScriptCore')
			.option('-g, --gtest [gtest]', 'Override the source URL for GTest', GTEST_URL)
			.option('-b, --boost [boost]', 'Override the source URL for Boost', BOOST_URL)
			.option('-s, --sdk-version [version]', 'Target a specific Windows SDK version [version]', /^(8\.1|10\.0)$/, WIN_8_1)
			.allowUnknownOption()
			.parse(process.argv);

		// If not overriding the JSC URL pick default based on sdk version we're targetting
		if (!program.javascriptcore) {
			if (program.sdkVersion === WIN_10) {
				program.javascriptcore = JSC_10_URL;
			} else {
				program.javascriptcore = JSC_81_URL;
			}
		}

		setup({
			boost: program.boost,
			gtest: program.gtest,
			jsc: program.javascriptcore,
			sdkVersion: program.sdkVersion
		}, function (err) {
			if (err) {
				console.error((SYMBOLS.ERROR + ' ' + err.toString()).red);
				process.exit(1);
			}
			process.exit(0);
		});
	}());
}
