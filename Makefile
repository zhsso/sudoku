all:
	gcc sudoku.c -std=c99 -o sudoku
clean:
	rm -rf sudoku
