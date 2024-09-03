#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> board;

int getMaxBlock(const vector<vector<int>>& b) {
    int maxBlock = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxBlock = max(maxBlock, b[i][j]);
        }
    }
    return maxBlock;
}

vector<vector<int>> moveLeft(const vector<vector<int>>& b) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int idx = 0;
        int lastValue = 0;
        for (int j = 0; j < N; j++) {
            if (b[i][j] == 0) continue;
            if (lastValue == 0) {
                lastValue = b[i][j];
            } else {
                if (lastValue == b[i][j]) {
                    newBoard[i][idx++] = 2 * lastValue;
                    lastValue = 0;
                } else {
                    newBoard[i][idx++] = lastValue;
                    lastValue = b[i][j];
                }
            }
        }
        if (lastValue != 0) {
            newBoard[i][idx] = lastValue;
        }
    }
    return newBoard;
}

vector<vector<int>> rotateBoard(const vector<vector<int>>& b) {
    vector<vector<int>> newBoard(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newBoard[j][N - 1 - i] = b[i][j];
        }
    }
    return newBoard;
}

int dfs(vector<vector<int>> b, int depth) {
    if (depth == 5) {
        return getMaxBlock(b);
    }
    int maxBlock = 0;
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> nextBoard = moveLeft(b);
        maxBlock = max(maxBlock, dfs(nextBoard, depth + 1));
        b = rotateBoard(b);
    }
    return maxBlock;
}

int main() {
    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(board, 0) << endl;
    return 0;
}
