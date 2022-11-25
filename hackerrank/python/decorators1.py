def wrapper(f):
    def fun(l):
        f(["+91 "+num[-10:-5]+" "+num[-5:] for num in l])
    return fun

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

l = [input() for _ in range(int(input()))]
sort_phone(l)

