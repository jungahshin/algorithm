#include <iostream>
#include <vector>
using namespace std;
 
int n;
int map[500][500] = {0, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<pair<int, int>, int>> rate[4];
int total = 0; // 격자 밖으로 나간 모래의 양
 
void setting()
{
    rate[0].push_back(make_pair(make_pair(-1, 1), 1));
    rate[0].push_back(make_pair(make_pair(1, 1), 1));
    rate[0].push_back(make_pair(make_pair(-1, 0), 7));
    rate[0].push_back(make_pair(make_pair(1, 0), 7));
    rate[0].push_back(make_pair(make_pair(-2, 0), 2));
    rate[0].push_back(make_pair(make_pair(2, 0), 2));
    rate[0].push_back(make_pair(make_pair(-1, -1), 10));
    rate[0].push_back(make_pair(make_pair(1, -1), 10));
    rate[0].push_back(make_pair(make_pair(0, -2), 5));
 
    rate[1].push_back(make_pair(make_pair(-1, -1), 1));
    rate[1].push_back(make_pair(make_pair(-1, 1), 1));
    rate[1].push_back(make_pair(make_pair(0, -1), 7));
    rate[1].push_back(make_pair(make_pair(0, 1), 7));
    rate[1].push_back(make_pair(make_pair(0, -2), 2));
    rate[1].push_back(make_pair(make_pair(0, 2), 2));
    rate[1].push_back(make_pair(make_pair(1, -1), 10));
    rate[1].push_back(make_pair(make_pair(1, 1), 10));
    rate[1].push_back(make_pair(make_pair(2, 0), 5));
 
    rate[2].push_back(make_pair(make_pair(-1, -1), 1));
    rate[2].push_back(make_pair(make_pair(1, -1), 1));
    rate[2].push_back(make_pair(make_pair(-1, 0), 7));
    rate[2].push_back(make_pair(make_pair(1, 0), 7));
    rate[2].push_back(make_pair(make_pair(-2, 0), 2));
    rate[2].push_back(make_pair(make_pair(2, 0), 2));
    rate[2].push_back(make_pair(make_pair(-1, 1), 10));
    rate[2].push_back(make_pair(make_pair(1, 1), 10));
    rate[2].push_back(make_pair(make_pair(0, 2), 5));
 
    rate[3].push_back(make_pair(make_pair(1, -1), 1));
    rate[3].push_back(make_pair(make_pair(1, 1), 1));
    rate[3].push_back(make_pair(make_pair(0, -1), 7));
    rate[3].push_back(make_pair(make_pair(0, 1), 7));
    rate[3].push_back(make_pair(make_pair(0, -2), 2));
    rate[3].push_back(make_pair(make_pair(0, 2), 2));
    rate[3].push_back(make_pair(make_pair(-1, -1), 10));
    rate[3].push_back(make_pair(make_pair(-1, 1), 10));
    rate[3].push_back(make_pair(make_pair(-2, 0), 5));
}
 
void move(int x, int y, int dir)
{
    int num = map[x][y]; // 기존 모래의 양
    int temp = 0; // (num-temp)가 알파에게 줄 모래의 양
    map[x][y] = 0;
    for(int i=0; i<rate[dir].size(); i++){
        int nx = x+rate[dir][i].first.first;
        int ny = y+rate[dir][i].first.second;
        int NUM = num*((float)rate[dir][i].second/100);
        temp += NUM;
        if(0<=nx && nx<n && 0<=ny && ny<n){
            map[nx][ny] += NUM;
        }else{
            total += NUM;
        }
    }
 
    // 남은 모래양은 알파 자리에 더해준다.
    int nx, ny;
    if(dir==0){
        nx = x;
        ny = y-1;
    }else if(dir==1){
        nx = x+1;
        ny = y;
    }else if(dir==2){
        nx = x;
        ny = y+1;
    }else{
        nx = x-1;
        ny = y;
    }
    if(0<=nx && nx<n && 0<=ny && ny<n){
        map[nx][ny] += (num-temp);
    }else{
        total += (num-temp);
    }
}
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
 
    int x = n/2, y = n/2;
    int num = 1;
    int cnt = 0;
    int dir = 0;
 
    setting();
 
    while(1){
        if(x==0 && y==0){
            break;
        }
        cnt++;
        for(int i=0; i<num; i++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                move(nx, ny, dir);
            }
            x = nx, y = ny;
        }
 
        if(cnt==2 && num!=n-1){
            cnt = 0;
            num++;
        }
        dir = (dir+1)%4;
    }
 
    cout<<total<<"\n";
    return 0;
}