# Push Swap Project
╱|、 <br />
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; (˚ˎ 。7  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |、˜〵          
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; じしˍ,)ノ

<br /> <br />

## Table of Contents

- [Introduction](#introduction)
- [Project Description](#project-description)
- [Sorting Algorithms](#sorting-algorithms)
- [Installation](#installation)

<br /> <br />

## Introduction

Welcome to the Push Swap project! This project involves sorting data on a stack using a limited set of instructions, with the goal of achieving the smallest number of moves. 
<br /> <br />
The main objective is to manipulate various sorting algorithms and select the most appropriate solution(s) for optimized data sorting.

This README file provides an overview of the project, installation instructions, details about the sorting algorithms used, and guidelines for usage.

<br /> <br />

## Project Description

The Push Swap project focuses on sorting data using two stacks, named Stack A and Stack B. 
<br /> <br />
Initially, Stack A contains a random list of integers, and Stack B is empty. The task is to sort the integers in Stack A in ascending order using a predefined set of instructions.

The challenge lies in finding an optimal sequence of instructions that will efficiently sort the integers with the least number of moves.

<br /> <br />

### The Rules
-  You have 2 **stacks** named a and b.
  
-  At the beginning:
  1.  The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  2.  The stack b is empty.

-  The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
  1. **sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. <br /> <br />
  2. **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. <br /> <br />
  3. **ss** : sa and sb at the same time. <br /> <br />
  4. **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. <br /> <br />
  5. **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. <br /> <br />
  6. **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one. <br /> <br />
  7. **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. <br /> <br />
  8. **rr** : ra and rb at the same time <br /> <br />
  9. **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one. <br /> <br />
  10. **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one. <br /> <br />
  11. **rrr** : rra and rrb at the same time. 

<br /> <br />

## Data Structure
As the mandatory of Push Swap project, I use **stack** then, implement its structure with **Linked List**.

  1.  **Stack**
      A linear data structure that accompanies a principle known as FILO (First In Last Out).
      FILO implies that the element that is inserted first, comes out last.

      https://cdn.buttercms.com/PuR6MmOQQdqAP6xfh6JO

  2.  **Doubly Linked List**
     A doubly linked list (DLL) is a special type of linked list in which each node contains a pointer to the previous node as well as the next node of the linked list.

      https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png

My node structure is maintained as follow,

```
typedef struct s_CLnode
{
	int		value;
	int		index;
	int		price;
	struct s_CLnode	*target_node;
	struct s_CLnode	*prev;
	struct s_CLnode	*next;
}	t_CLnode;
```
A node structure has been implemented for organizing data of: 

1.  **value** : Value of number this node contains. <br /> <br />
2.  **index** : The order number this node in the stack. (the first element has index of 1) <br /> <br />
3.  **price** : How many moves to go to the top of stack. <br /> <br />
4.  **target node** :
    In every nodes node of stack A, target node data will contains the address of the smaller node in stack B, but it must be the closest smallest one. Using this method, the bigger node will be ordered on top of the smaller node in stack B.
    <br /> <br />
  In every nodes node of stack B, target node data will contains the address of the biiger node in stack A, but it must be the closest bigger one. Using this method, the smaller node will be ordered on top of the bigger node in stack A.
<br /> <br />
6.  **prev** : pointer (address) to the next node. (prev of the first node will point to NULL) <br /> <br />
7.  **next** : pointer (address) to the previos node. (next of the last node will pint to NULL) <br /> <br />

```
typedef struct s_circularList
{
	int		size;
	t_CLnode	*top;
	t_CLnode	*find_last_node;
	t_CLnode	*lowest_price_node;
	t_CLnode	*the_smallest_node;
	t_CLnode	*the_cheapest_node;
}	t_circularList;
```
A stack structure has been implemented for organizing data of: 

1.  **size** : How many number of nodes in the stack. <br /> <br />
2.  **top** : pointer (address) to the toppest node in the stack. <br /> <br />
3.  **find_last_node** : pointer (address) to the bottom node in the stack. <br /> <br />
4.  **the_smallest_node** : a pointer (address) to the stack's smallest node. (To lessen a possible increase in complexity in the final_arrangement function) <br /> <br />
5.  **the_cheapest_node** : a pointer (address) to the stack's cheapest node. (Comparing each node to determine which one moves the least.)

<br /> <br />

## Sorting Algorithms

After handling user input error (empty string, string with space, duplicate number, input with many argument, input that is bigger than INT_MAX, input smaller than INT_MIN, etc), then push every element in stack A. 
<br /> <br />
I will classify the method to solve by the number of elements in stack A.

```
if (!stack_sorted(&a))  // if the stack has not been sorted.
{
  if (a.size == 2)      // if size == 2, then swap the 2 elements.
    sa(&a);              
  else if (a.size == 3) // 🅐 if size == 3
    tiny_sort_3(&a);
  else if (a.size == 5) // 🅑 if size == 5
    tiny_sort_5(&a, &b);
  else                  //  🅒 if size > 3
    push_swap(&a, &b);
}
```
<br /> <br />

🅐  To solve the problem which size == 3, my project implements the following sorting algorithms:
```
void	tiny_sort_3(t_circularList *a)
{
	int	biggest;

	biggest = find_biggest(a);
	if (a->top->value == biggest)
		ra(a);
	else if (a->top->next->value == biggest)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}
```
I'll make sure that the largest node is at the bottom, then verify that the first two nodes are in the correct order before swapping. The maximum number of moves that can be made using this approach is 2.

<br /> <br />

🅑  To solve the problem which size == 5, my project implements the following sorting algorithms:

```
void	tiny_sort_5(t_circularList *a, t_circularList *b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		find_smallest_node(a);
		pass_to_b(a, b);
	}
	tiny_sort_3(a);
	pa(a, b);
	pa(a, b);
}
```
I'll pick the smallest node in stack A and push to stack B. I'll do this process for 2 times so, the smallest will be at the bottom of stack B. Then, I'll do tiny_sort_3 to stack A. Then push back 2 element in stack B in order.

<br /> <br />

 🅒  To solve the problem which size > 3, my project implements the following sorting algorithms:
 
### Turk Sort: 
This modified version is inspired by the [Turk Sort article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ayooluwa Ogundahunsi.

This algorithm has the reference from **Mechanical Turk** which is hard coded and but efficiet.
The main algoritm is implemented as follow :

<br />

```
void	push_swap(t_circularList *a, t_circularList *b)
{
	// ❶ : Push 2 nodes into stack B.
	pb(a, b);
	pb(a, b);

        // ❷ : Push nodes into stack B based on its cost until stack size == 3.
	while (a->size > 3)
	{
		set_target_node_a(a, b);
		set_price(a, b);
		move_into_b(a, b);
	}
	// ❸ : Sort last three elements
	tiny_sort_3(a);
	

	// ❹  : Push all nodes back to stack A
	set_target_node_b(a, b);
	move_into_a(a, b);
	

	//! sprint5 : final arrangement
	final_arrangement(a);
}
```
<br /> 

❶ Push 2 nodes into stack B

<br />

❷  Push nodes into stack B based on its cost until stack size == 3.

&nbsp;First, I'll set the target node for every node in stack A. The condition is the target node must be smaller than node a and it must be the clostest smallest one. <br /> <br />
&nbsp;Second, calculate the price (how many moves both node A and target node to get the the toppest node). Compare all node in stack A then, keep the address of the chaepest node in a->the_cheapest_node <br /> <br />
&nbsp;Third, do the rotation to make node_a and its target_node_b to be at the top. If the node index <= median, then do ra(a). If not, then do rra(a). <br /> <br />
&nbsp;Forth, do pb(a, b) (move node_a to stack B)

<br />

❸ Sort last three elements 

<br />

❹ Push all nodes back to stack A
	
   This time I'll set the target node for every node in stack B. The condition is the target_node_a must be bigger than node_b and it must be the clostest bigger one. <br />
 
   Second, do the rotation to make node_b and its target_node_a to be at the top. If the node index <= median, then do rb(b). If not, then do rrb(b). <br />
  
   Third, do pa(a, b) (move node_b to stack A)

<br /> <br />

## Installation

To use the Push Swap project, follow these steps:

1. Clone the repository to your local machine:

```
   git clone https://github.com/paphachanok/push_swap.git
```

2. To complie all files in the directory

```
   make
```

3. To Run the program

```
   ./push_swap [ numbers you'd like to sort]
```

