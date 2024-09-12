#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    // 1층은 1개의 방으로 시작
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // 방의 범위 계산
    long long layer = 1; // 현재 층
    long long max_room_in_layer = 1; // 각 층의 마지막 방 번호

    while (N > max_room_in_layer) {
        layer++;
        max_room_in_layer += 6 * (layer - 1); // k층의 마지막 방 번호는 이전 층의 마지막 방 번호 + 6 * (layer - 1)
    }

    cout << layer << endl;
    return 0;
}
