*This project has been created as part of the 42 curriculum by gkordas and misasant.*

# push_swap

## Description

This project was developed as a **group project** by **gkordas** and **misasant**.

Both contributors:

- participated in the initial design (data structures, file layout, strategy choices),
- reviewed and discussed each other’s code,
- tested and debugged the program on various input sizes and patterns,
- prepared for the peer-evaluation by ensuring they can both explain all parts of the code.

#### misasant

- Implemented core data structures and stack management:
  - `t_node`, `t_stack`, creation and initialization functions,
  - `node_new`, `init_stack`, `stack_add_back`, `free_stack`, etc.
- Implemented argument parsing and validation:
  - `ft_atol`,
  - `is_valid_number`,
  - splitting arguments with `ft_split`,
  - detection of invalid formats and `INT_MIN`/`INT_MAX` overflows,
  - `has_duplicates`,
  - `parse_arguments`.
- Implemented stack-related helpers:
  - `is_sorted`,
  - `get_disorder` (inversion-based disorder metric).
- Implemented all core operations:
  - `sa`, `sb`, `ss`,
  - `pa`, `pb`,
  - `ra`, `rb`, `rr`,
  - `rra`, `rrb`, `rrr`,
  - plus operation counting for benchmark statistics.

#### gkordas

- Implemented the sorting algorithms:
  - `simple_sort`,
  - `medium_sort`,
  - `complex_sort` (radix-based),
  - `adaptive_sort` (selection logic).
- Implemented normalization / indexing:
  - `normalize_stack` and related utilities used by the complex strategy.
- Integrated flags and selection behavior:
  - forced strategies (`--simple`, `--medium`, `--complex`, `--adaptive`),
  - storage of `strat_used` in `t_data`.
- Implemented benchmark reporting:
  - `has_flag` for global flag detection,
  - `print_bench_details` to format strategy, complexity, and operation counts on `stderr`.

---

## Instructions

### Compilation

To compile the project, run the following command at the root of the repository:

```bash
make

This will create the push_swap executable. Other available rules are:

make clean: Removes object files.
make fclean: Removes object files and the executable.
make re: Recompiles the entire project.
```
## Execution
Run the program with a list of integers:

./push_swap 3 2 1
./push_swap "5 2 8 1"
Optional Flags
The program supports specific flags to force a strategy or display metrics:

--simple, --medium, --complex, --adaptive: Force a specific sorting method.
--bench: Displays performance metrics (disorder, strategy used, total operations) to stderr.
Example:
./push_swap --bench 100 2 50 3 4

---
### Algorithms: Explanation and Justification

We implemented four strategies to optimize the number of operations across different input sizes:

1) Simple Strategy (O(n²)): Used for stacks of 2 or 3 elements. It uses a hardcoded decision tree to sort with a maximum of 2 or 3 operations. Justification: At this scale, complex algorithms add unnecessary overhead; direct comparison is optimal.

2) Medium Strategy (O(n√n)): Used for stacks of 4 to 5 elements. It finds the minimum element, pushes it to stack B, and repeats until 3 elements remain in A (then sorted by the Simple strategy). Justification: This "Selection Sort" approach is very efficient for very small N, keeping the operation count well below the project limits.

3) Complex Strategy (O(n log n)): A Radix Sort implementation using bitwise operations on normalized indices. Justification: Radix sort provides a consistent and predictable number of operations for large stacks (100 or 500 numbers), ensuring we stay within the performance brackets required by the subject.

4) Adaptive Strategy: This is our "Hybrid" approach. It calculates a disorder metric (ratio of inversions) and checks the stack size to dynamically trigger the best-suited algorithm. Justification: This ensures the program is always efficient, whether the stack is nearly sorted or completely random.

### Resources

Documentation & Articles
42 Libft: Used for basic string and memory utilities.
Radix Sort for Push_swap: Research on bitwise sorting for two-stack systems.
Inversion Count Algorithms: Documentation on calculating stack disorder.
Standard C Library: man pages for write, malloc, free, and exit.

#AI Usage
I used AI to reduce repetitive tasks.
Logic Verification: Reviewing the logic of the function
Debugging: Identifying potential memory leaks and integer overflow edge cases during the parsing phase.
