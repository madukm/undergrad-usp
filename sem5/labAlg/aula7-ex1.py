



def money_sum(coin, n, x):
    sol = [0 for i in range(x+1)]
    mod = 1e9+7
    sol[0] = 1
    for i in range(1, x+1):
        for j in range(n):
            if i >= coin[j]:
                sol[i] += (sol[i-coin[j]])%mod

    return int(sol[x]%mod)

if __name__ == '__main__':
    # n = number of coins
    # x = desired sum
    n, x = map(int, input().split())
    coin = [int(x) for x in input().split()]
    print(money_sum(coin, n, x))
