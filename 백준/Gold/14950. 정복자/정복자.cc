#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

#define INF 987654321;
using namespace std;

// 14950 - 정복자
int n, m, t; // 도시의 개수, 도로의 개수, 증가하는 도로의 비용
int sum = 0, time = 0;
vector<int> isVisited;
vector<vector<pair<int, int>>> graph; // first: next, second: cost

void input(){
    cin >> n >> m >> t;
    isVisited.assign(n + 1, false);
    graph.assign(n + 1, vector<pair<int, int>>{});

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
}

void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    isVisited[1] = true;
    for(int i = 0; i < graph[1].size(); i++){
        pq.push({graph[1][i].second, graph[1][i].first});
    }

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(!isVisited[cur]){
            isVisited[cur] = true;
            sum += cost + t * time;
            time++;

            for(int i = 0; i < graph[cur].size(); i++){
                int n_cost = graph[cur][i].second;
                int next = graph[cur][i].first;
                if(!isVisited[next])    pq.push({n_cost, next});
            }
        }
    }
    cout << sum;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    prim();

    return 0;
}