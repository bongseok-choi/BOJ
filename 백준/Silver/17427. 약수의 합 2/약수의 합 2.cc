#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define INF 10000000000000
using namespace std;

// 17427 - 약수의 합 2
int n;
long long result = 0;


void input(){
    cin >> n;
}

void solve(){
    //각 숫자가 나오는 횟수는 n에서 각 숫자를 나눈 후의 몫만큼 등장한다.
    for(int i = 1; i <= n; ++i){
        result += (n / i) * i;
    }
    cout << result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}