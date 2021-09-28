# Maria Eduarda Kawakami Moreira - 11218751
# Aula 2 - Ex 1 
# SCC0210 - Lab de Algoritmos Avançados

def add_comments(n, m):
    servers = {ip: name for name, ip in (input().split() for _ in range(n))}
    for line in (input() for _ in range(m)):
        ip = line.split()[1]
        print(line + ' #' + servers[ip[:len(ip)-1]])

if __name__ == '__main__':
    n, m = map(int, input().split())
    add_comments(n, m)
