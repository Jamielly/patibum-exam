"""Exercise definition. The shell imports this file and grades rendu/<FILENAME>.

Add a new subject by copying this file, changing the fields below, and adding
the reference solution to solutions/rank03/<FILENAME>.
"""

FILENAME = "ft_sum_positive.py"
FUNCTION = "ft_sum_positive"

ASSIGNMENT = """
Write a function that returns the sum of all strictly positive integers
in a list. Zero and negative numbers must be ignored.
"""

SIGNATURE = "def ft_sum_positive(numbers: list[int]) -> int:"

# Each test is (tuple_of_arguments, expected_result).
# Keep them JSON-serializable (lists, ints, strings, bools, None).
TESTS = [
    ([[1, 2, 3]], 6),
    ([[-1, 0, 5]], 5),
    ([[]], 0),
    ([[-4, -2]], 0),
    ([[10, -10, 10]], 20),
]
