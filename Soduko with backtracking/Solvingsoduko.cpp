#include <iostream>
#include <string>
#include <chrono>
#include <stdexcept>
#include <memory>
using namespace std;

namespace
{
  const size_t N = 9; // standard Sudoku board is of size 9 x 9
}



class Sudoku
{
  public:
    Sudoku(string fromString)
    {
      // Assuming a string of 81 digits in rang[0, 9] where 0 is an empty cell, generated by reading the grid row-by-row,
      // this method should initialize the Sudoku board, otherwise a proper exception should be raised!
      // Please complete the code in here
      string letter="";
      for (int i =0;i < 9;i++){
        for (int j=0; j < 9;j++){
          letter=fromString[i*9+j];
          board[i][j]= stoi(letter);

    }}}
    void print()
    {
      for (int i =0;i < N;i++){
        for (int j=0; j < N;j++){
          cout<<board[i][j]<<" ";}
          cout<<endl;
      }
    }

    // The following method is a convenient way to access the cells of the Sudoku 9 x 9 grid
    int &operator()(size_t row, size_t col)
    {
      if(row >= 9 || col >=9)
      {
        throw out_of_range("Board subscript out of bounds");
      }
      return board[row][col];
    }

    private:
      int board[N][N];

};
// This is an abstract Sudoku solver class.
// Please don't touch this class!
class SudokuSolver
{
  public:

    // The purpose of the following methos is to solve the givin Sudoku and measure the time needed for that(in ms)
    double solveAndMeasureTime(Sudoku &sudoku)
    {
      auto start = chrono::steady_clock::now();
      solve(sudoku);
      auto end = chrono::steady_clock::now();
      return chrono::duration <double, milli> (end - start).count();
    }

  protected:
    virtual void solve(Sudoku &sudoku) = 0;
};



// Backtracking Sudoku solver class
// Feel free to modify the class as you wish as long as you make sure to override the solve method!
class BacktrackingSudokuSolver : public SudokuSolver
{

    bool isSafe(Sudoku &sudoku,int row,int col, int num){
        return !UsedInRow(sudoku,row, num)
        && !UsedInCol(sudoku,col, num)
        && !UsedInBox(sudoku,row - row % 3,col - col % 3, num)
        && sudoku(row,col) == 0;
    }


    bool UsedInBox(Sudoku &sudoku,int boxStartRow, int boxStartCol, int num){
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (sudoku(row + boxStartRow , col + boxStartCol) == num )
                    return true;
        return false;
    }


    bool UsedInCol(Sudoku &sudoku,int col, int num){
        for (int row = 0; row < N; row++)
            if (sudoku(row,col) == num)
                return true;
        return false;
    }

    bool UsedInRow(Sudoku &sudoku,int row, int num){
        for (int col = 0; col < N; col++)
            if (sudoku(row,col) == num)
                return true;
        return false;
    }


    bool FindUnassignedLocation(Sudoku &sudoku,int& row, int& col){
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (sudoku(row,col) == 0)
                    return true;
        return false;
    }

    bool SolveSudoku(Sudoku &sudoku){
        int row, col;

        if (!FindUnassignedLocation(sudoku,row, col))
            return true;

        for (int num = 1; num <= 9; num++) {

            if (isSafe(sudoku,row, col, num)) {

                sudoku(row,col) = num;

                if (SolveSudoku(sudoku))
                    return true;

                sudoku(row,col)  = 0;
            }
        }

        return false;
    }


  protected:
    // Inherited via SudokuSolver
    virtual void solve(Sudoku &sudoku) override {
        if (SolveSudoku (sudoku))
            return;
        else
            throw new std::exception;
    }
};



// Dancing Links Sudoku solver class
// Feel free to modify the class as you wish as long as you make sure to override the solve method!
class DancingLinksSudokuSolver : public SudokuSolver
{
    /*private: // Dancing Links toroidal structures
    class header;
    class node{
    public:
      int row;
      node * up, * down, * left, * right;
      header * head;
    };
    class header : public node{
    public:
      int size;
      bool visible;
      header * left, * right;
    };
    int u, u2, u3, rowsNumber, columnsNumber, solutionsNumber, maxSolutionsNumber;
    header * root;
    vector<header> columns;
    vector<vector<node> > rows;
    vector<int> solutions;*/

    protected:
    // Inherited via SudokuSolver
    virtual void solve(Sudoku &sudoku) override
    {
      // Please complete the code in here
    }
};



// Solve a sudoku and log the solution along with time needed
// Please don't touch this method
void solveAndLog(Sudoku sudoku, SudokuSolver *solver)
{
  auto time = solver->solveAndMeasureTime(sudoku);
  sudoku.print();
  cout << "Solved in " << time << " ms" << endl;
}



int main()
{
  // A diver code
  try
  {
    auto sudokuString = "010008000304721690006000010000902530042103780035806000090000100021387409000500020";
    Sudoku sudoku(sudokuString);
    cout << "Unsolved Sudoku:" << endl;
    sudoku.print();
    auto backTrackingSolver = make_unique<BacktrackingSudokuSolver>();
    //auto dancingLinksSolver = make_unique<DancingLinksSudokuSolver>();
    cout<< "Solving with Backtracking" << endl;
    solveAndLog(sudoku, backTrackingSolver.get());
    //cout << "Solving with Dancing Links" << endl;
    //solveAndLog(sudoku, dancingLinksSolver.get());
  }
  catch (std::exception& e)
  {
    cout << "An error occurred: " << e.what() << endl;
    return -2;
  }
  catch (...)
  {
    cout << "Unknown error!" << endl;
    return -1;
  }

  return 0;
}
