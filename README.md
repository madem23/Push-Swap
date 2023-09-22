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

### Program Constraints:
Two stacks: A and B.
Initial state: All numbers in stack A, stack B empty.

### Possible actions:

* ```pa``` : Push top of B to A (if B not empty).
* ```pb``` : Push top of A to B (if A not empty).
* ```sa``` : Swap top 2 elements in A (if >= 2 elements).
* ```sb``` : Swap top 2 elements in B (if >= 2 elements).
* ```ss``` : ```sa``` and ```sb``` simultaneously.
* ```ra``` : Rotate A (move top element to the bottom).
* ```rb``` : Rotate B (move top element to the bottom).
* ```rr``` : ```ra``` and ```rb```  simultaneously.
* ```rra``` : Reverse rotate A (move bottom element to the top).
* ```rrb``` : Reverse rotate B (move bottom element to the top).
* ```rrr``` : ```rra``` and ```rrb``` simultaneously.

### Grading:

* Sorting 3 values: ≤ 3 actions.
* Sorting 5 values: ≤ 12 actions
* Sorting 100 values:
  * 5 points for ≤ 700 actions
  * 4 points for ≤ 900 actions
  * 3 points for ≤ 1100 actions
  * 2 points for ≤ 1300 actions
  * 1 point for ≤ 1500 actions
* Sorting 500 values:
  * 5 points for ≤ 5500 actions
  * 4 points for ≤ 7000 actions
  * 3 points for ≤ 8500 actions
  * 2 points for ≤ 10000 actions
  * 1 point for ≤ 11500 actions
  
### Validation Requirement: 
Minimum 80/100.
