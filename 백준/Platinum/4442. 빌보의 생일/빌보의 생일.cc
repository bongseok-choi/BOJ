#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define ll long long

const int mxN=1e5+10;
int n;
vector<ll> arr, tree;
unordered_map<string, int> mp; 

ll sum(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];

    int mid = start + (end-start)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
    if(index < start || end < index) return;

    tree[node] += diff;
    if(start == end) return;

    int mid = start + (end-start)/2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}

void Init() {
    arr.clear();
    tree.clear();
    mp.clear();
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> n;
        if(n==0) break;
        arr.resize(n); tree.resize(4*n);

        Init();

        for(int i=0; i<n; i++) {
            string s; cin >> s;
            mp.insert({s, i});
        }

        for(int i=0; i<n; i++) {
            string s; cin >> s;

            auto it = mp.find(s);
            arr[i] = it->second;
        }

        ll ans=0;
        for(int i=0; i<n; i++) {
            int now = arr[i];
            ans += sum(0, n-1, 1, now+1, n-1);
            update(0, n-1, 1, now, 1);
        }

        cout << ans << "\n";
    }
}