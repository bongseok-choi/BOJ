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

// 4256 - 트리
vector<int> preorder, inorder;
vector<int> idx;


void input(int& n){
    cin >> n;
    preorder.assign(n + 1, 0);
    inorder.assign(n + 1, 0);
    idx.assign(n + 1, 0);

    for(int i = 1; i <= n; i++){
        cin >> preorder[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> inorder[i];
        idx[inorder[i]] = i; // 몇 번째 인덱스에 있는지 저장
    }
}

void get_postorder(int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start > pre_end || in_start > in_end)    return;

    int root_num = preorder[pre_start]; // 전위 순회는 루트 노드가 제일 앞에 위치
    int root_idx = idx[root_num]; // 루트 노드가 inorder 배열에서 몇 번째에 위치하는지 확인
    int left_size = root_idx - in_start; // 왼쪽 서브 트리의 크기가 얼마나 되는지 확인

    // search left subtree
    get_postorder(pre_start + 1, pre_start + left_size, in_start, root_idx - 1);
    // search right subtree
    get_postorder(pre_start + left_size + 1, pre_end, root_idx + 1, in_end);
    cout << root_num << ' ';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase = 0;
    cin >> testcase;

    while(testcase--){
        int n = 0;
        input(n);
        get_postorder(1, n, 1, n);

        cout << '\n';
    }

    return 0;
}