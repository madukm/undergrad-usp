import sys
from heapq import *

def check(n, visited, maze, pos):
    x, y = pos
    if x < 0 or x >= n or y < 0 or y >= n: # not a valid path
        return False
    return not (maze[x][y] == 0 or visited[x][y])

def manhattan(start, finish):
    return (abs(start[0]-finish[0])+abs(start[1]-finish[1]))

# heuristic = manhattan + depth

def a_star(n, maze, visited, start, finish):
    depth = 0
    pq = [[manhattan(start, finish), start, depth]] # priority queue = [heuristic, position, depth]
    heapify(pq)
    x, y = start
    while pq:
        if x == finish[0] and y == finish[1]:
            return depth
        last = heappop(pq)
        x, y = last[1]
        depth = last[2] + 1
        visited[x][y] = True
        if check(n, visited, maze, (x, y+1)) == True:
            heappush(pq, [manhattan((x, y+1), finish)+depth, (x, y+1), depth])
        if check(n, visited, maze, (x-1, y)) == True:
            heappush(pq, [manhattan((x-1, y), finish)+depth, (x-1, y), depth])
        if check(n, visited, maze, (x, y-1)) == True:
            heappush(pq, [manhattan((x, y-1), finish)+depth, (x, y-1), depth])
        if check(n, visited, maze, (x+1, y)) == True:
            heappush(pq, [manhattan((x+1, y), finish)+depth, (x+1, y), depth])
    return -1


if __name__ == '__main__':
    k = int(input()) # number of test cases
    for _ in range(k):
        n = int(input()) # dimension of the labirinth
        start = tuple([int(x) for x in input().split()])
        finish = tuple([int(x) for x in input().split()])
        maze = []
        visited = [[False for i in range(n)] for j in range(n)]
        for _ in range(n):
            maze.append([int(i) for i in input().split()])
        ans = a_star(n, maze, visited, start, finish)
        if ans == -1:
            print('Caminho Inexistente.')
        else:
            print('Nro de posicoes: ' + str(ans))

