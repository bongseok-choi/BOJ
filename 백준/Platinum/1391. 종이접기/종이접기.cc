#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin >> T;
    for (int _T = 0; _T < T; _T++){
        int n; cin >> n;
        int curri, previ; cin >> previ;
        int odd[2005], even[2005];

        for (int i = 0; i < n + 2; i++){
            odd[i] = 5000; even[i] = 5000; // 초기화
        }

        for (int i = 1; i < n; i++){
            cin >> curri;

            if (i % 2 == 0){
                even[max(previ, curri)] = i;
                even[min(previ, curri)] = -i;
            }
            else{
                odd[max(previ, curri)] = i;
                odd[min(previ, curri)] = -i;
            }

            previ = curri;
        }
        
        deque<int> d1, d2;
        bool imp = false;

        for (int i = 0; i < n + 2; i++){
            if (odd[i] > 0 && odd[i] < 2005){
                if (d1.front() + odd[i] != 0){
                    cout << "NO\n";
                    imp = true;
                    break;
                }
                d1.pop_front();
            }
            else if (odd[i] < 0){
                d1.push_front(odd[i]);
            }

            if (even[i] > 0 && even[i] < 2005){
                if (d2.front() + even[i] != 0){
                    cout << "NO\n";
                    imp = true;
                    break;
                }
                d2.pop_front();
            }
            else if (even[i] < 0){
                d2.push_front(even[i]);
            }
        }
        if (!imp) cout << "YES\n";
    }
}