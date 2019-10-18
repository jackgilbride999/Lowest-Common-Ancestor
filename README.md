# Lowest Common Ancestor problem for CSU33012 Software Engineering

## Description of problem
The task was to provide a program solution to the Lowest Common Ancestor (LCA) Problem. The goal was to implement this solution using good software engineering practises: using efficient practises, utilizing various tools to increase efficiency, good source control practice and unit testing as a means of checking whether the code fulfilled its use case.  
The first part of the task involved running the LCA solution on a binary tree. The second part of the task was to build on this and provide an implementation that would work on a Directed Acyclic Graph (DAG).

## Implementation and file structure
I decided to use C as the language to develop my solution in. As a result the repository takes a standard format for software engineering in C: 
- A build sudirectory, where all the build files are stored 
- A src subdirectory, containing the source and header file of the solution
- A test subdirectory, containing the source and header files of the unit tests
- A unity subdirectory, containing the Unity unit testing framework for C. This is a framework written in ANSI standard C.
- A Makefile, for ease of use in compiling and running tests

## How to Use
- Clone the project into a Linux repository on your machine
- In a bash terminal, ensure that you are in the project directory and enter 'make'
- The test, source and test framework files will all be linked and built into an executable. This executable will then be run and you will see the outcomes of all tests in your terminal window
