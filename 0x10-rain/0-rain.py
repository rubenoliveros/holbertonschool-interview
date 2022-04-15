#!/usr/bin/python3
"""0. Rain"""


def rain(walls):
    """
    Prototype: def rain(walls)
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    Assume that the ends of the list (before index 0 and after index walls[-1])
    are not walls, meaning they will not retain water.
    If the list is empty return 0.
    """

    if not walls or len(walls) < 3:
        return 0

    rainwater = 0

    for i in range(0, len(walls)):
        preWall = max(walls[:i + 1])
        postWall = max(walls[i:])
        rainwater += min(preWall, postWall) - walls[i]

    return rainwater
