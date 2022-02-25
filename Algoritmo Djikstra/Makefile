default: functions.o
	gcc functions.o dijkstra.c -o dijkstra

functions.o: functions.h
	gcc -c functions.c
	
clean:
	rm *.o