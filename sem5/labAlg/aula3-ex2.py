def maximum_number(number, f_x):
    for index in range(len(number)):
        digit = number[index]
        if f_x[digit-1] > digit:
            number[index] = f_x[digit-1]
    return int(''.join(map(str, number)))


if __name__ == "__main__":
    n = int(input())
    number = [int(i) for i in input()]
    f_x = [int(i) for i in input().split()]
    print(maximum_number(number, f_x))
