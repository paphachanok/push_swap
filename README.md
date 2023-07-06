# Push Swap Project

## Table of Contents

- [Introduction](#introduction)
- [Project Description](#project-description)
- [Sorting Algorithms](#sorting-algorithms)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Welcome to the Push Swap project! This project involves sorting data on a stack using a limited set of instructions, with the goal of achieving the smallest number of moves. The main objective is to manipulate various sorting algorithms and select the most appropriate solution(s) for optimized data sorting.

This README file provides an overview of the project, installation instructions, details about the sorting algorithms used, and guidelines for usage.

## Project Description

The Push Swap project focuses on sorting data using two stacks, named Stack A and Stack B. Initially, Stack A contains a random list of integers, and Stack B is empty. The task is to sort the integers in Stack A in ascending order using a predefined set of instructions.

The challenge lies in finding an optimal sequence of instructions that will efficiently sort the integers with the least number of moves.

### The Rules
-  You have 2 **stacks** named a and b.
  
-  At the beginning:
  1.  The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  2.  The stack b is empty.

-  The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
  1. **sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  2. **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  3. **ss** : sa and sb at the same time.
  4. **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  5. **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  6. **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  7. **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  8. **rr** : ra and rb at the same time
  9. **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  10. **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  11. **rrr** : rra and rrb at the same time.

## Sorting Algorithms

To solve the Push Swap problem, my project implements the following sorting algorithms:

1. **Turk Sort**: This modified version is inspired by the [Turk Sort article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ayooluwa Ogundahunsi.

    This algorithm has the reference from **Mechanical Turk** which is hard coded and but efficiet.


## Installation

To use the Push Swap project, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/paphachanok/push_swap.git
  ```


