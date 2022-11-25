def countdivideby3and5(numbers):
    return sum([1 for num in numbers if (num % 15 == 0) and sum([int(x) for x in str(num)])])


if __name__ == '__main__':
    numbers = []
    count = int(input())
    for i in range(count):
        numbers.append(int(input()))

    print(countdivideby3and5(numbers))
