#!/usr/bin/python3
from sys import argv
import math
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

    sq = int(math.sqrt(num))
    print(sq)

    if sq % 2 != 0:
        sq += 1

    HalfSq = int(sq/2)  # cuts sq in half

    for i in range(sq, int(num/2), 2):
        SqRootIt = i - sq  # iterator from sqaure root
        # print("n = ", n)
        if num % i == 0:
            for x in range(3, i, 2):
                if i % x == 0:
                    print("{}={}*{}".format(num, int(num/i), i))
                    return
        if num % SqRootIt == 0:  # currently implimenting square root method
            for  



        


with open(argv[1]) as f:
    for line in f:
        rsa(line)
