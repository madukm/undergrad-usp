def minimize_steps(distance, mid, k):
    curr = 0 # current size of the step
    day = k
    for d in distance:
        curr += d
        if curr > mid: # means we can't get there with only one step of size mid
            day -= 1
            if day < 0 or d > mid: # too short
                return False
            curr = d
    return True # too long

if __name__ == '__main__':
    while True:
        try:
            n, k = map(int, input().split())
            distance = []
            distance = [int(input()) for _ in range(n+1)]
            i = 0
            j = sum(distance)
            while j-i >= 0:
                mid = int((i+j)/2)
                if minimize_steps(distance, mid, k) == True:
                    j = mid-1
                else:
                    i = mid+1
            print(i if i>j else j)
            input()
        #i if minimize_steps(distance, i, k) else j)
        except:
            break
