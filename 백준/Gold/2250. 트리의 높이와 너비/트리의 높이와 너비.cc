#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

// 2250 - 트리의 높이와 너비
struct Node{
    int left, right;
};
int n, col = 1, result_width, result_level;
vector<Node> graph; // node의 left, right child
vector<int> isVisited; // root를 구하기 위한 배열 (자식 노드 번호에 해당하는 값++)
vector<vector<int>> grid; // 각 노드에 해당하는 행과 열 정보 저장

void input(){
    cin >> n;
    graph.assign(n + 1, {});
    isVisited.assign(n + 1, 0);
    for(int i = 0; i < n; i++){
        int n, l, r;
        cin >> n >> l >> r;
        graph[n] = {l, r};

        // 들어오는 간선 체크
        if(l != -1) isVisited[l]++;
        if(r != -1) isVisited[r]++;
    }
}

// 중위 순회를 통해서 각 노드의 열과 행의 위치를 찾고, grid 배열에 입력
void inOrder(int cur, int level){
    if(cur == -1)   return;

    inOrder(graph[cur].left, level + 1);

    if(grid.size() <= level) grid.resize(level + 1);
    grid[level].emplace_back(col++);

    inOrder(graph[cur].right, level + 1);
}

// 각 레벨마다 열을 정렬해서 너비를 구하고, 최대 너비와 레벨을 구한다.
void getMaxWidth(){
    int width = 0;
    for(int i = 1; i < grid.size(); i++){
        sort(grid[i].begin(), grid[i].end());
        width = grid[i][grid[i].size() - 1] - grid[i][0] + 1;

        if(width > result_width){
            result_width = width;
            result_level = i;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();

    int root = 0;
    for(int i = 1; i <= n; i++){
        if(isVisited[i] == 0){
            root = i;
            break;
        }
    }
    inOrder(root, 1);
    getMaxWidth();

    cout << result_level << " " << result_width;

    return 0;
}