# Assignment 3 – CO3: Constructors, Destructors and Operator Overloading

## Student Details

- **Name:** [Enter your name]
- **Register Number:** [Enter your register number]
- **Course:** C++
- **Assignment:** Assignment 3 – CO3
- **Compiler:** g++ [Enter your version, e.g., 13]
- **C++ Standard:** C++17

## About This Assignment

This repository contains my individual solutions for Assignment 3 (CO3). The programs demonstrate the use of constructors, destructors, copy construction, dynamic memory allocation, and operator overloading in C++.

The assignment contains seven tasks:

1. **Q1 – Constructors and Constructor Overloading:** Default, parameterised and overloaded constructors, member initializer lists, constructor delegation and validation.
2. **Q2 – Copy Constructors: Shallow and Deep Copies:** Deep copy constructor, copy assignment operator, destructor and independent copies of dynamically allocated data.
3. **Q3 – Dynamic Constructors and Destructors:** Dynamic allocation for an auditorium seat map, seat booking/cancellation and memory release.
4. **Q4 – Overloading Arithmetic and Stream Operators:** A `Money` class with arithmetic, comparison and stream operators.
5. **Q5 – Overloading Increment, Comparison and Subscript Operators:** Prefix/postfix increment, comparisons and checked playlist indexing.
6. **Q6 – The Rules of Operator Overloading:** A dynamically allocated `Text` class with copying, assignment, concatenation, comparison and printing.
7. **Q7 – Design a Complex-Number Class:** A `Complex` class for arithmetic operations and AC circuit impedance calculations.

## Repository Structure

Keep each question in its own folder. Add the source code, any required input file and the output screenshot for that task.

```text
DSA01-<RegisterNumber>-Assignment3/
│
├── README.md
├── Q1/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
├── Q2/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
├── Q3/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
├── Q4/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
├── Q5/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
├── Q6/
│   ├── main.cpp
│   ├── input.txt
│   └── output.png
└── Q7/
    ├── main.cpp
    ├── input.txt
    └── output.png
```

> Use the actual filenames in your repository. If a program does not require an input file, you can omit `input.txt`.

## Compiler and Compilation

**Compiler:** GNU C++ (`g++`)  
**Version:** [Enter the installed version]

Check the compiler version:

```bash
g++ --version
```

Compile a program using C++17 with warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o program
```

Run the compiled program:

```bash
./program
```

On Windows, run:

```bash
program.exe
```

If a task contains multiple source files, include all required `.cpp` files in the compilation command.

## How to Compile and Run Each Task

Open a terminal in the required question folder and run:

```bash
cd Q1
g++ -std=c++17 -Wall -Wextra main.cpp -o program
./program
```

Repeat the same steps for `Q2` through `Q7`, changing the folder name.

For memory-related tasks, use AddressSanitizer where supported:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g main.cpp -o program
./program
```

For optimisation timing experiments, compile separate builds:

```bash
g++ -std=c++17 -O0 main.cpp -o program_O0
g++ -std=c++17 -O2 main.cpp -o program_O2
```

## Task Results

Fill in the result after compiling and executing each program. Do not write a result until you have tested the program.

| Task | Result |
|---|---|
| Q1 | [Record whether all constructors work and invalid copy counts are rejected.] |
| Q2 | [Record whether copies are independent and whether AddressSanitizer reports any errors.] |
| Q3 | [Record whether seat booking/cancellation works and allocated memory is released.] |
| Q4 | [Record the arithmetic, comparison and formatted money output.] |
| Q5 | [Record prefix/postfix results, comparisons and playlist range-check behaviour.] |
| Q6 | [Record text copying, assignment, concatenation and comparison results.] |
| Q7 | [Record series/parallel impedance results and the zero-division test.] |

## Testing and Evidence

For every task, include:

- The completed C++ source file(s).
- Input file(s), if the program uses input files.
- A screenshot showing the program's actual output.
- Required output predictions and explanations for the prediction questions.
- Memory diagrams, sanitizer results and timing measurements wherever required by the assignment.
- A short explanation of the result and any issues found during testing.

For sanitizer tests, include the relevant terminal output. For timing tests, mention the compiler options used (`-O0` or `-O2`) and the measured time.

## Git Commit History

Commit the work progressively. Make at least one meaningful commit for each task instead of uploading everything in a single commit at the end.

Example commands:

```bash
git add Q1
git commit -m "Complete Q1 constructors"

git add Q2
git commit -m "Complete Q2 deep copy and assignment"

git add Q3
git commit -m "Complete Q3 dynamic memory and destructor"

git add Q4
git commit -m "Complete Q4 money operator overloading"

git add Q5
git commit -m "Complete Q5 increment and subscript operators"

git add Q6
git commit -m "Complete Q6 text class and operator rules"

git add Q7
git commit -m "Complete Q7 complex number class"

git add README.md
git commit -m "Add assignment 3 README"
```

## Conclusion

This assignment provides practical experience in managing object creation and destruction, handling dynamically allocated memory, implementing safe copying, and overloading operators in C++. Each task is compiled, executed and tested, with the required evidence maintained in its respective folder.

---

**GitHub Repository Link:** [Paste your repository URL here]
