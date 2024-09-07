#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count = 0;
    
    // 5kg 봉지를 최대한 많이 사용하면서 3kg으로 나눠떨어지는지 확인
    while (N >= 0) {
        if (N % 5 == 0) {  // 5kg 봉지로 나눠떨어지면
            count += N / 5;  // 5kg 봉지 개수 추가
            cout << count << endl;
            return 0;
        }
        N -= 3;  // 나눠떨어지지 않으면 3kg 봉지 하나 사용
        count++;  // 봉지 개수 증가
    }
    
    cout << -1 << endl;  // N을 만들 수 없을 경우
    return 0;
}
