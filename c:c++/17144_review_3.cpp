// 미세먼지 안녕!
#include <iostream>
#include <deque>
using namespace std;

int r, c, t, upX, upY, downX, downY;
int room[51][51] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;

void spread()
{
	int temp[51][51] = { 0, };
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (room[i][j] == 0 || room[i][j]==-1)continue;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < r && 0 <= ny && ny < c) {
					if (room[nx][ny] >= 0) {
						cnt++;
						temp[nx][ny] += (room[i][j] / 5);
					}
				}
			}

			temp[i][j] += (room[i][j] - (room[i][j] / 5)*cnt);
		}
	}

	temp[upX][upY] = -1;
	temp[downX][downY] = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			room[i][j] = temp[i][j];
		}
	}
}

void move()
{
	// 위쪽 방향
	deque<int> dq;
	for (int i = 1; i < c; i++) {
		dq.push_back(room[upX][i]);
	}
	for (int i = upX-1; i >= 0; i--) {
		dq.push_back(room[i][c - 1]);
	}
	for (int i = c - 2; i >= 0; i--) {
		dq.push_back(room[0][i]);
	}
	for (int i = 1; i < upX; i++) {
		dq.push_back(room[i][0]);
	}

	dq.push_front(0);
	dq.pop_back();

	for (int i = 1; i < c; i++) {
		room[upX][i] = dq.front();
		dq.pop_front();
	}
	for (int i = upX - 1; i >= 0; i--) {
		room[i][c - 1] = dq.front();
		dq.pop_front();
	}
	for (int i = c - 2; i >= 0; i--) {
		room[0][i] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i < upX; i++) {
		room[i][0] = dq.front();
		dq.pop_front();
	}

	dq.clear();
	// 아래 방향
	for (int i = 1; i < c; i++) {
		dq.push_back(room[downX][i]);
	}
	for (int i = downX + 1; i < r; i++) {
		dq.push_back(room[i][c - 1]);
	}
	for (int i = c - 2; i >= 0; i--) {
		dq.push_back(room[r - 1][i]);
	}
	for (int i = r - 2; i > downX; i--) {
		dq.push_back(room[i][0]);
	}

	dq.push_front(0);
	dq.pop_back();

	for (int i = 1; i < c; i++) {
		room[downX][i] = dq.front();
		dq.pop_front();
	}
	for (int i = downX + 1; i < r; i++) {
		room[i][c - 1] = dq.front();
		dq.pop_front();
	}
	for (int i = c - 2; i >= 0; i--) {
		room[r - 1][i] = dq.front();
		dq.pop_front();
	}
	for (int i = r - 2; i > downX; i--) {
		room[i][0] = dq.front();
		dq.pop_front();
	}
}

void go()
{
	while (t--) {
		// 미세먼지 확산
		spread();

		// 공기청정기 작동
		move();
	}

}

int main()
{
	cin >> r >> c >> t;
	int temp = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				if (temp == 0) {
					upX = i;
					upY = j;
					temp++;
				}
				else if (temp == 1) {
					downX = i;
					downY = j;
				}
			}
		}
	}

	go();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (room[i][j] == -1) continue;
			ans += room[i][j];
		}
	}

	cout << ans << "\n";
	return 0;
}