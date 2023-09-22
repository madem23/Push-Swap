# push_swap
<a href="https://pytorch.org/" target="_blank"> <img align="left" src="https://skillicons.dev/icons?i=c," alt="pytorch" height="42px"/> </a> 
push_swap is a 42 school algorithm project.
Objective: sorting a given a list of random numbers with a limited set of instructions, using the lowest possible number of actions and only 2 stacks.

The program displays on the standard output the smallest program of instructions, that sorts the integers received as arguments.

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <numbers>
```
The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap -787 879877 -9 68745
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```
To visualize this push_swap algorithm (with set size from 1 to 500):
```shell
python3 pyviz.py `ruby -e "puts (0..<size of set to sort>).to_a.shuffle.join(' ')"`
```
<div style="display: flex; justify-content: center;">
  <img src="assets/push_swap_visualizer.gif" alt="PS Visualizer" height="350"/>
</div>

## Push_Swap Rules and Grading

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

The grade depends on how efficient the program's sorting process is.
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

Validating the project requires at least 80/100.
