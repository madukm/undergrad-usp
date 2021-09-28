# Maria Eduarda Kawakami Moreira - 11218751
# Aula 1 - Ex 1 
# SCC0210 - Algoritmos Avançados

from collections import defaultdict

def orderToLeave(n):
    crew = defaultdict(list)
    for value, key in [input().split() for _ in range(n)]:
        if key == "woman":
            crew["child"].append(value)
        else:
            crew[key].append(value)
    p = lambda a : print('\n'.join(a))
    if len(crew['rat']) > 0 : p(crew['rat'])
    if len(crew['child']) > 0 : p(crew['child'])
    if len(crew['man']) > 0 : p(crew['man'])
    if len(crew['captain']) > 0 : p(crew['captain'])

if __name__ == "__main__":
    n = int(input())
    orderToLeave(n)
