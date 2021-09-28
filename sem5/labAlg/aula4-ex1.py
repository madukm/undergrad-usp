def all_sums(t, numbers, partial, sums):
    curr_sum = sum(partial)
    if curr_sum == t:
        sums[tuple(partial)] = None
    elif curr_sum >= t:
        return
    else:
        for i in range(len(numbers)):
            all_sums(t, numbers[i+1:], partial+[numbers[i]], sums)

if __name__ == "__main__":
    while True:
        line = input().split()
        t = int(line[0])
        n = int(line[1])
        if n == 0: break
        numbers = [int(x) for x in line[2:]]
        sums = dict()
        all_sums(t, numbers, [], sums)
        print("Sums of " + str(t) + ":")
        if not sums:
            print("NONE")
        for i in dict.fromkeys(sums):
            print(*i, sep='+')
