#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct State {
    int rx, ry, bx, by, moves;
};

int N, M;
char board[10][10];
bool visited[10][10][10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> move(int x, int y, int dx, int dy) {
    int count = 0;
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
        count++;
    }
    return {x, y};
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        auto [rx, ry, bx, by, moves] = q.front();
        q.pop();

        if (moves >= 10) return -1;

        for (int i = 0; i < 4; i++) {
            auto [nrx, nry] = move(rx, ry, dx[i], dy[i]);
            auto [nbx, nby] = move(bx, by, dx[i], dy[i]);

            if (board[nbx][nby] == 'O') continue;
            if (board[nrx][nry] == 'O') return moves + 1;

            if (nrx == nbx && nry == nby) {
                if (abs(nrx - rx) + abs(nry - ry) > abs(nbx - bx) + abs(nby - by)) {
                    nrx -= dx[i];
                    nry -= dy[i];
                } else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, moves + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;

    int rx, ry, bx, by;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << endl;
    return 0;
}
