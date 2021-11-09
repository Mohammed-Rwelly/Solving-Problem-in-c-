# Sudoku

Sudoku is a puzzle game in the form of a grid. The goal of the game is to fill this grid with a series of all different numbers that are never found more than once on the same line, in the same column or in the same block.
In a classic Sudoku of size 9, these blocks will therefore have sizes of 3 by 3 and the values that can be assigned to the cells will range from 1 to 9.

Reading the Sudoku rules clearly shows that this game is actually a problem of satisfying constraints. A simple first approach for solving Sudoku problem is to apply a recursive [Backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm, only this approach is not so efficient especially for larger non-standard grids of Sudoku.

In 2000, Donald Knuth, a famous U.S. computer professor, published an article entitled [Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links) in which he described the use of the Algorithm X to solve Sudoku grids. This article focuses first on the problem of exact coverage and the Algorithm X to solve it quickly and efficiently.In a second step, Donald Knuth shows how to transform the problem of solving a Sudoku grid into an instance of the problem of [exact coverage](https://en.wikipedia.org/wiki/Exact_cover#Sudoku). Once this modeling is done, it is easy to apply the Algorithm X and solve very complex Sudoku grids. All this with excellent performance.

# The Challenge

In this challenge we are seeking a proof of concept on the superiority of using the more "clever" Algorithm X to solve a Sudoku puzzle when compared to the naive Backtracking algorithm, our focus is on the execution time of both algorithms.

##  Your Quest

- There are plenty of resources on the internet for both proposed algorithms, do your research and have a complete understanding of them before you start.
- Carefully review the provided code skeleton in the file `sudoku.cpp`.
- Complete the code in the file mentioned above.

## Non-functional requirements

- The code must use comments wisely. Communicate why something behaves the way it does rather than what. It should be clear what the code does from reading it.



