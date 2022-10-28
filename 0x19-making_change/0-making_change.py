#!/usr/bin/python3
"""
makeChange method
"""
def makeChange(coins, total):
    """
    determine the fewest number of coins needed
    to meet a given amount total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        count += total // coin
        total = total % coin
    if total:
        return -1
    return count