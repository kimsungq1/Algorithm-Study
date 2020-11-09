//BOJ-2667
#include <iostream>
#include <queue>
using namespace std;
int a[25][25];
int d[25][25];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int ans[25 * 25];
int n;
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[d[i][j]] += 1;
		}
	}
	cout << cnt << "\n";
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
