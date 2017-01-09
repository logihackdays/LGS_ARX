# LGS_ARX
The Logitech|G Arx Control Software Development Kit enables applications such as games to interact with the Arx Control app on mobile devices.

Arx Control allows games and third party developers to take advantage of an iOS/Android device as a secondary screen to display useful data from the game.

# SDK Package
The following files are included:

● LogitechGArxControlLib.h: C/C++ header file containing function prototypes

● LogitechGArxControlLib.lib: companion lib file to access DLL exported functions (32 and 64 bit)

# Requirements
The Logitech|G Arx Control SDK can be used on the following platforms:

● Windows Vista (32-bit and 64-bit)

● Windows 7 (32-bit and 64-bit)

● Windows 8 (32-bit and 64-bit)


Logitech Gaming Software (8.52 or higher) needs to be running in order to use this SDK.

The SDK is a Windows based API for C/C++ programmers. The applet layout is based on web programming, so a basic knowledge of HTML/JavaScript/CSS is also needed.

# Do’s and Don’ts
These are a few guidelines that may help you implement 'better' support in your game:

**DO’s**

● Create a callback function and use it to be notified on applet focus change, device orientation change and user clicks on any object in your applet.<br />
● The applet will be displayed on Arx Control only after the first valid call to LogiArxSetIndex. Send all your data first, and then set the index page to display correctly the app.

**DON’TS**

● Data is sent over Wi-Fi. Don’t send oversized images or files. Try to optimize the format of any file that will be part of the applet.
