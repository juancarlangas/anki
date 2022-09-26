anki: main.o mazo.o
	gcc build/main.o build/mazo.o -o bin/anki

main.o: src/main.c src/mazo.h
	gcc -c src/main.c -o build/main.o

mazo.o: src/mazo.c src/mazo.h
	gcc -c src/mazo.c -o build/mazo.o

clean:
	rm build/main.o build/mazo.o
