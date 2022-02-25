default: functions.o
	gcc functions.o prim.c -o prim

functions.o: functions.h
	gcc -c functions.c
	
clean:
	rm *.o