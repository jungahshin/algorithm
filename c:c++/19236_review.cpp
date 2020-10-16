// 청소년 상어
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, shark_x, shark_y, shark_dir;
int ans = 0;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
// pair<int, int> fish[17]; // 물고기들의 위치

struct FISH {
	int x, y, dir;
	bool die;
};

void copy(pair<int, int> a[5][5], pair<int, int> b[5][5]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = make_pair(b[i][j].first, b[i][j].second);
		}
	}
}

void copy2(FISH a[17], FISH b[17])
{
	for (int i = 1; i <= 16; i++) {
		a[i].x = b[i].x;
		a[i].y = b[i].y;
		a[i].dir = b[i].dir;
		a[i].die = b[i].die;
	}
}


void dfs(int shark_x, int shark_y, int shark_dir, FISH f[17], pair<int, int> s[5][5], int eat) {
	pair<int, int> sea[5][5];
	FISH fish[17];
	copy(sea, s);
	copy2(fish, f);
    
	// 상어 자리에 있던 물고기 죽이기
	fish[sea[shark_x][shark_y].first].die = 1;
	// sea 위치 빈칸으로 만들기
	sea[shark_x][shark_y] = make_pair(0, 0);

	// 물고기 이동하기
	for (int i = 1; i <= 16; i++) {
		if (fish[i].die == 1) continue;
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;
		int nx = x + dx[dir - 1];
		int ny = y + dy[dir - 1];
		int temp = 0;
		bool check = false;

		while ((0 > nx || nx >= 4 || 0 > ny || ny >= 4) || (nx == shark_x && ny == shark_y)) {
			temp++;
			if (temp == 8) {
				check = true;
				break;
			}
			dir++;
			if (dir == 9) {
				dir = 1;
			}
			nx = x + dx[dir - 1];
			ny = y + dy[dir - 1];
		}

		// (x, y)와 (nx, ny) 물고기 위치 바꿔주기
		if (check == false) {
			int num = i;
			int next_num = sea[nx][ny].first;
			int next_dir = sea[nx][ny].second;

			sea[x][y] = make_pair(next_num, next_dir);
			sea[nx][ny] = make_pair(num, dir);

			fish[num].x = nx;
			fish[num].y = ny;
			fish[num].dir = dir;

			fish[next_num].x = x;
			fish[next_num].y = y;
		}
	}
    
	int nx = shark_x + dx[shark_dir - 1];
	int ny = shark_y + dy[shark_dir - 1];

	while (0 <= nx && nx < 4 && 0 <= ny && ny < 4) { // 칸안에 있고 빈칸이 아닐때
		if (sea[nx][ny].first != 0) {
			dfs(nx, ny, sea[nx][ny].second, fish, sea, eat+sea[nx][ny].first);
		}
		nx += dx[shark_dir - 1];
		ny += dy[shark_dir - 1];
	}

	ans = max(ans, eat);
}

int main()
{
	FISH fish[17];
	pair<int, int> sea[5][5]; // 위치에 따른 물고기 번호와 방향
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			sea[i][j] = make_pair(a, b);
			fish[a].x = i;
			fish[a].y = j;
			fish[a].dir = b;
			fish[a].die = 0;
		}
	}

	// (0, 0)자리의 물고기를 먹고 상어가 들어간다.
	shark_x = 0;
	shark_y = 0;
	shark_dir = sea[0][0].second;
	dfs(shark_x, shark_y, shark_dir, fish, sea, sea[0][0].first);
	
	cout << ans << "\n";
	return 0;
}