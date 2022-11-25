#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the kangaroo function below.
def kangaroo(x1, v1, x2, v2):
    if v2 >= v1:
        return 'NO'
    while x1 <=x2:
        if x1== x2:
            return 'YES'
        x1+=v1
        x2+=v2
    return 'NO'


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    x1, v1, x2, v2 = map(int, input().split())

    result = kangaroo(x1, v1, x2, v2)

    fptr.write(result + '\n')

    fptr.close()
