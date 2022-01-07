#!/usr/bin/python3
"""0. Minimum Operations"""


def minOperations(n):
    """A function that calculates the accuracy of a prediction"""
    t = 0
    m = 2
    while n > 1:
        while not n % m:
            t += m
            n /= m
        m += 1
    return t
