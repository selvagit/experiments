
all:
	gcc -g -Wall -o test.a ./test.c -ljansson

run:
	./test.a | tee run.log

valgrind:
	#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --log-file=./valgrind.log  ./test.a

clean:
	rm ./test.a
