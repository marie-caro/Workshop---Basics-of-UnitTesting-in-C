# Workshop --- Basics of UnitTesting in C

## Linux Installation:
1. Go to: https://intra.epitech.eu/file/Public/technical-documentations/C/
2. Install the script: ```install_criterion.sh```
3. Go to your Downloads, and in the terminal execute the following command
```
chmod +x install_criterion.sh
./install_criterion.sh
```
It will ask you at some point your password, write it.

4. And now time to install gcovr
```
sudo apt update
sudo apt install gcovr

```

## Unit Testing Basic Idea
### What is it
Testing individual functions of your code to ensure that they behaved as expected, ensure that they return correct outputs for given inputs
### Why do we do this
1. catch bugs
2. reduce regression issues (breaking a feature while adding a new one)
3. improve code quality


## Repository structure for Epitech Delivery
```
| tests/
| src/
| include/
| Makefile
```

## Makefile Rules
For the moulinette to detect your unit tests, you are going to need the following rule:

    tests_run

```
unit_test:
	gcc -o unit_tests <your .c files> <your test files> --coverage -lcriterion

tests_run:	unit_test
	./unit_tests
	gcovr -r . --exclude tests/
	rm *.gcno *.gcda
```
This is just an explanation for you to understand the rules, do not use them as they are here.
You can go to the Makefile provided at the root of this repository to see what a correct Makefile would be.

### Understanding the rules
Click for more information on the rules
<details>
<summary>The unit_test rule</summary>
This rule compiles your unit tests into an executable called unit_tests.

**Breaking down the command:**

- `gcc` - The C compiler
- `-o unit_tests` - Names the output executable "unit_tests"
- `<your .c files>` - Your source code files (e.g., `src/my_functions.c`)
- `<your test files>` - Your test files (e.g., `tests/test_my_functions.c`)
- `--coverage` - Enables code coverage analysis (generates `.gcno` and `.gcda` files)
- `-lcriterion` - Links the Criterion testing library

</details>

<details>
<summary>The tests_run rule</summary>

This is the main rule that the moulinette will call. It depends on `unit_test`, meaning it will compile first if needed.

**What it does:**

1. `unit_test` - Ensures the tests are compiled before running
2. `./unit_tests` - Executes your test suite
3. `gcovr -r . --exclude tests/` - Generates a coverage report
   - `-r .` - Sets the root directory at the current repository level (adjust based on your project structure)
   - `--exclude tests/` - Excludes the tests directory from coverage calculation
4. `rm *.gcno *.gcda` - Cleans up coverage files after generating the report

</details>

### Important Notes

> The tests_run rule must exist for the moulinette to work

> Make sure your .c files and test files are correctly specified

> The --coverage flag is essential for code coverage tracking

> The gcovr path (-r .) may need adjustment depending on your project structure


## Unit Testing
You will write .c files with functions that follow this format:
```
# include < criterion / criterion .h > // DO NOT FORGET THIS LINE

Test (suite_name, test_name) {
    ...
}
```
Be careful, each test MUST have unique names for both the suite and the test, and the test name should be meaningful. Do not write `test1` or `test2`, make it descriptive: `test_addition_with_negative_numbers` or `test_strlen_with_empty_string`.

### Useful terminology
The `suite_name` groups related tests together (like "string_functions" or "math_operations"), and `test_name` describes what you're testing (like "test_strlen_empty_string" or "test_addition_positive_numbers").

An `assert` is a statement that checks if something is true. If the condition you're checking is false, the test fails.
> For example: cr_assert(result == 5) means "I expect result to equal 5, and if it doesn't, this test should fail."



### List of asserts

| Assert | Description | Example | When to Use |
|--------|-------------|---------|-------------|
| `cr_assert(condition)` | Basic assertion - test fails if false | `cr_assert(x > 0)` | Simple true/false checks |
| `cr_expect(condition)` | Like assert but continues on failure | `cr_expect(x > 0)` | When you want to see all failures |
| `cr_assert_eq(a, b)` | Checks equality | `cr_assert_eq(result, 5)` | Comparing numbers or return values |
| `cr_assert_neq(a, b)` | Checks inequality | `cr_assert_neq(x, y)` | Verifying values are different |
| `cr_assert_str_eq(a, b)` | String equality | `cr_assert_str_eq(str, "hello")` | Comparing strings (always use this!) |
| `cr_assert_str_neq(a, b)` | String inequality | `cr_assert_str_neq(s1, s2)` | Verifying strings are different |
| `cr_assert_str_empty(str)` | String is empty | `cr_assert_str_empty(str)` | Checking for "" |
| `cr_assert_str_not_empty(str)` | String is not empty | `cr_assert_str_not_empty(str)` | Verifying string has content |
| `cr_assert_arr_eq(a, b, size)` | Array equality | `cr_assert_arr_eq(arr1, arr2, 5)` | Comparing arrays element by element |
| `cr_assert_arr_neq(a, b, size)` | Array inequality | `cr_assert_arr_neq(arr1, arr2, 5)` | Verifying arrays differ |
| `cr_assert_null(ptr)` | Pointer is NULL | `cr_assert_null(ptr)` | Checking error returns, uninitialized pointers |
| `cr_assert_not_null(ptr)` | Pointer is not NULL | `cr_assert_not_null(ptr)` | Verifying malloc success, valid pointers |
| `cr_assert_float_eq(a, b, eps)` | Float equality with tolerance | `cr_assert_float_eq(f, 3.14, 0.01)` | Comparing floats/doubles (never use ==) |
| `cr_assert_lt(a, b)` | Less than (a < b) | `cr_assert_lt(x, 10)` | Range checks, ordering |
| `cr_assert_leq(a, b)` | Less or equal (a <= b) | `cr_assert_leq(x, 10)` | Inclusive upper bounds |
| `cr_assert_gt(a, b)` | Greater than (a > b) | `cr_assert_gt(x, 0)` | Minimum value checks |
| `cr_assert_geq(a, b)` | Greater or equal (a >= b) | `cr_assert_geq(x, 0)` | Inclusive lower bounds |


### How to structure your tests

1. Setup - Prepare what you need (allocate memory, initialize variables)
2. Action - Call the function you're testing
3. Assert - Check the result is what you expected
4. Cleanup - Free memory if needed (though Criterion handles this pretty well)

### Example to illustrate the structure
```
Test(my_suite, test_my_strdup) {
    // Setup
    char *original = "hello";

    // Action
    char *copy = my_strdup(original);

    // Assert
    cr_assert_not_null(copy);
    cr_assert_str_eq(copy, original);
    cr_assert_neq(copy, original);  // Different pointers

    // Cleanup
    free(copy);
}
```

### What should you test

1. Normal cases: Does it work with typical input?
2. Edge cases: Empty strings, zero, negative numbers, very large numbers...
3. Error cases: NULL pointers, invalid input :: what should fail?
4. Boundary conditions: First element, last element :: array limits


### Examples to understand what to test:
```
Test(math, addition) {
    cr_assert_eq(add(2, 3), 5);
    cr_assert_eq(add(-1, 1), 0);
    cr_assert_eq(add(0, 0), 0);
}

Test(strings, my_strlen) {
    cr_assert_eq(my_strlen("hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
}

Test(strings, strdup_null) {
    char *result = my_strdup(NULL);
    cr_assert_null(result);
}

Test(memory, malloc_check) {
    char *str = malloc(10);
    cr_assert_not_null(str);
    free(str);
}
```

## Understanding the results:
# TODO

