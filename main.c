#include <stdio.h>
#include "funcs.c"

int main()
{
    FILE *op;

    op = fopen("grid.txt", "rt");

    if (op == NULL) {
        printf("\nInput file does not exist.\n\n");
        return 1;
    }

    int sudokuGrid[SUDOKU_ROW][SUDOKU_COL];

    for (int i = 0; i < SUDOKU_ROW; i++) {
        for (int j = 0; j < SUDOKU_COL; j++) {
            fscanf(op, "%d", &sudokuGrid[i][j]);
        }
    }

    if (SudokuSolve(sudokuGrid, 0, 0)) {

        //test print of grid

    printf("\n\n");

    for (int i = 0; i < SUDOKU_ROW; i++) {
        for (int j = 0; j < SUDOKU_COL; j++) {
            printf("%d ", sudokuGrid[i][j]);

            if (j == 2 || j == 5)
                printf("| ");
        }
        printf("\n");

        if (i == 2 || i == 5)
            printf("----------------------\n");
    }

    printf("\n\n");

    }
    else {
        printf("\nSolution does not exist.\n");
    }

    

    fclose(op);

    return 0;
}