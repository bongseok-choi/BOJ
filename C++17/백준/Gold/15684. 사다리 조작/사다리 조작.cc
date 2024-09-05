#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
bool ladder[31][11];  // 사다리 배열, [a][b]는 b번 세로선과 b+1번 세로선을 a번 점선에서 연결

// 사다리 타기 시뮬레이션: i번 세로선에서 출발해서 어디로 도착하는지 확인
int simulate() {
    for (int i = 1; i <= N; i++) {
        int cur = i;  // 현재 세로선 번호
        for (int j = 1; j <= H; j++) {
            if (ladder[j][cur]) cur++;       // 오른쪽으로 이동
            else if (ladder[j][cur - 1]) cur--;  // 왼쪽으로 이동
        }
        if (cur != i) return false;  // 자기 자신으로 돌아오지 않으면 실패
    }
    return true;  // 모든 세로선이 자기 자신으로 돌아오면 성공
}

// 가로선 추가하기 (백트래킹)
int solve(int cnt, int x, int y) {
    if (cnt > 3) return -1;  // 가로선을 3개 이상 추가하면 불가능
    if (simulate()) return cnt;  // 성공하면 추가한 가로선의 개수 리턴

    int res = -1;
    for (int i = x; i <= H; i++) {
        for (int j = (i == x ? y : 1); j < N; j++) {
            if (!ladder[i][j] && !ladder[i][j-1] && !ladder[i][j+1]) {  // 가로선을 추가할 수 있는지 확인
                ladder[i][j] = true;  // 가로선 추가
                int temp = solve(cnt + 1, i, j + 2);  // 다음 위치로 이동
                if (temp != -1) {
                    if (res == -1) res = temp;
                    else res = min(res, temp);
                }
                ladder[i][j] = false;  // 가로선 제거 (백트래킹)
            }
        }
    }

    return res;
}

int main() {
    cin >> N >> M >> H;

    // 입력으로 주어진 가로선 정보 저장
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    // 문제 해결
    int result = solve(0, 1, 1);
    cout << result << endl;

    return 0;
}
