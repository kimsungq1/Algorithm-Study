//1260 - DPS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
bool check[1001];
vector<int> v[1001];

void dfs(int now) {
	check[now] = true;
	cout << now << ' ';
	//vector의 size함수로 나온 결과값 int와 바로 비교시 에러
	//형변환 해주기
	for (int i = 0; i < (int)v[now].size(); i++) {
		int next = v[now][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start); check[start] = 1;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		cout << node << ' ';
		for (int i = 0; i < (int)v[node].size(); i++) {
			int next = v[node][i];
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	int x, y, z, a, b;
	cin >> x >> y >> z;

	for (int i = 0; i < y; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < x; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(z);
	puts("");
	memset(check, false, sizeof(check));
	bfs(z);
	puts("");
}