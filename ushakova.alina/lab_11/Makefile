all: lab_11

obj:
	mkdir obj;

lab_11: obj/main.o obj/employees.o obj/bin_manip.o
	g++ -std=c++11 -Wall -Wextra -Werror obj/main.o obj/employees.o obj/bin_manip.o -o lab_11

obj/main.o: src/main.cpp include/employees.h | obj
	g++ -std=c++11 -Wall -Wextra -Werror -c -Iinclude src/main.cpp -o obj/main.o

obj/employees.o: src/employees.cpp include/employees.h include/bin_manip.h | obj
	g++ -std=c++11 -Wall -Wextra -Werror -c -Iinclude src/employees.cpp -o obj/employees.o

obj/bin_manip.o: src/bin_manip.cpp  include/bin_manip.h | obj
	g++ -std=c++11 -Wall -Wextra -Werror -c -Iinclude src/bin_manip.cpp -o obj/bin_manip.o

clean:
	rm -f lab_11
	rm -Rf obj/
