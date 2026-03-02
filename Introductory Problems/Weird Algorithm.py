
def weird_algorithm(n):
    print(n, end=" ")
    if n == 1:
        return
    elif n % 2 == 0:
        weird_algorithm(n // 2)
    else:
        weird_algorithm(3 * n + 1)
n = int(input())
weird_algorithm(n)