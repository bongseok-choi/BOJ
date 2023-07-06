#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define INF 987654321
#define MAX 1000000 + 1
using namespace std;

// 4803 - 트리
vector<vector<int>> graph;
vector<int> isVisited;

void input(int& n, int& m){
    graph.assign(n + 1, vector<int>(0, 0));
    isVisited.assign(n + 1, false);

    for(int i = 0; i < m; i++){
        int s = 0, e = 0;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
}

bool DFS(int idx, int before){
    isVisited[idx] = true;

    for(int i = 0; i < graph[idx].size(); i++){
        int next = graph[idx][i];
        if(next == before)  continue; // 바로 이전에 방문한 곳인 경우 pass

        if(isVisited[next]) return false;
        if(!DFS(next, idx)) return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx = 0;
    while(true){
        int n, m, tree = 0;
        cin >> n >> m;
        if(n == 0 && m == 0)    break;

        input(n, m);
        idx++;

        for(int i = 1; i <= n; i++){
            if(!isVisited[i]){
                if(DFS(i, 0))   tree++;
            }
        }

        if(tree == 0)   cout << "Case " << idx << ": No trees.\n";
        else if(tree == 1)  cout << "Case " << idx << ": There is one tree.\n";
        else    cout << "Case " << idx << ": A forest of " << tree <<" trees.\n";
    }

    return 0;
}