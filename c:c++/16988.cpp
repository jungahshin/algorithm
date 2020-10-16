#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int baduk[23][23] = { 0, };
int visited[401] = { 0, };
vector<pair<int, int>> v;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1};
int ans = 0;

void bfs()
{
	int visited2[23][23] = { 0, };
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (baduk[i][j] == 2 && !visited2[i][j]) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));

				bool check = false;
				int cnt = 1; // 2의 개수

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					visited2[x][y] = 1;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited2[nx][ny]) {
							if (baduk[nx][ny] == 2) {
								visited2[nx][ny] = 1;
								cnt++;
								q.push(make_pair(nx, ny));
							}
							else if (baduk[nx][ny] == 0) { // 2가 0과 접하면 무조건 성립 x
								check = true;
							}
						}
					}
				}

				if (check == true) {
					cnt = 0;
				}

				total += cnt;
			}
		}
	}

	ans = max(ans, total);
}

void choose(int idx, int num)
{
	if (num == 2) {
		for (int i = 0; i < v.size(); i++) {
			if (visited[i] == true) {
				baduk[v[i].first][v[i].second] = 1;
			}
		}

		bfs();

		for (int i = 0; i < v.size(); i++) {
			if (visited[i] == true) {
				baduk[v[i].first][v[i].second] = 0;
			}
		}
        
        return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (visited[i] == true) continue;
		visited[i] = true;

		choose(i, num + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> baduk[i][j];
			if (baduk[i][j]==0){
				v.push_back(make_pair(i, j));
			}
		}
	}

	choose(0, 0);

	cout << ans << "\n";
	return 0;
}