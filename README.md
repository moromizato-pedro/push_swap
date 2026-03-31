*This project has been created as part of the 42 curriculum by pedrohe3.*

# Description
**Push_swap** is a sorting project where the challenge is to sort a list of unique integers on a stack with a limited set of instructions, using the lowest possible number of actions. The objective is to understand sorting algorithms and time complexity, allowing for the evaluation and selection of an optimized solution to complete the task.

# Instructions
The project is managed via a **Makefile** and requires the **libft** library to be present in the root directory.

To compile the project, run the following command in the terminal:
```bash
make
```
This will generate the push_swap executable. To execute the program, provide a list of integers as individual arguments (1) or as a single string containing the list of integers (2):

1. `./push_swap 2 1 3 6 5 8`
2. `./push_swap "2 1 3 6 5 8"`

The program will then output the smallest sequence of operations required to sort the stack.

<img width="231" height="78" alt="image" src="https://github.com/user-attachments/assets/5723d9f7-c1f3-4a34-9375-42700eba68db" />



# Resources
- AI was used to help understanding better a few sorting algorithms, and also improving readability and objectivity in this README.
- [**Turk Algorithm**](https://medium.com/@ayogun/push-swap-c1f5d2d41e97 "Push Swap — A journey to find most efficient sorting algorithm"): The core logic used as base to calculate the most efficient moves between stacks.

# Data Structure
A linked list-based stack was selected as the primary data structure. To facilitate the sorting logic, specific attributes were added to each node, such as individual indexes and a target position in stack 'A' (utilized specifically by nodes in stack 'B').

While the list itself is not structurally circular, it can be rotated as if it were to accommodate the subject's required operations. We maintain structural control by identifying its start via the list's base address and its end via a NULL pointer.

![Stack](https://github.com/user-attachments/assets/a584fa55-494e-46f4-8da5-f00e958a6d42)

# Algorithm
The algorithm implemented is a customized variation of the Turk Algorithm.

While the traditional Turk Algorithm focuses on pushing elements to stack B in a sorted, descending manner from the very beginning, this implementation takes an approach based on a shallow overview of the original concept in order to attempt achieving the objective without having a step-by-step guide, which led to some less efficient implementation. 

Rather than sorting during the initial push, almost the entire stack A is pushed to B sequentially. The calculated sorting and ordering logic is instead applied when bringing the elements back to stack A, ensuring the smallest elements end up on top and the largest at the bottom.

The execution steps for this custom implementation are as follows:
1. Push numbers from stack A to stack B without any sorting verification until exactly 3 elements remain in A.
2. Sort the remaining 3 elements in stack A (largest at the bottom, smallest on top).
3. For every number in stack B, calculate the operation cost required to move it to the top of stack B.
4. For every number in stack B, identify its "target" in stack A. The target is the number it must be placed before to keep stack A circularly sorted. (Note: If the number from B is larger than every number in A, its target becomes the top of the largest number in A).
5. Evaluate all numbers in stack B to find the one with the lowest combined operation cost (its own cost to reach the top of B + its target's cost to reach the top of A).
6. Until stack B is empty, rotate both stacks to position the chosen number and its target at the top of their respective stacks, then push the number from B to A.
7. Once stack B is completely empty, locate the smallest value in stack A and rotate the stack until this minimum value sits at the top.
