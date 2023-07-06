#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

// 16235 - 나무 재테크
struct Tree{
    int age, y, x;
};
int n, m, k;
int idx = 0;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<Tree>> tree; // 나무의 정보
vector<vector<int>> grid, supply; // 기본 땅, 겨울마다 양분 공급

void input(){
    cin >> n >> m >> k;

    tree.assign(2, vector<Tree>{});
    grid.assign(n , vector<int> (n, 5));
    supply.assign(n , vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cin >> supply[i][k];
        }
    }

    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> y >> x >> z;
        Tree tmp = {z, y - 1, x - 1};
        tree[idx].emplace_back(tmp);
    }
}

bool compare(const struct Tree &t1, const struct Tree &t2){
    return t1.age < t2.age;
}

bool isInside(int y, int x){
    return (0 <= x && x < n) && (0 <= y && y < n);
}

void summer(vector<Tree> &now, vector<Tree> &next){
    // 봄에 죽은 나무가 나이/2만큼 해당 땅에 양분을 제공한다.
    for(int i = 0; i < now.size(); i++){
        if(now[i].age < 0){ // 죽은 나무라면 양분 추가
            grid[now[i].y][now[i].x] += -now[i].age / 2;
        }
        else{
            next.emplace_back(now[i]);
        }
    }
}

void winter(){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            grid[i][k] += supply[i][k];
        }
    }
}

void Cycle(){
    vector<Tree> &now = tree[idx];
    vector<Tree> &next = tree[1 - idx];
    next.clear();

    // 봄 : 모든 나무가 있는 위치에 양분이 충분히 있다면 나무가 자라고, 양분이 없다면 나무가 죽는다.
    for(int i = 0; i < now.size(); i++){
        int cy = now[i].y;
        int cx = now[i].x;

        if(now[i].age <= grid[cy][cx]){ // 양분이 충분할 때
            grid[cy][cx] -= now[i].age;
            now[i].age++;

            if(now[i].age % 5 == 0){ // 나이가 5의 배수일 때에만 번식
                for(int k = 0; k < 8; k++){ // 가을에 태어날 나무들 미리 push
                    int ny = cy + dy[k];
                    int nx = cx + dx[k];
                    if(isInside(ny, nx)){
                        next.push_back({1, ny, nx});
                    }
                }
            }
        }
        else{ // 양분이 충분하지 않을 때 죽은 나무로 표시한다.
            now[i].age = -now[i].age;
        }
    }

    summer(now, next);
    winter();

    idx = 1 - idx;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    sort(tree[idx].begin(), tree[idx].end(), compare);
    while(k--){
        Cycle();
    }

    cout << tree[idx].size();

    return 0;
}