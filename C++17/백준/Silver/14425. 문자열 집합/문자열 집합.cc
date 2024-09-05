#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<string> S;  // 집합 S
    string str;

    // N개의 문자열을 입력받아 집합 S에 저장
    for (int i = 0; i < N; i++) {
        cin >> str;
        S.insert(str);
    }

    int count = 0;

    // M개의 문자열을 입력받아 S에 있는지 확인
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (S.find(str) != S.end()) {
            count++;
        }
    }

    // 결과 출력
    cout << count << endl;

    return 0;
}
