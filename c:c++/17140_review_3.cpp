// 이차원 배열과 연산
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 구해보자.

int r, c, k, R, C;
int a[101][101] = { 0, };
int ans = 0;
bool check = true;

int main()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	R = 3;
	C = 3;
	
	while (a[r][c] != k) {
		ans++;
		if (ans > 100) {
			check = false;
			break;
		}

		if (R >= C) { // R연산
			int temp_r = 0; // 최대 열의 길이 저장
			for (int i = 1; i <= R; i++) { // 행기준
				int temp[101] = { 0, };
				for (int j = 1; j <= C; j++) {
					temp[a[i][j]]++;
					a[i][j] = 0; // a도 같이 0으로 초기화
				}
				vector<pair<int, int>> v; // 등장 횟수, 수
				for (int j = 1; j <= 100; j++) {
					if (temp[j] > 0) {
						v.push_back(make_pair(temp[j], j));
					}
				}
				sort(v.begin(), v.end());


				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					a[i][idx++] = v[j].second; // 수
					if (idx > 100) {
						break;
					}
					a[i][idx++] = v[j].first; // 등장 횟수
					if (idx > 100) {
						break;
					}
				}
				int size = v.size()*2;
				temp_r = max(temp_r, size);
			}
			C = temp_r;
		}
		else { // C연산
			int temp_c = 0; // 최대 행의 길이 저장
			for (int i = 1; i <= C; i++) { // 열기준
				int temp[101] = { 0, };
				for (int j = 1; j <= R; j++) {
					temp[a[j][i]]++;
					a[j][i] = 0; // a도 같이 0으로 초기화
				}
				vector<pair<int, int>> v; // 등장 횟수, 수
				for (int j = 1; j <= 100; j++) {
					if (temp[j] > 0) {
						v.push_back(make_pair(temp[j], j));
					}
				}
				sort(v.begin(), v.end());

				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					a[idx++][i] = v[j].second; // 수
					if (idx > 100) {
						break;
					}
					a[idx++][i] = v[j].first; // 등장 횟수
					if (idx > 100) {
						break;
					}
				}
				int size = v.size() * 2;
				temp_c = max(temp_c, size);
			}
			R = temp_c;
		}
	}

	if (check == false) {
		cout << "-1" << "\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}