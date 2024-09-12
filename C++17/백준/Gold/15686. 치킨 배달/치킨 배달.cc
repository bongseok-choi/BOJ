#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> selected;

int get_chicken_distance() {
    int total_distance = 0;
    for (const auto& house : houses) {
        int hx = house.first;
        int hy = house.second;
        int min_distance = INT_MAX;
        for (int i = 0; i < selected.size(); ++i) {
            if (selected[i]) {
                int cx = chickens[i].first;
                int cy = chickens[i].second;
                int distance = abs(hx - cx) + abs(hy - cy);
                if (distance < min_distance) {
                    min_distance = distance;
                }
            }
        }
        total_distance += min_distance;
    }
    return total_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> city(N, vector<int>(N));
    chickens.clear();
    houses.clear();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                houses.emplace_back(i, j);
            } else if (city[i][j] == 2) {
                chickens.emplace_back(i, j);
            }
        }
    }

    int chicken_count = chickens.size();
    selected.resize(chicken_count, 0);
    for (int i = 0; i < M; ++i) {
        selected[i] = 1;
    }

    sort(selected.begin(), selected.end());
    int min_chicken_distance = INT_MAX;

    do {
        int distance = get_chicken_distance();
        if (distance < min_chicken_distance) {
            min_chicken_distance = distance;
        }
    } while (next_permutation(selected.begin(), selected.end()));

    cout << min_chicken_distance << '\n';

    return 0;
}
