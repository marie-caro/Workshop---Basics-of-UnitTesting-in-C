# Now onto the exercises

It's finally time to put your knowledge into practice! You will write unit tests for basic string and utility functions from the pool.

**Your mission:** Achieve at least **80% code coverage** and test all edge cases!

> Do not wait for every test to be written to run `tests_run`

---

## Step 1: Set Up Your Test Environment

### a) Create the test file
```bash
mkdir tests
touch tests/test_my_functions.c
```

In your test file, don't forget to include:
```c
#include <criterion/criterion.h>
```

### b) Complete the Makefile
Update the Makefile at the root of your project with the `tests_run` rule as well as some other parts (refer to the main README for details).

---

## Step 2: Write Your Tests!

### Exercise 1: `my_strlen`

**Function prototype:**
```c
int my_strlen(char const *str);
```

**What it does:** Returns the length of a string.

**Your tests:**
- Normal string → `"hello"` should return `5`
- Empty string → `""` should return `0`
- Single character → `"a"` should return `1`
- Longer string → `"Epitech"` should return `7`

💡 **Hint:** Use `cr_assert_eq()` to compare results!

---

### Exercise 2: `my_putchar`

**Function prototype:**
```c
int my_putchar(char c);
```

**What it does:** Writes a character to stdout and returns `0`.

**Your tests:**
- Test with different characters: `'a'`, `'Z'`, `'0'`, `' '`
- Verify it always returns `0`

💡 **Hint:** `cr_assert_eq(my_putchar('a'), 0)`

---

### Exercise 3: `my_str_isnum`

**Function prototype:**
```c
int my_str_isnum(char const *str);
```

**What it does:** Returns `1` if the string contains only digits (0-9), `0` otherwise.

**Your tests:**
| Input | Expected | Description |
|-------|----------|-------------|
| `"12345"` | `1` | Only numbers |
| `"hello"` | `0` | Contains letters |
| `"123abc"` | `0` | Mixed content |
| `""` | `1` | Empty string (edge case!) |
| `"123!"` | `0` | Special characters |
| `"1 2 3"` | `0` | Contains spaces |

💡 **Hint:** Think about what "only numbers" means!

---

## Step 3: You're Getting Good! Time to Fly Solo

For the following functions, **you** decide what tests to write!

**Requirements:**
- Write **at least 4 tests** per function
- Test normal cases, edge cases, and error cases
- Think about what could break the function

---

### Exercise 4: `my_str_isalpha`

**Function prototype:**
```c
int my_str_isalpha(char const *str);
```

**What it does:** Returns `1` if string contains only alphabetic characters (a-z, A-Z), `0` otherwise.

**Think about:**
- What about uppercase vs lowercase?
- What about empty strings?
- What about numbers or special characters?

---

### Exercise 5: `my_strupcase`

**Function prototype:**
```c
char *my_strupcase(char *str);
```

**What it does:** Converts all lowercase letters to uppercase and returns the modified string.

**Think about:**
- Does it modify the original string?
- What if the string is already uppercase?
- What about numbers and special characters?

---

### Exercise 6: `my_isneg`

**Function prototype:**
```c
int my_isneg(int nb);
```

**What it does:** Prints `'N'` if number is negative, `'P'` if positive or zero. Returns `0`.

**Think about:**
- What about zero? Is it positive or negative?
- What return value should you test?

---

### Exercise 7: `my_putstr`

**Function prototype:**
```c
int my_putstr(char const *str);
```

**What it does:** Prints a string to stdout and returns `0`.

**Think about:**
- Empty strings?
- Long strings?
- Strings with special characters?

---

## Finishing Up

Once you've written all your tests, run a final and see your final coverage result:
```bash
make tests_run
```

**Check your results:**
- All tests passing?
- Code coverage ≥ 80%?
- Edge cases covered?

---

## Bonus Challenges

Want to go further?
- Reach 100% code coverage
- Add even more edge cases
- Organize tests with meaningful suite names
- Try testing with NULL inputs (they should fail - that's expected!)

## End of workshop
 Congratulationsss, you now know how to do unit tests. This skill will give you an incomensurable advantage when it comes to  coding and having a steady program (aaand it will allow you to get bonus marks on your projects).
