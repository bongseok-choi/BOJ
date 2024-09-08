#include <iostream>
using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    // E, S, M의 초기 값을 맞추기 위한 시작 연도
    int year = 1;

    // E, S, M의 주기에 맞추어 연도를 조정
    while (true) {
        if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
            cout << year << '\n';
            break;
        }
        year++;
    }

    return 0;
}
