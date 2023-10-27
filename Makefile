VPATH=lib

game: main.c
	gcc -I"$(VPATH)" -g -o game.exe -municode $(VPATH)/main.c

run: game
	./game.exe
