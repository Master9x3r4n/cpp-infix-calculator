# Infix Calculator in C++
## Features
- Converts a string of infix computations into postfix expression
- Evaluations postfix expressions and returns a result
- Can support `+ - * / % ^ == != < > <= >= && || && !` operations
- Accepts **positive** operands
## Limitations
- Limited to the cpp input buffer
  - **NO SPACES OR OTHER SPECIAL CHARACTERS**
  - Can only accept a string input of operands (numbers) and valid operators
  - Example invalid: `(1 + 2) >= A`
  - Example valid: `(1+2)>=3`
- Can only perform operations with valid syntax
  - Invalid expressions, such as incomplete expression or missing symbols, will not work
  - Cannot accept negative numbers as an operand
    - Example: `-3!=9+7` will not work but `0-3!=9+7` will
## How To Use
- Clone the repository in the terminal using `git clone https://github.com/Master9x3r4n/cpp-infix-calculator.git`
- Open the directory
- Compile the project in the terminal using `gcc main.cpp -o main.exe`
- Run the project with `main`
## Usage 
- The files in the current version of the project have a single dependency in `main.cpp`
- If you want to utilize the code for your own project, compile the other `.cpp` modules and follow the implementation in `main.cpp`
- I got too lazy to fix the dependency issue
