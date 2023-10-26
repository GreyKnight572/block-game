game: main.c
	gcc -o game.exe -municode main.c

run: game
	./game.exe
