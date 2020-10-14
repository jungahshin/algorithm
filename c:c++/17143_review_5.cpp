// 낚시왕
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int R, C, M, r, c, s, d, z;
vector<tuple<int, int, int>> shark[101][101];
int ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
// int die[10001] = { 0, }; // 죽은 상어의 여부

void play()
{
	int idx = 0; // 현재 낚시왕의 위치
	while (1) {
		idx++;
		if (idx > C) { // 열보다 한칸 뒤에 간다면
			break;
		}

		// 낚시왕이 가까운 상어를 잡는다.
		for (int i = 1; i <= R; i++) {
			if (shark[i][idx].size() == 0) continue;
			int size, speed, dir;
			tie(size, speed, dir) = shark[i][idx][0];
			ans += size;
			shark[i][idx].clear();
			break;
		}

		vector<tuple<int, int, int>> v[101][101];

		// 상어 이동하기
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (shark[i][j].size() == 0) continue;
				int size, speed, dir;
				tie(size, speed, dir) = shark[i][j][0];
				int nx = i;
				int ny = j;
				int speed_temp = speed;

				if (dir == 1 || dir == 2) {
					speed_temp %= (2*R - 2);
				}
				else if (dir == 3 || dir == 4) {
					speed_temp %= (2*C - 2);
				}

				for (int k = 0; k < speed_temp; k++) { // 속력만큼 이동한다.
					nx += dx[dir-1];
					ny += dy[dir-1];
					if (1 > nx || nx > R || 1 > ny || ny > C) {
						nx -= dx[dir - 1];
						ny -= dy[dir - 1];
						if (dir == 1) {
							dir = 2;
						}
						else if (dir == 2) {
							dir = 1;
						}
						else if (dir == 3) {
							dir = 4;
						}
						else if (dir == 4) {
							dir = 3;
						}
						nx += dx[dir - 1];
						ny += dy[dir - 1];
					}
				}

				// 상어의 정보 update하기
				// 원래 자리 clear & 새로운 자리 넣기
				v[nx][ny].push_back(make_tuple(size, speed, dir));
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (v[i][j].size() > 0) {
					sort(v[i][j].begin(), v[i][j].end());
					int size, speed, dir;
					tie(size, speed, dir) = v[i][j][v[i][j].size() - 1];

					v[i][j].clear();
					v[i][j].push_back(make_tuple(size, speed, dir));
				}
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (shark[i][j].size() > 0) {
					shark[i][j].clear();
				}

				if (v[i][j].size() > 0) {
					int size, speed, dir;
					tie(size, speed, dir) = v[i][j][0];
					shark[i][j].push_back(make_tuple(size, speed, dir));
				}
			}
		}
	}

}

int main()
{
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		shark[r][c].push_back(make_tuple(z, s, d));

	}

	if (M == 0) {
		cout << ans << "\n";
		return 0;
	}

	play();

	cout << ans << "\n";
	return 0;
}