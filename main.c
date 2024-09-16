#include <stdio.h>
#include <stdbool.h>
#define SUDOKU_ROW 9 
#define SUDOKU_COL 9 
#include "funcs.c"

//bool CheckSubGrid(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val);
//bool CheckRowCol(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val);
//bool isValidCell(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val);
//bool SudokuSolve(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind);


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


//finds which subgrid a cell belongs to and checks that subgrid for duplicates
/*bool CheckSubGrid(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val) {

    int row_start = (row_ind / 3) * 3;              //formula for subgrid row bounds is flr(r/3)*3 for start and flr(r/3)*3+3 for end
    int col_start = (col_ind / 3) * 3;              //same formula; as with row bounds flr(c/3)*3 for start and flr(c/3)*3+3 for end


    for (int i = row_start; i < row_start + 3; i++) {         
        for (int j = col_start; j < col_start + 3; j++) {     

            if (i == row_ind && j == col_ind)   //skips the index position of the cell being evaluated since it's just zero each time it is being checked
                continue;

            if (isValidCell(Grid, i, j)) {

                if (Grid[i][j] == val) {
                    printf("\nDuplicate number found!\n");
                    
                    return true;
                }
            }

        }
    }

    return false;

}*/

//checks the row and column relative to the cell being checked for duplicates
/*bool CheckRowCol(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val) {

    //same formula with CheckSubGrid()
    int row_start = (row_ind / 3) * 3;
    int col_start = (col_ind / 3) * 3;

    for (int i = row_ind - row_start; i < 9; i++) {       // row_index - (row_index / 3)*3 is the formula used to find the starting position of row checking

        if (i == row_ind)       //skips evaluated cell index
            continue;

        if (Grid[i][col_ind] == val) {
            printf("\nDuplicate found!\n");
            return true;
        }
    }

    for (int i = col_ind - col_start; i < 9; i++) {       //same formula as above, just that it's col now

        if (i == col_ind)       //skips evaluated cell index
                continue;

        if (Grid[row_ind][i] == val) {
            printf("\nDuplicate found!\n");
            return true;
        }
    }

    return false;
}*/

//checks if an index position is vacant '0' or not, and if the cell is within the grid
/*bool isValidCell(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val) {

    int i, j;
    int row_start = (row_ind / 3) * 3;
    int col_start = (col_ind / 3) * 3;

    //not in row
    for (i = row_start; i < 9; i++) {

        if (i == row_ind)
            continue;

        if (Grid[i][col_ind] == val)
            return false;
    }

    //not in col
    for (i = col_start; i < 9; i++) {

        if (i == col_ind)
            continue;
        
        if (Grid[row_ind][i] == val)
            return false;

    }

    //not in subgrid
    for (i = row_start; i < row_start + 3; i++) {
        for (j = col_start; j < col_start + 3; j++) {

            if (i == row_ind && j == col_ind)
                continue;
            
            if (Grid[i][j] == val)
                return false;

        }
    }

    return true;

}

bool SudokuSolve(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind) {

    if (row_ind == 9) {

        return true;

    } else if (col_ind == 9) {

        return SudokuSolve(Grid, row_ind + 1, 0);

    } else if (Grid[row_ind][col_ind] != 0) {

        return SudokuSolve(Grid, row_ind, col_ind + 1);

    } else {

        for (int i = 1; i <= 9; i++) {

            if (isValidCell(Grid, row_ind, col_ind, i)) {

                Grid[row_ind][col_ind] = i;

                if (SudokuSolve(Grid, row_ind, col_ind + 1))
                    return true;
                
                Grid[row_ind][col_ind] = 0;

            }
        }

        return false;
    }
}*/