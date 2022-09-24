anki: anki.o
	gcc anki.o -o anki

anki.o: anki.c
	gcc -c anki.c -o anki.o

clean:
	rm anki.o
