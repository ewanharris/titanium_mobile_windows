'use strict';

const appc = require('node-appc');

/*
 Public API.
 */
exports.mixin = mixin;

/*
 Implementation.
 */
function mixin(WindowsBuilder) {
	WindowsBuilder.prototype.getTargetDevices = getTargetDevices;
	WindowsBuilder.prototype.sanitizeProjectName = sanitizeProjectName;
	WindowsBuilder.prototype.computeHashes = computeHashes;
	WindowsBuilder.prototype.getWindowsSDKTarget  = getWindowsSDKTarget;
	WindowsBuilder.prototype.isWindowsSDKTargetSpecified  = isWindowsSDKTargetSpecified;
}

/**
 * Returns Windows SDK argument
 */

/**
 * Returns the Windows SDK argument
 * @return {String} Windows SDK specified by the user, or selected by the CLI
 */
function getWindowsSDKTarget() {
	return this.cli.argv['win-sdk'] ? this.cli.argv['win-sdk'] : (this.cli.argv['wp-sdk'] ? this.cli.argv['wp-sdk'] : null);
}

/**
 * Returns whether the user has specified a Windows SDK to build with
 * @return {Boolean}
 */
function isWindowsSDKTargetSpecified() {
	return this.cli.argv.$_.indexOf('--wp-sdk') !== -1 || this.cli.argv.$_.indexOf('--win-sdk') !== -1 || this.cli.argv.$_.indexOf('-S') !== -1;
}

/**
 * Returns the available target Windows Phone devices and emulators. It will
 * cache the results so subsequent calls don't have to requery.
 *
 * This function must be called after the CLI has called config() and after
 * the --ws-sdk option has been processed.
 *
 * @returns {Array}
 */
function getTargetDevices() {
	if (this.deviceCache) {
		return this.deviceCache;
	}

	const target = this.cli.argv.target,
		wpsdk  = this.getWindowsSDKTarget(),
		wpsdkDefault = !this.isWindowsSDKTargetSpecified();

	if (target === 'wp-emulator' && this.windowsInfo.emulators) {
		Object.keys(this.windowsInfo.emulators).forEach(function (sdk) {
			if (wpsdkDefault || sdk === wpsdk) {
				if (this.deviceCache) {
					this.deviceCache = this.windowsInfo.emulators[sdk].concat(this.deviceCache);
				} else {
					this.deviceCache = this.windowsInfo.emulators[sdk];
				}
			}
		}, this);
		return this.deviceCache;
	} else if (target === 'wp-device' && Array.isArray(this.windowsInfo.devices)) {
		const devices = this.windowsInfo.devices;
		for (let d in devices) {
			const device = devices[d];
			// only list local devices
			if (device.ip && device.ip !== '127.0.0.1') {
				devices.splice(d, 1);
			}
		}
		return this.deviceCache = devices;
	}

	return [];
}

/**
 * Removes characters from the project name that aren't supported.
 * @param 	{String} str 	The project name to sanitize
 * @returns {string}
 */
function sanitizeProjectName(str) {
	return str
		.replace(/[^a-zA-Z0-9_]/g, '_')
		.replace(/_+/g, '_')
		.split(/[\W_]/)
		.map(function (s) { return appc.string.capitalize(s); })
		.join('');
}

/**
 * Generate hashes of modules and properties from the tiapp.xml so we can detect
 * changes and force a rebuild.
 *
 * @param {Function} next - A function to call when once the hashes have been computed
 */
function computeHashes(next) {
	// modules
	this.modulesHash = !Array.isArray(this.tiapp.modules) ? '' : this.hash(this.tiapp.modules.filter(function (m) {
		return !m.platform || /^windows|commonjs$/.test(m.platform);
	}).map(function (m) {
		return m.id + ',' + m.platform + ',' + m.version;
	}).join('|'));

	// properties
	this.propertiesHash = this.hash(this.tiapp.properties ? JSON.stringify(this.tiapp.properties) : '');

	next();
}
