VPATH=lib

release: main.c
	gcc -I"$(VPATH)" -O3 -o Physio.exe -municode $(VPATH)/main.c

run: release
	./Physio.exe

debug: main.c
	gcc -I"$(VPATH)" -g -o PhysioDebug.exe -municode $(VPATH)/main.c
