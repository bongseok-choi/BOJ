#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> pokemon;
vector<string> pokemonSeq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q; 
    cin >> N >> Q;
    pokemonSeq.resize(N + 1); // 1-indexed 사용

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        pokemon[s] = i;
        pokemonSeq[i] = s;
    }
    
    while(Q--) {
        string s;
        cin >> s;
        if(isdigit(s[0])) {
            int idx = stoi(s);
            cout << pokemonSeq[idx] << '\n';
        }
        else {
            cout << pokemon[s] << '\n';
        }
    }

    return 0;
}
