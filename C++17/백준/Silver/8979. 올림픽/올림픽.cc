#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 국가 정보를 저장할 구조체 정의
struct Country {
    int id;  // 국가 ID
    int gold; // 금메달 수
    int silver; // 은메달 수
    int bronze; // 동메달 수
};

// 정렬을 위한 비교 함수
bool compare(const Country &a, const Country &b) {
    if (a.gold != b.gold) return a.gold > b.gold;
    if (a.silver != b.silver) return a.silver > b.silver;
    return a.bronze > b.bronze;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Country> countries(N);

    // 입력 받기
    for (int i = 0; i < N; ++i) {
        int id, gold, silver, bronze;
        cin >> id >> gold >> silver >> bronze;
        countries[i] = {id, gold, silver, bronze};
    }

    // 정렬
    sort(countries.begin(), countries.end(), compare);

    // 순위 계산
    int rank = 1;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && (countries[i].gold != countries[i - 1].gold ||
                       countries[i].silver != countries[i - 1].silver ||
                       countries[i].bronze != countries[i - 1].bronze)) {
            rank = i + 1;
        }
        if (countries[i].id == K) {
            cout << rank << endl;
            break;
        }
    }

    return 0;
}
