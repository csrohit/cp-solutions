def lcm(a, b):
    """Calculate LCM of the pair."""
    if a > b:
        return int((a*b)/gcd(b, a))
    return int((a*b)/gcd(a, b))


def gcd(a, b):
    """Calculate GCD of the pair."""
    if a == 0:
        return b
    return gcd(b % a, a)


def count():
    input()
    l = 1
    for i in map(int, input().split()):
        l = lcm(l, i)
        if l > 100:
            return 0    # max value of B is 100, if lcm is more than 100 then 0 factors are there
                        # also we can limit the value of lcm to min(B)
            break
    g = 0
    for i in map(int, input().split()):
        g = gcd(g, i)
    return sum([1 for i in range(l,g+1,l) if (g % i) is 0])

if __name__ == '__main__':
    """
    The main function.
        
    find the LCM of list A and GCD of list B
    print the count of multiples of LCM that divides the GCD    
    """
    print(count())