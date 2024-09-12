#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int N, int K) {
    vector<bool> visited(100001, false); // 방문 여부를 확인하는 배열
    queue<pair<int, int>> q;  // (위치, 시간)을 저장하는 큐
    q.push({N, 0});  // 수빈이의 현재 위치와 시간을 큐에 넣음
    visited[N] = true;

    while (!q.empty()) {
        int current_position = q.front().first;
        int time = q.front().second;
        q.pop();

        // 동생의 위치에 도착했을 때 시간을 반환
        if (current_position == K) {
            return time;
        }

        // 세 가지 이동 방법에 대해 처리
        if (current_position - 1 >= 0 && !visited[current_position - 1]) {
            visited[current_position - 1] = true;
            q.push({current_position - 1, time + 1});
        }
        if (current_position + 1 <= 100000 && !visited[current_position + 1]) {
            visited[current_position + 1] = true;
            q.push({current_position + 1, time + 1});
        }
        if (current_position * 2 <= 100000 && !visited[current_position * 2]) {
            visited[current_position * 2] = true;
            q.push({current_position * 2, time + 1});
        }
    }
    return -1;  // 동생을 찾지 못하는 경우는 없음
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
    return 0;
}
