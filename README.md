*This project has been created as part of the 42 curriculum by pedrohe3.*

# Description
**Push_swap** is a sorting project where the challenge is to sort data on a stack, with a limited set of instructions, using the lowest number of actions. The objective is to learn about sorting algorithms and complexity, to be able to evaluate and select an optmized solutio to complete this task.

# Instructions
The project is managed via a **Makefile** and requires the **libft** library to be present in the root directory.

To compile the project, run the following command in the terminal:
`make`

This will generate the `push_swap` executable. To execute the program, provide a list of integers as arguments (1) or a string as single argument containing the list of integers (2):
1. `./push_swap 2 1 3 6 5 8`
2. `./push_swap "2 1 3 6 5 8"`

The program will then output the smallest list of operations typed to sort the stack.

# Resources
- AI was used to help understanding better a few sorting algorithms.
- [**Turk Algorithm**](https://medium.com/@ayogun/push-swap-c1f5d2d41e97 "Push Swap — A journey to find most efficient sorting algorithm"): The core logic used as base to calculate the most efficient moves between stacks.

# Data Structure


# Algorithm
The algorithm used was a version of the Turk Algorithm. Originaly the algorithm can be divided in a few steps:
1. Push 2 numbers without any verification to stack B.
2. For every number in the stack A, calculate the cost to put it at the top of stack A.
3. For every number in the stack A, find which number from B that it should be put before in order to always keep B circularly sorted with biggest on top and smallest at the bottom. This number will be its target (If the number is smaller than every number from B, it goes on top of the biggest number from B).
4. Find the number in A that has the least sum between its cost and its target's cost.
5. And until the stack A is empty, put them both at the top of each stack, and finally push from A to B.
7. Once stack A is empty, find the biggest value and rotate until it gets on top.
6. Pushes everything back from B to A in order to have the biggest at the bottom and the smallest on top.

In this project, a very quick and shallow study on the Turk Algorithm was made with the objective to get a grasp of the concept, without giving away how to proceed exactly to achieve the objective. Which led to some original (and unfortunately less efficient) implementation. The steps taken were quite similar to the original version, but instead of pushing at the reverse order to B, it was pushed almost the whole stack A to B, and only when bringing it back to A that the order was taken into account, keeping the smallest on top and biggest at the bottom.
1. Push numbers to stack B without any verification until 3 are remaining in A.
2. Sort the 3 elements in A with biggest at the bottom and smaller on top.
3. For every number in the stack B, calculate the cost to put it at the top of stack B.
4. For every number in the stack B, find which number from A that it should be put before in order to always keep B circularly sorted with smallest on top and biggest at the bottom. This number will be its target (If the number is bigger than every number from A, it goes on top of the biggest number from A).
5. Find the number in B that has the least sum between its cost and its target's cost.
6. And until the stack B is empty, put them both at the top of each stack, and finally push from B to A.
7. Once stack B is empty, find the smallest value and rotate until it gets on top.
 
This project has been created as part of the 42 curriculum by pedrohe3

# Description
Get_new_line is a project with the objective of teaching about static variables through the implementation of a program that given a file descriptor it will return only one line from it, being possible to execute the function more than once to retrieve the consecutive lines.

# Instructions
This project only contains 2 programs and one header.

In order to be able to call the get_next_line function the header must be included in file where the main function will be located.

Secondly, to compile correctly it is needed to have all of the files at the same directory as the file containing the main, compile all the .c files get_next_line.c get_next_line_utils.c, as the example bellow, and finally execute the program.
Example: cc <main_file.c> get_next_line.c get_next_line_utils.c

# Resources
- www.opengroup.org
- AI was used to help understanding how to attack and search for potential reasons for the leaks. It was also used to make the code cleaner, direct and shorter, helping to refactor the code to reduce the amount of lines and remove redundant code.

# Algorithm
- The decision to use static variables was based in the indication made by the project guidelines. It allowed to keep track of the buffer used even in between different calls of the get_next_line function, and was a key aspect for the completion of the project.
- The use of while loops was chosen to guarantee that new reads were made everytime the end of the buffer was reached and the end of line was not reached yet, it was also used to iterate through the buffer while looking for the end of the buffer ('\0') or for the end of line ('\n') markers.
