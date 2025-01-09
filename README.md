# PushSwap

PushSwap is a project for the 42 school that challenges students to sort a list of numbers in as few operations as possible. The program utilizes two stacks (`a` and `b`) and a set of predefined operations to achieve the sorting.

## Table of Contents

1. [About the Project](#about-the-project)
2. [Features](#features)
3. [How It Works](#how-it-works)
4. [Getting Started](#getting-started)
5. [Usage](#usage)
6. [Testing](#testing)

---

## About the Project

The primary goal of PushSwap is to develop a sorting program that efficiently sorts a given list of integers using only stack-based operations. The project implements the **Mechanical Turk algorithm** to optimize the sorting process.

This project emphasizes:

- Algorithmic efficiency.
- Understanding and implementing stack-based operations.
- Code optimization and cleanliness.

---

## Features

- Implements the Mechanical Turk algorithm for sorting.
- Predefined operations include:
  - `sa`, `sb`, `ss` (swap top two elements of a stack).
  - `pa`, `pb` (push the top element of one stack to another).
  - `ra`, `rb`, `rr` (rotate a stack upward).
  - `rra`, `rrb`, `rrr` (rotate a stack downward).
- Efficient handling of input validation and edge cases.

---

## How It Works

PushSwap operates with two stacks:

1. **Stack `a`**: Initially holds the list of numbers to be sorted.
2. **Stack `b`**: An auxiliary stack used during the sorting process.

The sorting process involves:

1. Parsing and validating the input list.
2. Applying a series of optimized operations to sort the numbers.
3. Printing the list of operations required for sorting.

---

## Getting Started

### Prerequisites

- A Unix-based operating system.
- GCC or another C compiler.
- Make utility.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/push_swap.git
   cd push_swap
   ```

2. Compile the program:
   ```bash
   make
   ```

---

## Usage

To run the program:

```bash
./push_swap <list_of_numbers>
```

Example:

```bash
./push_swap 4 2 7 1 3
```

The output will be a list of operations required to sort the numbers.

---

## Testing

You can test the program with automated tools or custom scripts to measure the number of operations and validate the sorting.

Example testing script:

```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker $ARG
```

---