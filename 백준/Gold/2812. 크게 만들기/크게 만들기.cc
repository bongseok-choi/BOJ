#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

#define INF 987654321
#define MAX 1000000 + 1
using namespace std;

// 2812 - 크게 만들기
int n, k;
vector<int> nums;
deque<int> dq;

void input(){
    scanf("%d %d", &n, &k);
    nums.assign(n, 0);

    for(int i = 0; i < n; i++){
        scanf("%1d", &nums[i]);
    }
}

void solve(){
    for(int i = 0; i < n; i++){
    	// 아직 k개를 모두 제거하지 않았으며 & 자신보다 더 작은 수가 앞에 존재한다면
        while(!dq.empty() && k && dq.back() < nums[i]){
            k--;
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }
}

void printAnswer(){
    for(int i = 0; i < dq.size() - k; i++){
        printf("%d", dq[i]);
    }
}

int main(){

    input();
    solve();
    printAnswer();

    return 0;
}