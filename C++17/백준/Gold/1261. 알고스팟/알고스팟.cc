#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321; // 큰 값으로 초기화
const int dx[] = { 1, -1, 0, 0 }; // 상하좌우 이동을 위한 배열
const int dy[] = { 0, 0, 1, -1 };

int N, M;
vector<vector<int>> board;
vector<vector<int>> dist;

void bfs() {
    deque<pair<int, int>> dq;
    dq.push_back({ 0, 0 });
    dist[0][0] = 0;

    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        // 상하좌우로 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 미로 범위 내에 있는지 확인
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            // 벽을 부수고 이동하는 경우
            if (board[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                dq.push_back({ nx, ny }); // 벽이므로 뒤에 추가
            }

            // 빈 방으로 이동하는 경우
            else if (board[nx][ny] == 0 && dist[nx][ny] > dist[x][y]) {
                dist[nx][ny] = dist[x][y];
                dq.push_front({ nx, ny }); // 빈 방이므로 앞에 추가
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(M, vector<int>(N));
    dist.resize(M, vector<int>(N, INF));

    // 미로 입력 받기
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    bfs();
    cout << dist[M - 1][N - 1] << "\n";

    return 0;
}
