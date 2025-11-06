##
## EPITECH PROJECT, 2023
## makefile
## File description:
##
##
SRC =	#TODO: add the src file
TEST_SRC =	#TODO: add the test file

BIN = binary
TEST_BIN =	unit_tests

OBJ = $(SRC:.c=.o)


# Compilation Flags ---------------------------------------
TEST_FLAGS = --coverage -lcriterion
W_FLAGS = -Wall -Werror -Wextra
VALGRIND_FLAGS = -g3

all: $(BIN)

$(BIN):
	$(CC) -c $(SRC) $(W_FLAGS) $(VALGRIND_FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(TEST_BIN)
	$(RM) *.gcno *.gcda

re:	fclean all

unit_test:	fclean $(BIN)
#TODO: Complete here
	$(CC) -o {...}

tests_run:	unit_test
	./unit_tests
	gcovr -r . --exclude tests/
	$(RM) $(TEST_BIN)
	$(RM) *.gcno *.gcda

.PHONY: all clean fclean re unit_test tests_run