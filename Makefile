game.exe: main.c
	gcc -o game.exe -municode main.c

run: game.exe
	./game.exe
