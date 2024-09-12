#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;  // 가능한 최대 위치

int N, K;
int time[MAX];           // 각 위치에 도달하는 데 걸린 시간
int previous[MAX];       // 각 위치로 오기 전 위치를 기록

void bfs() {
    queue<int> q;
    q.push(N);          // 시작 위치 N에서 시작
    time[N] = 0;        // 시작 위치에서 걸린 시간은 0
    previous[N] = -1;   // 시작점이므로 이전 위치는 없음

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == K) return;  // 동생의 위치에 도달하면 종료

        // 3가지 경우: 앞으로, 뒤로, 순간이동
        for (int next : {current - 1, current + 1, current * 2}) {
            if (next >= 0 && next < MAX && time[next] == -1) {
                time[next] = time[current] + 1;  // 다음 위치까지 걸리는 시간 기록
                previous[next] = current;        // 이전 위치 기록
                q.push(next);
            }
        }
    }
}

void printPath() {
    vector<int> path;
    for (int i = K; i != -1; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for (int i : path) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    cin >> N >> K;

    fill(time, time + MAX, -1);  // 시간 배열 초기화
    bfs();

    cout << time[K] << "\n";  // 동생을 찾는 데 걸린 최소 시간 출력
    printPath();              // 경로 출력

    return 0;
}
