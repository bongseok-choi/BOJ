#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, ans = 0;
vector<int> K;

void backTracking(int num) {
    if (num > N)
        return;
    
    ans = max(ans, num);

    for (int i : K) {
        // 현재 num을 10배하고 K의 원소를 더해서 다음 숫자를 만듦
        num = num * 10 + i;
        backTracking(num);
        // 재귀 후 num 원래 상태로 복원
        num = (num - i) / 10;
    }
}

int main() {
    // 입력 처리
    cin >> N >> C;
    K.resize(C);
    
    for (int i = 0; i < C; i++) {
        cin >> K[i];
    }

    // 백트래킹 시작
    backTracking(0);

    // 결과 출력
    cout << ans << endl;

    return 0;
}
