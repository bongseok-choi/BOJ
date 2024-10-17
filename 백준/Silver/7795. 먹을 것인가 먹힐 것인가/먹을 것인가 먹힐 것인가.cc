#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색을 통해 B에서 A의 원소보다 작은 원소의 개수를 찾는 함수
int countLessThan(const vector<int>& B, int value) {
    // lower_bound를 사용하여 value보다 작은 원소들의 개수를 찾음
    return lower_bound(B.begin(), B.end(), value) - B.begin();
}

int main() {
    int T;
    cin >> T; // 테스트 케이스의 개수
    
    while (T--) {
        int N, M;
        cin >> N >> M; // A의 크기와 B의 크기
        
        vector<int> A(N), B(M);
        
        // A와 B 입력 받기
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }
        
        // A와 B 정렬
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int result = 0;
        
        // A의 각 원소에 대해 B에서 자신보다 작은 원소의 개수를 찾음
        for (int i = 0; i < N; i++) {
            result += countLessThan(B, A[i]);
        }
        
        cout << result << endl; // 결과 출력
    }
    
    return 0;
}
