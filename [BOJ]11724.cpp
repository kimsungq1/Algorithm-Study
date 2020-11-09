//BOJ-11724
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
int check[1001];

void dfs(int now) {
	check[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int node = v[now][i];
		if (check[node] == false) {
			dfs(node);
		}
	}
}

int main() {
	int n, m, x, y;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}