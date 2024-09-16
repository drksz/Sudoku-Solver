#include <stdio.h>
#include <stdbool.h>
#define SUDOKU_ROW 9 
#define SUDOKU_COL 9 

bool CheckSubGrid(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val);
bool CheckRowCol(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val);
bool isValidCell(int Grid[SUDOKU_ROW][SUDOKU_COL], int x, int y);
bool SudokuSolve(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind);

//finds which subgrid a cell belongs to and checks that subgrid for duplicates
bool CheckSubGrid(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val) {
    int row_start = (row_ind / 3) * 3;
    int col_start = (col_ind / 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (Grid[i][j] == val && !(isValidCell(Grid, i, j))) {
                printf("Sub-grid duplicate found!\n");
                return true;
            }
        }
    }

    return false;
}


//checks the row and column relative to the cell being checked for duplicates
bool CheckRowCol(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind, int val) {

    //same formula with CheckSubGrid()
    //int row_start = (row_ind / 3) * 3;
    //int col_start = (col_ind / 3) * 3;

    for (int i = 0; i < 9; i++) {       // row_index - (row_index / 3)*3 is the formula used to find the starting position of row checking

        if (i == row_ind)       //skips evaluated cell index
            continue;

        if (Grid[i][col_ind] == val) {
            printf("\nDuplicate found!\n");
            return true;
        }
    }

    for (int i = 0; i < 9; i++) {       //same formula as above, just that it's col now

        if (i == col_ind)       //skips evaluated cell index
                continue;

        if (Grid[row_ind][i] == val) {
            printf("\nDuplicate found!\n");
            return true;
        }
    }

    return false;

}


bool isValidCell(int Grid[SUDOKU_ROW][SUDOKU_COL], int x, int y) {
    if ( (Grid[x][y] == 0) && (x >= 0 && y >= 0) && (x < SUDOKU_ROW && y < SUDOKU_COL) )    //checks if an index position is vacant '0' or not, and if the cell is within the grid
        return true;

    return false;
}

bool SudokuSolve(int Grid[SUDOKU_ROW][SUDOKU_COL], int row_ind, int col_ind) {

    
    if (row_ind == SUDOKU_ROW)     //row index of 9 means we've filled all sudoku cells; return true

        return true;

    if (col_ind == SUDOKU_COL)               //col index of 9 means we've run off of valid column cells. call SudokuSolve again 
                                            //but add 1 to row_ind and set col_ind to 0 so that it may traverse to the next rows of cells
        return SudokuSolve(Grid, row_ind + 1, 0);
   

    if (!(isValidCell(Grid, row_ind, col_ind)))    //if the cell is not vacant (not zero), skip by calling the function again and adding 1 to  col_ind

        return SudokuSolve(Grid, row_ind, col_ind + 1);


        //executes if none of the above is violated
    for (int i = 1; i <= 9; i++) { //for-loop which tries all nums 1 to 9 for each cell
        if (!(CheckSubGrid(Grid, row_ind, col_ind, i)) && !(CheckRowCol(Grid, row_ind, col_ind, i))) {  //checks if the number 'i' is not within the subgrid
                                                                                                        //or row and col of that cell

            Grid[row_ind][col_ind] = i; //if above condition is not violated, set the value at that cell equal to 'i'

                //BACKTRACKING STARTS HERE

            if (SudokuSolve(Grid, row_ind, col_ind + 1) )   //recursively call SudokuSolve() to check next cell
                return true;    //if it returns true, sudoku puzzle is solved

                //if it returns false, it means nums 1 to 9 did not work for the next cell. It will return here and set the value at the cell
                //back to zero again and try the remaining nums
            Grid[row_ind][col_ind] = 0;
                
                //for example: 3 was assigned to starting cell before recursive call. If that recursive call on next cell returns false, return here
                  //and set that 3 back to zero, try next num, which is 4, and recursively call the function again.
                
            }
        }

        return false;         //makes function return false if all nums 1 to 9 are not valid for that cell

}