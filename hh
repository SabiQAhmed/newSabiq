May 20, 2025 8:16:41 AM org.openqa.selenium.devtools.CdpVersionFinder findNearestMatch
WARNING: Unable to find CDP implementation matching 136
May 20, 2025 8:16:41 AM org.openqa.selenium.chromium.ChromiumDriver lambda$new$5
WARNING: Unable to find version of CDP to use for 136.0.7103.114. You may need to include a dependency on a specific version of the CDP using something similar to `org.seleniumhq.selenium:selenium-devtools-v86:4.26.0` where the version ("v86") matches the version of the chromium-based browser you're using and the version number of the artifact is the same as Selenium's.
--------------------------------------------------------------------
Navigate to the URL ERROR: You are using a no-op implementation of the CDP. The most likely reason for this is that Selenium was unable to find an implementation of the CDP protocol that matches your browser. Please be sure to include an implementation on the classpath, possibly by adding a new (maven) dependency of `org.seleniumhq.selenium:selenium-devtools-vNN:4.26.0` where `NN` matches the major version of the browser you're using.
Build info: version: '4.26.0', revision: '8ccf0219d7'
System info: os.name: 'Windows 11', os.arch: 'amd64', os.version: '10.0', java.version: '17.0.7'
Driver info: DevTools Connection
--------------------------------------------------------------------
-------------------------------------------------
-------------------------------------------------
 driver opened !!
