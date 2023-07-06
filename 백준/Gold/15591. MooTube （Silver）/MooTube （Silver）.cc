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

// 15591 - MooTube(Silver)
int n, q; // 영상의 개수, 질문의 개수
vector<vector<pair<int, long long>>> graph; // 간선 저장

void input(){
    cin >> n >> q;
    graph.assign(n + 1, vector<pair<int, long long>>(0, {0, 0}));

    for(int i = 0; i < n - 1; i++){
        int s, e;
        long long c;
        cin >> s >> e >> c;
        graph[s].emplace_back(make_pair(e, c));
        graph[e].emplace_back(make_pair(s, c));
    }
}

void BFS(long long k, int v){
    vector<int> isVisited(n + 1, false);
    isVisited[v] = true;

    queue<pair<int, long long>> q;
    q.push({v, k});
    int count = 0;

    while(!q.empty()){
        int cur = q.front().first;
        int cur_cost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;

            if(!isVisited[next] && next_cost >= k){
                isVisited[next] = true;
                count++;
                q.push({next, next_cost});
            }
        }
    }

    cout << count << '\n';
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for(int i = 0; i < q; i++){
        long long k = 0;
        int v = 0;
        cin >> k >> v;
        BFS(k, v);
    }

    return 0;
}