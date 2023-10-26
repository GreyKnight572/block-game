================
QUICKSTART GUIDE
================

	1. Install Git
	2. Clone https://github.com/GreyKnight572/block-game.git
	3. Don't forget to pull the latest updates before building
	4. Install MSYS2 from https://www.msys2.org/
	5. Open MSYS2 MINGW64 and run the following commands:

		$ pacman --noconfirm -Syu
		$ pacman --noconfirm -S mingw-w64-x86_64-gcc make

	6. Open Windows Start and search "path"
	7. Open "Edit the system environment variables"
	8. Click on "Environment Variables" at the bottom of the window
	9. Double-click on "Path" in the top half of the window
	10. Use the "New" button to add “C:\msys64\mingw64\bin” & “C:\msys64\usr\bin”
	11. Click "OK" to save the changes
	12. Open Command Prompt and use "cd C:\[path]" to navigate to the "block-game" folder
	13. Use the command "make run" to build and start the game
