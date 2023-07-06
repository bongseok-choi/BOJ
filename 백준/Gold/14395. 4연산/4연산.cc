#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>

#define INF 10000000000000
using namespace std;

// 14395 - 4연산
int s, t;
string result;
bool flag = false;

void input(){
    cin >> s >> t;
}

void solve(){
    unordered_set<long long> hashmap;
    queue<pair<long long, string>> q;
    q.push({s, ""});

    while(!q.empty()){
        long long cur = q.front().first;
        string str = q.front().second;
        q.pop();

        if(cur == t){
            flag = true;
            result = str;
            return;
        }
        long long next = cur * cur;
        if(hashmap.find(next) == hashmap.end()){
            hashmap.insert(next);
            q.push({cur * cur, str + "*"});
        }
        next = cur + cur;
        if(hashmap.find(next) == hashmap.end()){
            hashmap.insert(next);
            q.push({cur + cur, str + "+"});
        }
        next = cur - cur;
        if(hashmap.find(next) == hashmap.end()){
            hashmap.insert(next);
            q.push({cur - cur, str + "-"});
        }

        if(cur != 0){
            next = cur / cur;
            if(hashmap.find(next) == hashmap.end()){
                hashmap.insert(next);
                q.push({cur / cur, str + "/"});
            }
        }

    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    if(s == t){
        cout << "0";
    }
    else{
        solve();
        if(flag){
            cout << result;
        }
        else{
            cout << "-1";
        }
    }


    return 0;
}