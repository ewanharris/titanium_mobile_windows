#!groovy​
// Keep history of up to 30 builds, but only keep artifacts for the last 5
properties([buildDiscarder(logRotator(numToKeepStr: '30', artifactNumToKeepStr: '5'))])

def gitCommit = ''
def testTimeout = 25

def build(sdkVersion, msBuildVersion, architecture, gitCommit) {
	unstash 'sources' // for build
	if (fileExists('dist/windows')) {
		bat 'rmdir dist\\windows /Q /S'
	}
	bat 'mkdir dist\\windows'

	dir('Tools/Scripts') {
		bat 'npm install .'
		echo "Installing JSC built for Windows ${sdkVersion}"
		bat "node setup.js -s ${sdkVersion} --no-color --no-progress-bars"
		bat 'rmdir node_modules /Q /S'
	}

	dir('Tools/Scripts/build') {
		bat 'npm install .'

		timeout(45) {
			echo "Building for ${architecture} ${sdkVersion}"
			def raw = bat(returnStdout: true, script: "echo %JavaScriptCore_${sdkVersion}_HOME%").trim()
			def jscHome = raw.split('\n')[-1]
			echo "Setting JavaScriptCore_HOME to ${jscHome}"
			withEnv(["JavaScriptCore_HOME=${jscHome}"]) {
				bat "node build.js -s ${sdkVersion} -m ${msBuildVersion} -o ${architecture} --sha ${gitCommit}"
			}
		} // timeout
	} // dir Tool/Scripts/build
	archiveArtifacts artifacts: 'dist/**/*'
} // def build

def unitTests(target, branch, testSuiteBranch) {
	def defaultEmulatorID = '10-0-1'
	// unarchive mapping: ['dist/' : '.']
	// dir('Tools/Scripts/build') {
	// 	echo 'Setting up SDK'
	// 	bat 'npm install .'
	// 	bat "node setupSDK.js --branch ${branch}"
	// }

	// if our test suite already exists, delete it
	bat 'if exist titanium-mobile-mocha-suite rmdir titanium-mobile-mocha-suite /Q /S'
	// clone the tests suite fresh
	// FIXME Clone once on initial node and use stash/unstash to ensure all OSes use exact same checkout revision
	dir('titanium-mobile-mocha-suite') {
		// TODO Do a shallow clone, using same credentials as from scm object
		git changelog: false, poll: false, credentialsId: 'd05dad3c-d7f9-4c65-9cb6-19fef98fc440', url: 'https://github.com/appcelerator/titanium-mobile-mocha-suite.git', branch: testSuiteBranch
	}

	dir('titanium-mobile-mocha-suite/scripts') {
		bat 'npm install .'
		echo "${target}"
		try {
			if ('ws-local'.equals(target)){
				echo "Running tests on ws-local"
				// bat "node test.js -p windows -T ${target} --skip-sdk-install --cleanup"
				bat "node test.js -p windows -T ${target}"
			} else if ('wp-emulator'.equals(target)) {
				echo "Running tests on wp-emulator"
				// FIXME Need to see if the emulators are set up paired/dev mode/checkpoint and all have same id
				// There could be 10.0.10240/10586/14393/15063 emulators on the boxes!
				// Seems like "10.0.14393.0 WVGA 4 inch 512MB" is good on WinGin-03, which is 10-0-1. Has only 10.0.14393 emulators for Windows 10
				// Seems like "10.0.10586.0 WVGA 4 inch 512MB" is good on WinGin04, which is 10-0-1. Has both 10.0.10586 and 10.0.14393 emulators for Windows 10
				// Seems like "10.0.14393.0 WVGA 4 inch 512MB" is good on WinGin-02, which is 10-0-1. Has only 10.0.14393 emulators for Windows 10
				// Seems like "10.0.14393.0 WVGA 4 inch 512MB" and maybe "10.0.14393.0 WXGA 4.5 inch 512MB" is good on WinGin10, WVGA is 10-0-1. Has only 10.0.14393 emulators for Windows 10
				// bat "node test.js -p windows -T ${target} -C ${defaultEmulatorID} --skip-sdk-install --cleanup"
				bat "node test.js -p windows -T ${target} -C ${defaultEmulatorID}"
			}
		} catch (e) {
			echo "${e}"
			throw e
		} finally {
			if ('ws-local'.equals(target)){
				bat 'taskkill /IM mocha.exe /F 2> nul'
			} else if ('wp-emulator'.equals(target)) {
				bat 'taskkill /IM xde.exe /F 2> nul'
			}
		}
		junit 'junit.*.xml'
	} // dir 'titanium-mobile-mocha-suite/scripts
} // def unitTests

