#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000;
vector<int> graph[MAX];
bool visited[MAX];

bool dfs(int node, int depth, int target) {
    if (depth == target) {
        return true;
    }
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, depth + 1, target)) {
                return true;
            }
        }
    }
    visited[node] = false;
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) {
        fill(visited, visited + N, false); // 방문 배열 초기화
        if (dfs(i, 1, 5)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
