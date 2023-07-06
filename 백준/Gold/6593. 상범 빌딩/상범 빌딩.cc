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

// 6593 - 상범 빌딩
struct info{
    int z, y, x, time;
};
int l, r, c, result = 0;
int dx[6] = {-1, 0, 1, 0, 0, 0}, dy[6] = {0, -1, 0, 1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};
vector<vector<vector<char>>> building;
queue<info> q;

void input(){
    for(int floor = 0; floor < l; floor++){

        for(int i = 0; i < r; i++){
            for(int k = 0; k < c; k++){
                cin >> building[floor][i][k];
                if(building[floor][i][k] == 'S'){
                    q.push({floor, i, k, 0});
                }
            }
        }
    }
}

bool isInside(int x, int y, int z){
    return (0 <= x && x < c) && (0 <= y && y < r) && (0 <= z && z < l);
}

void BFS(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i = 0; i < 6; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            if(isInside(nx, ny, nz) && building[nz][ny][nx] == 'E'){
                result = cur.time + 1;
                return;
            }
            if(isInside(nx, ny, nz) && building[nz][ny][nx] == '.'){
                q.push({nz, ny, nx, cur.time + 1});
                building[nz][ny][nx] = 'x'; // 방문 표시
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)  return 0;

        building.assign(l, vector<vector<char>>(r, vector<char>(c, 0)));
        result = 0;
        while(!q.empty())   q.pop();

        input();
        BFS();
        if(result != 0){
            cout << "Escaped in " << result <<" minute(s).\n";
        }
        else{
            cout << "Trapped!\n";
        }
    }

    return 0;
}