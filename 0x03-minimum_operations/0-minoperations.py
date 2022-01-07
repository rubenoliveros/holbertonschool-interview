#!/usr/bin/python3
"""0. Minimum Operations"""


def minOperations(n):
    """A function that calculates the accuracy of a prediction"""
    if not isinstance(n, int):
        return 0
    if n <= 0 or n == 1 or n is None:
        return 0
    if n % 2 == 0 and n != 2:
        return minOperations(int(n / 2)) + 2
    if n % 3 == 0 and n != 3:
        return minOperations(int(n / 3)) + 3
    f n % 5 == 0 and n != 5:
        return minOperations(int(n / 5)) + 5
    else:
        return int(n)
