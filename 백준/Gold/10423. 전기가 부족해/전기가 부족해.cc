#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define INF 987654321;
using namespace std;

// 10423 - 전기가 부족해
int n, m, k; // 도시의 수, 케이블의 수, 발전 도시의 수
vector<vector<pair<int, int>>> graph;
vector<int> isVisited; // 정점 방문 여부 저장
vector<int> generator; // 발전소가 설치된 도시의 정보 저장

void input(){
    cin >> n >> m >> k;

    graph.assign(n + 1, vector<pair<int, int>>{});
    isVisited.assign(n + 1, false);
    generator.assign(k, 0);

    // 발전소가 설치된 도시의 번호
    for(int i = 0; i < k; i++){
        cin >> generator[i];
    }

    // 케이블 연결
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
}

void setGenerator(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>& pq){
    // 발전소가 설치되어 있는 도시와 연결되어있는 간선의 정보를 넣는다.
    for(int i = 0; i < k; i++){
        isVisited[generator[i]] = true;
        for(int j = 0; j < graph[generator[i]].size(); j++){
            // 간선의 비용, 연결된 도시의 번호
            pq.push({graph[generator[i]][j].second, graph[generator[i]][j].first});
        }
    }
}

void prim(){
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    setGenerator(pq);

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(!isVisited[cur]){
            isVisited[cur] = true;
            sum += cost;

            for(int i = 0; i < graph[cur].size(); i++){
                int next = graph[cur][i].first;
                int n_cost = graph[cur][i].second;
                if(!isVisited[next]){
                    pq.push({n_cost, next});
                }
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