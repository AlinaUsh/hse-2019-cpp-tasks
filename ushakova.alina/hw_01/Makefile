all: hw_01

hw_01: obj/main.o obj/bmp.o 
	gcc -g -o hw_01 obj/main.o obj/bmp.o 

obj:
	mkdir obj

clean:
	rm hw_01 -Rf obj

obj/bmp.o: src/bmp.c include/bmp.h | obj
	gcc -g -o obj/bmp.o -c -Iinclude src/bmp.c -Wall -Wextra -Werror

obj/main.o: src/main.c include/bmp.h | obj
	gcc -g -o obj/main.o -c -Iinclude src/main.c -Wall -Wextra -Werror
