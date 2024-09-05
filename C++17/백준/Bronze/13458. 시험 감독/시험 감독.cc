#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;  // 시험장의 수

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];  // 각 시험장 응시자의 수
    }

    int B, C;
    cin >> B >> C;  // 총감독관과 부감독관이 감시할 수 있는 응시자의 수

    long long total_supervisors = 0;

    for (int i = 0; i < N; i++) {
        // 총감독관 한 명을 배치
        total_supervisors += 1;
        A[i] -= B;

        // 부감독관이 필요한 경우 계산
        if (A[i] > 0) {
            total_supervisors += (A[i] + C - 1) / C;  // 필요한 부감독관의 수 계산
        }
    }

    cout << total_supervisors << endl;

    return 0;
}
