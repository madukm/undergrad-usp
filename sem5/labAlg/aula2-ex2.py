# Maria Eduarda Kawakami Moreira - 11218751
# Aula 2 - Ex 2 
# SCC0210 - Lab de Algoritmos Avançados

def remove_doubles(string):
    stack = []
    ans = ""
    for i in string:
        if not stack:
            stack.append(i)
        elif stack[-1] == i:
            stack.pop()
        else:
            stack.append(i)
    return "".join(stack)

if __name__ == "__main__":
    string = str(input())
    print(remove_doubles(string))
