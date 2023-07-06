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

// 9205 - 맥주 마시면서 걸어가기
int n = 0, result = 0;
vector<pair<int, int>> pos; // idx 0:home, idx n+1:festival
vector<vector<int>> graph;
vector<bool> isVisited;

void input(){
    cin >> n;
    pos.assign(n + 2, {0,0});
    graph.assign(n + 2, vector<int>(0, 0));
    isVisited.assign(n + 2, false);

    for(int i = 0; i < n + 2; i++){
        int y, x;
        cin >> y >> x;
        pos[i] = {y, x};
    }
}

int getDistance(const pair<int, int>& a, const pair<int, int>& b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void setEdge(){
    for(int i = 0; i < n + 2; i++){
        for(int k = i + 1; k < n + 2; k++){
            // 맥주 20병 * 50m
            if(getDistance(pos[i], pos[k]) <= 1000){
                graph[i].emplace_back(k);
                graph[k].emplace_back(i);
            }
        }
    }
}

void DFS(int idx){
    isVisited[idx] = true;

    for(int i = 0; i < graph[idx].size(); i++){
        int next = graph[idx][i];
        if(!isVisited[next]){
            DFS(next);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase = 0;
    cin >> testcase;

    while(testcase--){
        input();
        setEdge();
        DFS(0);

        if(isVisited[n + 1]){
            cout << "happy\n";
        }
        else{
            cout << "sad\n";
        }
    }

    return 0;
}