T = 10
for test_case in range(1, T + 1):
    N = int(input())
    lst = list(map(int, input().split()))
    ans = 100
    for _ in range(N):
        lst.sort()
        lst[0] += 1
        lst[-1] -= 1
        if ans > max(lst)-min(lst):
            ans = max(lst)-min(lst)
    print(f'#{test_case} {ans}')