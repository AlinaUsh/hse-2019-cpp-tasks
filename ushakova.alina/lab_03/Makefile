all: lab3

lab3: obj/main.o obj/clist.o 
	gcc -o lab3 obj/main.o obj/clist.o 

obj:
	mkdir obj

clean:
	rm lab3 -Rf obj

obj/clist.o: src/clist.c | obj
	gcc -o obj/clist.o -c -Iinclude src/clist.c -Wall -Wextra -Werror

obj/main.o: src/main.c | obj
	gcc -o obj/main.o -c -Iinclude src/main.c -Wall -Wextra -Werror




