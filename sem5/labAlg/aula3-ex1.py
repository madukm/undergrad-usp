def minimum_coins(coolness):
    coolness.sort()
    coins = 0
    last = -1
    for i in coolness:
        if last < i:
            last = i
        else:
            coins += last - i + 1
            last += 1
    return coins

if __name__ == "__main__":
    n = int(input())
    coolness = [int(x) for x in input().split()]
    print(minimum_coins(coolness))
