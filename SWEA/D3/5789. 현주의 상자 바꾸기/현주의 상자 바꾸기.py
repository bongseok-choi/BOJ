T = int(input())
for test_case in range(1, T + 1):
    N, Q = map(int, input().split())
 
    lst = [0] * (N+1)
    for val in range(1, Q+1):
        L, R = map(int, input().split())
        for i in range(L, R+1):
            lst[i] = val
    print(f'#{test_case}', *lst[1:])