#!/usr/bin/python3
"""0. UTF-8 Validation"""


def validUTF8(data):
    """
    A method that determines if a given data
    set represents a valid UTF-8 encoding
    """
    data = [n & 255 for n in data]
    try:
        bytes(data).decode()
    except (ValueError, UnicodeError):
        return False
    else:
        return True


if __name__ == "__main__":
    pass
