def all_pw_by_rule(words, rule, index, partial):
    if index == len(rule):
        print(''.join(partial))
        return
    if rule[index] == '0':
        for i in range(10):
            all_pw_by_rule(words, rule, index+1, partial+[str(i)])
    else:
        for w in words:
            all_pw_by_rule(words, rule, index+1, partial+[w])

def all_passwords(words, rules):
    for r in rules:
        all_pw_by_rule(words, r, 0, [])

if __name__ == '__main__':
    while True:
        try:
            n = int(input())
            words = []
            for _ in range(n):
                words.append(input())
            m = int(input())
            rules = []
            for _ in range(m):
                rules.append([c for c in input()])
            print('--')
            all_passwords(words, rules)
        except:
            break

