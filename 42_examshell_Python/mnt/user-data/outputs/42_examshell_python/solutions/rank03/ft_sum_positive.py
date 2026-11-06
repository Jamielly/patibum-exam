def ft_sum_positive(numbers: list[int]) -> int:
    total = 0
    for n in numbers:
        if n > 0:
            total += n
    return total
