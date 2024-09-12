#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
    int screen;   // 현재 화면에 있는 이모티콘 개수
    int clipboard; // 현재 클립보드에 있는 이모티콘 개수
    int time;      // 경과 시간
};

int minTimeToCreateEmoticons(int S) {
    queue<State> q;
    vector<vector<bool>> visited(S + 1, vector<bool>(S + 1, false));
    
    // 초기 상태: 화면에 1개, 클립보드에 0개, 시간 0
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int screen = current.screen;
        int clipboard = current.clipboard;
        int time = current.time;

        // 목표 상태에 도달한 경우
        if (screen == S) {
            return time;
        }

        // 1. 복사: 화면의 이모티콘을 클립보드에 복사
        if (!visited[screen][screen]) {
            visited[screen][screen] = true;
            q.push({screen, screen, time + 1});
        }

        // 2. 붙여넣기: 클립보드의 이모티콘을 화면에 붙여넣기
        if (clipboard > 0 && screen + clipboard <= S && !visited[screen + clipboard][clipboard]) {
            visited[screen + clipboard][clipboard] = true;
            q.push({screen + clipboard, clipboard, time + 1});
        }

        // 3. 삭제: 화면의 이모티콘 하나 삭제
        if (screen > 1 && !visited[screen - 1][clipboard]) {
            visited[screen - 1][clipboard] = true;
            q.push({screen - 1, clipboard, time + 1});
        }
    }

    return -1; // 도달할 수 없는 경우
}

int main() {
    int S;
    cin >> S;
    cout << minTimeToCreateEmoticons(S) << endl;
    return 0;
}
