#include <iostream>
#include <vector>
using namespace std;

const int N = 19;
int board[N][N];
int backwardX, backwardY;

// 방향을 나타내는 배열 (가로, 세로, 대각선 오른쪽 위, 대각선 오른쪽 아래)
int dx[] = { 0, 1, 1, -1 };
int dy[] = { 1, 0, 1, 1 };

bool isValid(int x, int y) {
    return x >= 0 && x < N&& y >= 0 && y < N;
}

bool checkFive(int row, int col) {
    if (board[row][col] == 0) return false; // 빈 칸은 검사할 필요 없음

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;
        // 앞쪽 방향으로 연속된 돌 확인
        int x = row + dx[dir];
        int y = col + dy[dir];
        while (isValid(x, y) && board[x][y] == board[row][col]) {
            count++;
            x += dx[dir];
            y += dy[dir];
        }

        // 연속된 돌의 앞쪽 끝 검사
        int forwardX = x;
        int forwardY = y;

        // 반대 방향으로 연속된 돌 확인
        x = row - dx[dir];
        y = col - dy[dir];
        while (isValid(x, y) && board[x][y] == board[row][col]) {
            count++;
            x -= dx[dir];
            y -= dy[dir];
        }

        // 연속된 돌의 뒤쪽 끝 검사
        backwardX = x +dx[dir];
        backwardY = y +dy[dir];

        // 정확히 5개의 돌이 연속되는지 확인
        if (count == 5) {
            // 양 끝이 둘 다 유효하지 않거나, 양쪽 끝에 동일한 색의 돌이 없는 경우에만 true 반환
            if ((!isValid(forwardX, forwardY) || board[forwardX][forwardY] != board[row][col]) &&
                (!isValid(backwardX -dx[dir], backwardY -dy[dir]) || board[backwardX -dx[dir]][backwardY- dy[dir]] != board[row][col])) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (checkFive(i, j)) {
                cout << board[i][j] << "\n" << backwardX + 1 << " " << backwardY + 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << '\n'; // 승자 없음
    return 0;
}