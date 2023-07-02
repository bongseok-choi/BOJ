#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, k;
int vis[100003]; // 각 점에 도달하는 최단 시간을 기록
int result = 987654321; // 결과값
void bfs(int a){
    queue<pair<int, int>> q; // <위치, 시간>
    q.push(make_pair(a, 0)); // <초기위치, 0초>
    while(!q.empty()){
        int x = q.front().first; // 현재 위치
        int cnt = q.front().second; // 현재 위치까지 걸린 시간
        q.pop();
        if (x == k){ // 도착 지점 도달 시
            if(result > cnt) // 최단 시간일 경우 기록
                result = cnt;
        }else if (result < cnt){ // 기록된 결과을 넘은 시간인 경우 pass
            continue;
        }
        else{
            for (int i = -1; i <= 1;i++){ 
                int nx; // 다음 위치
                if (i == 0) // 순간이동한 경우
                    nx = 2 * x;
                else // 걷는 경우
                    nx = x + i;
            
                if(nx >= 0 && nx <= 100000){ // 일직성 상 범위 준수
                    // 순간이동을 하면 초가 변하지 않으므로 현재까지 걸린
                    // 시간이 다음 위치에 기록된 시간보다 적으면 
                    // 그것이 최단 시간이 됨.(-1 경우는 한번도 방문 안함)
                    if(i == 0 && (vis[nx] > cnt || vis[nx] == -1)){
                        q.push(make_pair(nx, cnt));
                        vis[nx] = cnt;
                    }// 걷는 경우 현재 시간에 +1 한 것이 더 작아야함.
                    else if(vis[nx] > cnt +1 || vis[nx]== -1){
                        q.push(make_pair(nx, cnt + 1));
                        vis[nx] = cnt + 1;
                    }
                }
            }
        }
    }
}
int main(){
    cin >> n >> k;
    memset(vis, -1, sizeof(vis)); // 0초인 경우도 있으니 -1로 초기화
    bfs(n);
    cout << result;
    return 0;
}
