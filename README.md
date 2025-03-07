# SudokuGen: Sudoku Generator and Solver

**SudokuGen** is a C-based program that can **generate** and **solve** Sudoku puzzles at the highest difficulty level. It uses an optimized **backtracking algorithm** combined with logical deduction to efficiently generate unique, challenging puzzles and solve any valid Sudoku configuration.

## 📌 Features
✔️ **Solves any Sudoku** using an optimized recursive algorithm.  
✔️ **Generates hard Sudokus** that require advanced solving techniques.  
✔️ **Interactive mode** for playing, solving, and saving Sudoku puzzles.  
✔️ **Efficient memory management** using linked lists for backtracking.  

---

## 🧩 How the Sudoku Solver Works

The solver is based on a **hybrid approach** combining logical deduction and backtracking:

1. **Elementary Search**:  
   - Fills in cells that have only **one possible candidate**.
   
2. **Intermediate Search**:  
   - Identifies numbers that must be placed in a row, column, or block.
   - This process repeats until no more numbers can be inserted.

3. **Advanced Search (Backtracking)**:  
   - Finds the **cell with the fewest candidates**, inserts a possible number, and attempts to solve the puzzle.  
   - If a contradiction occurs, it **backtracks** and tries the next candidate.

### 🔧 Key Data Structures

Each Sudoku **cell** is a **struct** containing:  
- `value`: The current number in the cell.  
- `candidates`: A **9-bit vector** indicating possible numbers.  
- `neighbors`: Pointers to adjacent cells (row, column, and block).  

For backtracking, a **stack-based structure (`branch`)** stores:  
- A **9x9 matrix snapshot** of the Sudoku state.  
- A pointer to the **decision cell** that started the branch.  
- `i, j`: Coordinates of the modified cell.  
- `k`: Index tracking the next candidate to try.  

---

## 📌 Functions Overview  

The project consists of several key functions responsible for **solving**, **generating**, and **interacting** with Sudoku puzzles. Below is a breakdown of their roles and execution order.  

---

### 🧩 **Sudoku Solver Functions**  

#### 🔹 `solve_sudoku(int grid[9][9])`  
**Purpose:**  
- Main function that solves a given Sudoku puzzle.  

**Process:**  
1. Calls `solve()` to fill obvious numbers using logic.  
2. If the grid is not complete, finds the cell with the **fewest candidates**.  
3. Creates a **backtracking branch**, tries inserting a candidate, and recursively calls itself.  
4. If a contradiction occurs, it **backtracks** and tries the next candidate.  

---

#### 🔹 `solve(int grid[9][9])`  
**Purpose:**  
- Applies **elementary** and **intermediate** solving techniques before backtracking.  

**Process:**  
1. Loops through all cells to find those with only **one possible number**.  
2. If no easy placements remain, calls `find_num()` to determine which numbers can be placed.  
3. Uses `taglia_num()` to update cell state and remove candidates in affected rows, columns, and quadrants.  

---

#### 🔹 `find_num(int grid[9][9], int row, int col)`  
**Purpose:**  
- Finds a **valid number** for a specific cell.  

**Process:**  
- Checks if a number is **the only candidate** in its **row, column, or quadrant**.  
- Returns the valid number if found, or `0` if there are multiple possibilities.  

---

#### 🔹 `taglia_num(int grid[9][9], int row, int col, int num)`  
**Purpose:**  
- Removes **invalid candidates** from the **row, column, and quadrant** of the given cell.  

**Process:**  
1. Updates the **bit-vector** of affected cells.  
2. Calls `taglia_r()`, `taglia_c()`, and `taglia_q()` to update candidates.  
3. Uses `find_q(row, col)` to determine the quadrant index.  

---

#### 🔹 `undo()`  
**Purpose:**  
- Restores the **previous Sudoku state** when backtracking.  

**Process:**  
1. Retrieves the last **valid grid state** from the **branch stack**.  
2. Removes the incorrect candidate.  
3. Continues solving from the last decision point.  

---

### 🎲 **Sudoku Generator Functions**  

#### 🔹 `randGrigliaSudoku(int grid[9][9])`  
**Purpose:**  
- Generates a **random, fully solved** Sudoku grid.  

**Process:**  
1. Fills **diagonal 3x3 blocks** with random numbers.  
2. Calls `solve_sudoku()` to complete the grid.  

---

#### 🔹 `generate_sudoku(int grid[9][9])`  
**Purpose:**  
- Creates a **difficult** Sudoku puzzle by removing numbers **strategically**.  

**Process:**  
1. Randomly removes a number and checks if the puzzle still has a **unique solution**.  
2. If multiple solutions exist, the number is restored.  
3. Repeats until a **valid Sudoku** remains.  

---

### 🖥 **User Interaction Functions**  

#### 🔹 `start()`  
**Purpose:**  
- Initializes the program and prompts the user to select a mode:  
  - **Play a Sudoku** (manually solve a puzzle).  
  - **Solve a Sudoku** (input a custom puzzle and get the solution).  
  - **Generate a Sudoku** (create a new challenge).  

---

#### 🔹 `play_sudoku()`  
**Purpose:**  
- Allows the user to **manually solve** a generated Sudoku.  
- Accepts keyboard input for inserting numbers or requesting hints.  

---

#### 🔹 `play_solve()`  
**Purpose:**  
- Lets the user **input a Sudoku puzzle** and instantly solve it.  

---

#### 🔹 `fprint_sudoku(FILE *file, int grid[9][9])`  
**Purpose:**  
- Saves the **current Sudoku grid** to a text file.  

**Process:**  
- Appends the **player's name** and the **timestamp** to ensure unique filenames.  

---

## 🔄 **Function Execution Flow**
```mermaid
graph TD
    A[start] --> B{Choose Mode}
    B -- "Play Sudoku" --> C[play_sudoku]
    B -- "Solve Sudoku" --> D[play_solve]
    B -- "Generate Sudoku" --> E[generate_sudoku]
    
    D --> F[solve_sudoku]
    F --> G[solve]
    G --> H{Is Sudoku solved?}
    H -- No --> I[find_num]
    I --> J[taglia_num]
    J --> G
    H -- Yes --> K[Solved!]

    E --> L[randGrigliaSudoku]
    L --> M[generate_sudoku]

```

The solve_sudoku() function calls solve(), which iterates through all Sudoku cells, attempting to fill them using find_num(). If no numbers can be placed, the algorithm creates a new branch, selects a candidate, and tries solving recursively.

---

# 🎲 How the Sudoku Generator Works
The generator follows these steps:

Create a fully solved 9x9 Sudoku grid

Uses randGrigliaSudoku() to fill diagonal blocks with random numbers.
Solves the grid using the Sudoku solver.
Remove numbers one by one while ensuring a unique solution

Randomly removes a number and attempts to solve the Sudoku.
If multiple solutions exist, the number is restored.
If the puzzle is still solvable, the number is permanently removed.
This method guarantees a unique, difficult Sudoku every time.



