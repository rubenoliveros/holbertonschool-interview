#!/usr/bin/python3
"""
0x19. Making Change
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.
    """

    if total <= 0:
        return 0
    if total in coins:
        return 1
    if len(coins) <= 0:
        return -1
    dp = [total + 1] * (total + 1)
    dp[0] = 0
    for s in range(1, total + 1):
        for c in coins:
            if s - c >= 0:
                dp[s] = min(dp[s], 1 + dp[s - c])
    return dp[total] if dp[total] != total + 1 else -1
