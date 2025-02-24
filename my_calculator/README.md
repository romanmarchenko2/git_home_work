Simple calculator project using GNU Autotools.

## Installation Instructions
1. Generate configuration files to prepare source code for compilation
   ```
   autoreconf
   ```
   Notes: 
   autoreconf executes autoconf, automake, libtools in the correct sequence to create files like configure and Makefile.in

2. Configure the project:
   ```
   ./configure
   ```
   Notes: This command runs a script that prepares source code for building on specific system.

3. Build the project:
   ```
   make
   ```
   Notes: The make command builds the software

4. Install the program (requires root privileges):
   ```
   sudo make install
   ```

## Cleaning Instructions
1. Clean build files:
   ```
   make clean
   ```

2. Clean all generated files (including autotools files):
   ```
   make clean-all
   ```

## Project Structure
- main.c: Main program file
- my_calc.h: Header file with function declarations
- add.c: Implementation of addition function
- multiply.c: Implementation of multiplication function
- configure.ac: Autoconf configuration file
- Makefile.am: Automake configuration file

## Screenshot Of Program Execution
![alt text](result.png)