#!/usr/bin/python3
from sys import argv
""" this modual gets the first prime factors of any number """


def rsa(line):
    """
        This rsa function
        gets the prime factors
        of a number and
        prints them out
    """
    num = int(line)
    if num % 2 == 0:
        print("{}={}*{}".format(num, int(num/2), 2))
        return

    for i in range(3, int(num/2), 2):
        # print(i)
        if num % i == 0:
            for x in range(3, int(num/2), 2):
                if (i % x == 0):
                    print("{}={}*{}".format(num, int(num/i), i))
                    return


with open(argv[1]) as f:
    for line in f:
        rsa(line)
