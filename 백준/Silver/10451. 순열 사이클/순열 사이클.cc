#include<bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, to, adj[mxN];
bool vis[mxN];

void dfs(int u) {
	vis[u] = true;

	int next=adj[u];
	if(!vis[next]) {
		dfs(next);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> adj[i];
		}
		memset(vis, 0, sizeof(vis));
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				dfs(i), ans++;

			}
		}
		cout << ans << "\n";
	}
}