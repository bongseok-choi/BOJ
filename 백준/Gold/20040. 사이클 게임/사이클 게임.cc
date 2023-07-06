#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX 1000000 + 1
using namespace std;

// 20040 - 사이클 게임
int n, m; // 점의 개수, 진행된 차례의 수
int result = 0;
vector<int> parent;


int getParent(int x){
    if(parent[x] == x)  return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b)   parent[b] = a;
    else    parent[a] = b;
}

void initParent(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

void solve(){
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        s = getParent(s);
        e = getParent(e);
        
        if(s == e){ // 부모가 같다는 뜻은 이미 이어진 그래프라는 뜻
            result = i + 1;
            return;
        }
        unionParent(s, e);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    parent.assign(n + 1, 0);
    initParent();
    solve();

    cout << result;

    return 0;
}