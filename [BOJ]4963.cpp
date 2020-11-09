#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int a[51][51];
bool d[51][51];
int h, w;
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (d[nx][ny] == 0 && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%1d", &a[i][j]);
				d[i][j] = false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (d[i][j] == 0 && a[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}