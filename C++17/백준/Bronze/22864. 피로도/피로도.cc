#include <iostream>
using namespace std;

int main() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int current_fatigue = 0;  // 초기 피로도는 0
    int total_work_done = 0;  // 총 처리한 일의 양

    for (int hour = 0; hour < 24; ++hour) {
        if (current_fatigue + A <= M) {
            // 피로도가 최대 M을 넘지 않을 경우 일하기
            current_fatigue += A;
            total_work_done += B;
        } else {
            // 피로도가 최대 M을 넘을 경우 쉬기
            current_fatigue -= C;
            if (current_fatigue < 0) current_fatigue = 0;
        }
    }

    cout << total_work_done << endl;
    return 0;
}
