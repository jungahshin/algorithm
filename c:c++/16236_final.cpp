//아기상어 원래짯던 코드에 bfs이용해서 해보기!!!
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <tuple>
using namespace std;

bool Visit[21][21];
int area[21][21] = {0, };
int size;
int num = 0;
int final = 0;
int eat_num = 0;
vector<pair<int, int>> baby_shark;
vector<pair<int, int>> can_eat;//먹을 수 있는 물고기 위치
vector<tuple<int, int, int>> shortest;
vector<tuple<int, int, int>> shortest_i;
vector<tuple<int, int, int>> shortest_j;
vector<int> time_final;
vector<int> shark_size;
vector<tuple<int, int, int>> V;
int n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1 ,-1 ,0 ,0 };

bool sortbysec(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
} 

bool sortbyth(const tuple<int, int, int>& a,  
              const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
} 

void bfs(int a, int b, int size){//time재기
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));//맨처음은 아기상어 위치
    Visit[a][b] = true;
    V.clear();

    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dist = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                if (Visit[nx][ny] == false)
                {
                    if (area[nx][ny] == 0)//지나갈 수 있다
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                    else if (area[nx][ny] < size)//지나갈 수 있다, 먹을 수 있다
                    {
                        V.push_back(make_tuple(nx, ny, Dist+1));
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                    else if (area[nx][ny] == size)//지나갈 수 있다
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Dist + 1));
                    }
                }
            }
        }
    }
}

void eat_fish(){//물고기 잡아먹기

    while(1){
        memset(Visit, false, sizeof(Visit));
        bfs(baby_shark[0].first, baby_shark[0].second, shark_size[shark_size.size()-1]);

        if(V.size()>1){//먹을 수 있는 물고기가 2개 이상
            //위치 확인해서 가까운것 먹기(최단->위->왼)
            for(int i=0; i<V.size(); i++){
                int time  = get<2>(V[i]);
                shortest.push_back(make_tuple(get<0>(V[i]), get<1>(V[i]), time));
            }

            //shortest time순으로 정렬하고, i, j순으로 정렬(다 오름차순)
            sort(shortest.begin(), shortest.end(), sortbyth);//time

            // shortest_i.push_back(make_tuple(get<0>(shortest[0]), get<1>(shortest[0]), get<2>(shortest[0])));
            for(int i=0; i<shortest.size(); i++){//time 같으면
                if(get<2>(shortest[0]) == get<2>(shortest[i])){
                    shortest_i.push_back(make_tuple(get<0>(shortest[i]), get<1>(shortest[i]), get<2>(shortest[i])));
                }
            }

            sort(shortest_i.begin(), shortest_i.end());//i

            // shortest_j.push_back(make_tuple(get<0>(shortest_i[0]), get<1>(shortest_i[0]), get<2>(shortest_i[0])));
            for(int i=0; i<shortest_i.size(); i++){//i 같으면
                if(get<0>(shortest_i[0]) == get<0>(shortest_i[i])){
                    shortest_j.push_back(make_tuple(get<0>(shortest_i[i]), get<1>(shortest_i[i]), get<2>(shortest_i[i])));
                }
            }

            sort(shortest_j.begin(), shortest_j.end(), sortbysec);

            //가장 맨 앞에 있는 있는 것을 먹는다
            //아기상어 원래 위치에 0값 넣기
            area[baby_shark[0].first][baby_shark[0].second] = 0;
            //먹는 물고기 위치에 아기상어 9값 넣기
            area[get<0>(shortest_j[0])][get<1>(shortest_j[0])] = 9;
            baby_shark.clear();
            baby_shark.push_back(make_pair(get<0>(shortest_j[0]), get<1>(shortest_j[0])));
            //아기상어가 먹은 물고기 수(eat_num) +1
            eat_num++;
            time_final.push_back(get<2>(shortest_j[0]));
        
        }else if(V.size() == 1){//1개 먹을 수 있을 때->그냥 그 위치에 있는 물고기 먹는다.
            int time  = get<2>(V[0]);
            time_final.push_back(time);
            //아기상어 원래 위치에 0값 넣기
            area[baby_shark[0].first][baby_shark[0].second] = 0;
            //먹는 물고기 위치에 아기상어 9값 넣기
            area[get<0>(V[0])][get<1>(V[0])] = 9;
            baby_shark.clear();
            baby_shark.push_back(make_pair(get<0>(V[0]), get<1>(V[0])));
            //아기상어가 먹은 물고기 수(eat_num) +1
            eat_num++;

        }else if(V.size() == 0){
            for(int i=0; i<time_final.size(); i++){
                final += time_final[i];
            }
            cout<<final<<"\n";
            break;
        }

        //아기상어가 먹은 물고기의 수(eat_num)가 아기상어의 크기와 같게 되면 아기 상어 크기 size+1, eat_num = 0초기화
        if(eat_num == shark_size[shark_size.size()-1]){
            size = shark_size[shark_size.size()-1] + 1;
            shark_size.push_back(size);
            eat_num = 0;
        }

        shortest.clear();
        shortest_i.clear();
        shortest_j.clear();
    }
}

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>area[i][j];
            if(area[i][j] == 9){//아기 상어 위치
                baby_shark.push_back(make_pair(i, j));
            }
        }
    }

    shark_size.push_back(2);
    eat_fish();

    return 0;
}