# Maria Eduarda Kawakami Moreira - 11218751
# Aula 1 - Exercício 2
# SCC0210 - Laboratório de Algoritmos Avançados

from heapq import *

def getID(pq, k):
    heapify(pq)
    while k>0:
        last = heappop(pq)
        print(last[1])
        heappush(pq, [last[0]+last[2], last[1], last[2]])
        k-=1

if __name__ == '__main__':
    pq = [] # will be turned into a priority queue
    while True:
        string = input()
        if string == '#': break
        _ = string.split()
        pq.append(list(map(int, (_[2], _[1], _[2])))) # we need to keep track of the original period
    getID(pq, int(input()))
