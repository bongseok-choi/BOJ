#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16], P[16];
int dp[16];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // DP 배열 초기화
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 > N) {
            // 현재 상담을 할 수 없는 경우
            dp[i] = dp[i+1];
        } else {
            // 상담을 할 수 있는 경우와 안하는 경우 중 큰 값을 선택
            dp[i] = max(dp[i+1], P[i] + dp[i + T[i]]);
        }
    }
    
    // 첫 번째 날부터 시작했을 때의 최대 이익 출력
    cout << dp[1] << endl;
    
    return 0;
}
