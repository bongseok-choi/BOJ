#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int num;
    cin >> num;
    vector<pair<long,long>> arr;
    pair<long,long> tmp;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}