default: functions.o
	gcc functions.o kruskal.c -o kruskal

functions.o: functions.h
	gcc -c functions.c
	
clean:
	rm *.o
