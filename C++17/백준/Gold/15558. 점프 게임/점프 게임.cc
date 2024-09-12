#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int line, position, time;
    State(int line, int position, int time) : line(line), position(position), time(time) {}
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> board(2, vector<int>(N + 1));  // 2개의 줄 (왼쪽, 오른쪽) 정보 저장
    vector<vector<bool>> visited(2, vector<bool>(N + 1, false));  // 방문 여부 체크 배열

    // 입력 받기 (왼쪽 줄, 오른쪽 줄)
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            board[i][j] = c - '0';  // '0'이나 '1'을 정수로 변환
        }
    }

    queue<State> q;
    q.push({0, 1, 0});  // 처음 시작: 왼쪽 줄(0), 첫 번째 칸(1번), 시간 0
    visited[0][1] = true;  // 시작 위치 방문 처리

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int line = current.line;  // 현재 줄 (0: 왼쪽, 1: 오른쪽)
        int pos = current.position;  // 현재 칸
        int time = current.time;  // 경과 시간

        // 탈출 조건: 현재 칸이 N번 칸을 넘으면 게임 클리어
        if (pos > N) {
            cout << 1 << endl;
            return 0;
        }

        // 현재 칸이 사라졌는지 확인
        if (pos <= time) continue;

        // 이동 가능한 세 가지 경우 확인
        // 1. 한 칸 앞으로 이동
        if (pos + 1 <= N && board[line][pos + 1] == 1 && !visited[line][pos + 1]) {
            visited[line][pos + 1] = true;
            q.push({line, pos + 1, time + 1});
        }

        // 2. 한 칸 뒤로 이동 (사라진 칸이 아니어야 함)
        if (pos - 1 > time && board[line][pos - 1] == 1 && !visited[line][pos - 1]) {
            visited[line][pos - 1] = true;
            q.push({line, pos - 1, time + 1});
        }

        // 3. 반대편 줄로 점프
        int newLine = 1 - line;  // 반대편 줄 (0 -> 1, 1 -> 0)
        if (pos + K <= N && board[newLine][pos + K] == 1 && !visited[newLine][pos + K]) {
            visited[newLine][pos + K] = true;
            q.push({newLine, pos + K, time + 1});
        }

        // 반대편 줄로 점프 시, N을 넘으면 바로 클리어 처리
        if (pos + K > N) {
            cout << 1 << endl;
            return 0;
        }
    }

    // BFS 탐색 종료 후에도 클리어하지 못한 경우
    cout << 0 << endl;
    return 0;
}
