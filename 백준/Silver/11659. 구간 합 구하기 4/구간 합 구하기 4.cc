#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int su, quiz;
    cin >> su >> quiz;
    int S[100001] = {};

    for (int i = 1; i <= su; i++) {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    for (int i = 0; i < quiz; i++) {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << "\n";
    }
}