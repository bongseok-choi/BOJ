#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> score(n);
    vector<int> dp(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    // 초기 조건 설정
    dp[0] = score[0];
    if (n > 1) dp[1] = score[0] + score[1];
    if (n > 2) dp[2] = max(score[0] + score[2], score[1] + score[2]);

    // DP 배열 채우기
    for (int i = 3; i < n; ++i) {
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }
    
    // 결과 출력
    cout << dp[n-1] << endl;

    return 0;
}
