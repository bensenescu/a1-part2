a.out:
	clang++ TestArray.cpp -std=c++11 -ggdb3 -pedantic -Weverything -Wno-weak-vtables -Wno-missing-prototypes -Wno-98-compat

lldb:
	lldb ./a.out

test: a.out
	./a.out	

valgr:
	valgrind --leak-check-full --show-task-kinds=all --track-origins=yes -v ./a.out

clean:
	rm a.out
