#include <bits/stdc++.h>
using namespace std;

const int mxN=50;
int n, m, a[mxN+1][mxN+1];
bool vis[mxN+1][mxN+1];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

//bool e(int i, int j) {
//	return i>=0 && i<n && j>=0 && j<m && a[i][j] == 1;
//}

void dfs(int i, int j) {
	vis[i][j] = true;
	
	for(int k=0; k<8; k++) {
		int nx = i+dx[k];
		int ny = j+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m) {
			if(a[nx][ny]==1 && !vis[nx][ny]) {
				dfs(nx, ny);
			} 		
		}
	}
}

int main() {
	while(true) {
		cin >> m >> n;
		if(m==0 && n==0) return 0;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> a[i][j];
			}
		}
	
		memset(vis, 0, sizeof(vis));
		
		int ans=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]==1 && !vis[i][j]) {
					dfs(i, j), ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}