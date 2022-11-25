from collections import namedtuple

n, columns = int(input()), input().split()
Student = namedtuple('Student', columns)
print(sum([int(Student._make(input().split()).MARKS) for i in range(n)])/n)