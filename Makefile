build: 
	gcc -Wall -o tema_1  tema_1.c 
run: 
	./tema_1
clean:
	rm -rf tema_1
test-valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --leak-check=yes ./tema_1