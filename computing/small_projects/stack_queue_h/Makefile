
INPFILE=stack.c

OUTPUT=./stack.a

all:
	@echo "--Building apps--"
	@gcc -g -Wall -o $(OUTPUT) $(INPFILE)
	@ls -l ./

run:
	@echo "--Running apps--"
	@$(OUTPUT) | tee $(OUTPUT)_run.log

valgrind:
	@echo "--Running apps in valgrind--"
	@valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --log-file=./valgrind.log $(OUTPUT)

clean:
	@echo "--Cleaning the workspace--"
	@rm $(OUTPUT) ./*.log
