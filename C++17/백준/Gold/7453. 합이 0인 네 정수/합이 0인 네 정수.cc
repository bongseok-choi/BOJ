#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<ll> A(n), B(n), C(n), D(n);
    for(int i=0; i<n; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        A[i] = a; B[i] = b; C[i] = c; D[i] = d;
    }
    vector<ll> AB, CD;
    ll cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ll res = A[i] + B[j];
            AB.push_back(res);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ll res = C[i] + D[j];
            CD.push_back(res);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    // 같은 값이 여러개일 경우, 갯수를 세줘야하므로 upper_bound를 사용한다.
    for(int i=0; i<AB.size(); i++) {
        ll preCD = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        ll refCD = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();

        if(AB[i] + CD[preCD] == 0) {
            cnt += refCD - preCD;
        }
    }

    cout << cnt;
}