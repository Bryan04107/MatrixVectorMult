all: mylib.o 
	gcc -o main.exe mylib.o main.c

mylib.o: mylib/mylib.c
	gcc -o mylib.o -c mylib/mylib.c

test:
	gcc -o mylib.o -c mylib/mylib.c
	gcc -o main.exe main.c mylib.o
	./main.exe

time: 
	gcc -o mylib.o -c mylib/mylib.c  
	gcc -o main_b_time.exe main_b_time.c mylib.o 
	./main_b_time.exe;

space:
	gcc -o mylib.o -c mylib/mylib.c   
	gcc -o main_b_space.exe main_b_space.c mylib.o
	./main_b_space.exe;
	
clear: 
	rm -rf *.exe
	rm -rf *.o