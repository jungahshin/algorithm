// 열쇠
#include <string>
#include <queue>
#include <climits>
#include <cstring>
#include <vector>
#include <iostream>
 
using namespace std;
 
int testcase, h, w;
string s, tmp;
char map[105][105];
int visited[105][105] = { 0, };
int key = 0; // 열쇠 소유 상태(bitmask)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
 
bool check(char c) {
    if ('A' <= c && c <= 'Z') {
        if (((1<<(c-'A')) & key) != 0) {
            return true;
        }
    }
 
    return false;
}
 
int move()
{
    // 가장자리 진입
    int ans = 0; // 획득할 수 있는 문서의 수
    queue<pair<int, int>> q;
 
    for (int i = 0; i <= w + 1; i++) {
        q.push(make_pair(0, i));
        q.push(make_pair(h + 1, i));
    }
 
    for (int i = 1; i <= h; i++) {
        q.push(make_pair(i, 0));
        q.push(make_pair(i, w + 1));
    }
 
    // 안으로 진입
    queue<pair<int, int>> door[27]; // 열지 못했던 문을 넣어준다.
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= h && 1 <= ny && ny <= w && !visited[nx][ny]) {
                char c = map[nx][ny];
                if (c == '*') continue;
                if (c == '$') { // 문서
                    visited[nx][ny] = true;
                    ans++;
                    q.push(make_pair(nx, ny));
                } else if (c == '.') { // 빈 공간
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                } else if ('a' <= c && c <= 'z') { // 열쇠
                    visited[nx][ny] = true;
                    key |= (1 << (c - 'a'));
                    q.push(make_pair(nx, ny));
 
                    // 이전의 문을 연다.
                    while (!door[c - 'a'].empty()) {
                        int x = door[c - 'a'].front().first;
                        int y = door[c - 'a'].front().second;
                        door[c - 'a'].pop();
                        q.push(make_pair(x, y));
                    }
                } else {
                    if (check(c)) { // 열 수 있는 문
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    } else { // 열 수 없는 문 -> 위치만 저장
                        door[c - 'A'].push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
 
    return ans;
}
 
int main()
{
    vector<int> ans;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        // 초기화
        key = 0;
        memset(visited, 0, sizeof(visited));
        
        cin >> h >> w;
        for (int j = 1; j <= h; j++) {
            cin >> s;
            for (int k = 0; k < s.size(); k++) {
                map[j][k+1] = s[k];
            }
        }
        cin >> tmp;
        if (tmp != "0") {
            for (int j = 0; j < tmp.size(); j++) {
                key |= (1<<(tmp[j] - 'a') );
            }
        }
 
        ans.push_back(move());
    }
 
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
 
    return 0;
}