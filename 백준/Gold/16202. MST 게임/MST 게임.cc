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

// 16202 - MST 게임
struct Edge{
    int node[2], dist;
    bool isSelected;

    Edge(int a, int b, int dist, bool isSelected){
        this->node[0] = a;
        this->node[1] = b;
        this->dist = dist;
        this->isSelected = isSelected;
    }
    bool operator < (Edge edge){
        return this->dist < edge.dist;
    }
};
int n, m, k; // 노드의 개수, 간선의 개수, 턴의 개수
int sum = 0, idx = 0;
vector<int> parent;
vector<Edge> graph;


void input(){
    cin >> n >> m >> k;
    parent.assign(n + 1, 0);

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        graph.emplace_back(a, b, i, false);
    }
}

void initParent(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

int getParent(int x){
    if(x == parent[x])  return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b)   parent[b] = a;
    else    parent[a] = b;
}

bool isParentSame(int a, int b){
    a = getParent(a);
    b = getParent(b);
    return a == b;
}

void kruskal(){
    int min_dist = INF;
    sum = 0;

    for(int i = 0; i < graph.size(); i++){
        if(!isParentSame(graph[i].node[0], graph[i].node[1]) && !graph[i].isSelected){
            if(min_dist > graph[i].dist){
                min_dist = graph[i].dist;
                idx = i;
            }
            sum += graph[i].dist;
            unionParent(graph[i].node[0], graph[i].node[1]);
        }
    }

    graph[idx].isSelected = true;
}

bool isAllConnected(){
    // 모든 정점의 parent가 제대로 갱신이 안되어있을수도 있으니 갱신을 한 차례 해준다.
    for(int i = 1; i <= n; i++){
        getParent(i);
    }

    int base = parent[1];
    for(int i = 2; i <= n; i++){
        if(base != parent[i])   return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    sort(graph.begin(), graph.end());

    bool flag = false;
    while(k--){
        // 1. MST가 제대로 생성되었는지의 여부 확인 필요 : parent의 값이 모두 같아야 한다
        // 2. MST가 만들어졌다면 MST를 구성하는 간선 중 가중치가 제일 작은 간선 삭제 필요 : kruskal 알고리즘
        if(!flag){
            initParent();
            kruskal();

            if(isAllConnected()){
                cout << sum << " ";
            }
            else{
                flag = true;
                cout << "0 ";
            }
        }
        else{
            cout << "0 ";
        }
    }

    return 0;
}