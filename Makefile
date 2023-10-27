VPATH=lib

game: main.c
	gcc -I"$(VPATH)" -g -o Physio.exe -municode $(VPATH)/main.c

run: game
	./Physio.exe