// wrap in timestamps
timestamps {
	node('npm && node') {
		stage('Checkout') {
			// checkout scm
			// Hack for JENKINS-37658 - see https://support.cloudbees.com/hc/en-us/articles/226122247-How-to-Customize-Checkout-for-Pipeline-Multibranch
			checkout([
				$class: 'GitSCM',
				branches: scm.branches,
				extensions: scm.extensions + [
					[$class: 'CleanBeforeCheckout'],
					[$class: 'SubmoduleOption', disableSubmodules: false, parentCredentials: true, recursiveSubmodules: true, reference: '', trackingSubmodules: false],
					[$class: 'CloneOption', depth: 30, honorRefspec: true, noTags: true, reference: '', shallow: true]
				],
				userRemoteConfigs: scm.userRemoteConfigs
			])
			// FIXME: Workaround for missing env.GIT_COMMIT: http://stackoverflow.com/questions/36304208/jenkins-workflow-checkout-accessing-branch-name-and-git-commit
			gitCommit = sh(returnStdout: true, script: 'git rev-parse HEAD').trim()
			// Stash our source code/scripts so we don't need to checkout again?
			stash name: 'sources', includes: '**', excludes: 'apidoc/**,test/**,Examples/**'
		} // Checkout stage
		//
		// stage('Docs') {
		// 	if (isUnix()) {
		// 		sh 'mkdir -p dist/windows/doc'
		// 	} else {
		// 		bat 'mkdir dist\\\\windows\\\\doc'
		// 	}
		// 	echo 'Generating docs'
		// 	dir('apidoc') {
		// 		if (isUnix()) {
		// 			sh 'npm install .'
		// 			sh 'node ti_win_yaml.js'
		// 		} else {
		// 			bat 'call npm install .'
		// 			bat 'call node ti_win_yaml.js'
		// 		}
		// 	}
		// 	echo 'copying generated docs to dist folder'
		// 	if (isUnix()) {
		// 		sh 'mv apidoc/Titanium dist/windows/doc/Titanium'
		// 	} else {
		// 		bat '(robocopy apidoc\\\\Titanium dist\\\\windows\\\\doc\\\\Titanium /e) ^& IF %ERRORLEVEL% LEQ 3 cmd /c exit 0'
		// 	}
		// 	archiveArtifacts artifacts: 'dist/**/*'
		// } // stage('Docs')
	} // node

	// Are we on a PR/feature branch, or a "mainline" branch like master/6_2_X/7_0_X?
	def isMainlineBranch = (env.BRANCH_NAME ==~ /master|\d_\d_X/)
	def targetBranch = env.CHANGE_TARGET // if it's a PR, use target merge branch as branch of SDK to install
	if (isMainlineBranch) { // if it's a mainline branch, use the same branch for titanium_mobile
		targetBranch = env.BRANCH_NAME
	}
	if (!targetBranch) { // if all else fails, use master as SDK branch to test with
		targetBranch = 'master'
	}
	// Trigger titanium_mobile if we're on a mainline branch
	def triggerDownstream = isMainlineBranch

	// stage('Build') {
	// 	parallel(
	// 		'Windows 10 x86': {
	// 			node('msbuild-14 && vs2015 && hyper-v && windows-sdk-10 && npm && node && cmake && jsc') {
	// 				build('10.0', '14.0', 'WindowsStore-x86', gitCommit)
	// 			}
	// 		},
	// 		'Windows 10 ARM': {
	// 			node('msbuild-14 && vs2015 && hyper-v && windows-sdk-10 && npm && node && cmake && jsc') {
	// 				build('10.0', '14.0', 'WindowsStore-ARM', gitCommit)
	// 			}
	// 		},
	// 		failFast: true
	// 	)
	// } // Stage build

	stage('Test') {
		parallel(
			'ws-local': {
				// FIXME This is specifically tied to Win-Gin10 for stability
				node('msbuild-14 && vs2015 && hyper-v && windows-sdk-10 && npm && node && cmake && jsc && Win-Gin10') {
					unitTests('ws-local', targetBranch, 'windows')
				}
			},
			'wp-emulator': {
				node('msbuild-14 && vs2015 && hyper-v && windows-sdk-10 && npm && node && cmake && jsc') {
					unitTests('wp-emulator', targetBranch, 'windows')
				}
			}
		)
	} // stage Test

	// If not a PR, trigger titanium_mobile to build
	if (triggerDownstream) {
		// Trigger build of titanium_mobile in our pipeline multibranch group!
		build job: "../titanium_mobile/${env.BRANCH_NAME}", wait: false
	}
}
