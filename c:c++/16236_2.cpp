//아기상어
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <tuple>
using namespace std;

int area[21][21] = {0, };
int size = 2;
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
int n;

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

int eat_fish(int size){//물고기 잡아먹기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(0<area[i][j] && area[i][j]<size){//먹을 수 있는 물고기
                can_eat.push_back(make_pair(i, j));
            }
        }
    }

    if(can_eat.size()>1){//먹을 수 있는 물고기가 2개 이상
        cout<<"2 in"<<"\n";
        //위치 확인해서 가까운것 먹기(최단->위->왼)
        for(int i=0; i<can_eat.size(); i++){
            int time  = abs(baby_shark[0].first - can_eat[i].first) + abs(baby_shark[0].second - can_eat[i].second);
            shortest.push_back(make_tuple(can_eat[i].first, can_eat[i].second, time));
        }

        for(int i=0; i<shortest.size(); i++){
            cout<<"shortest time 정렬 전"<<get<0>(shortest[i])<<" "<<get<1>(shortest[i])<<" "<<get<2>(shortest[i])<<"\n";
        }

        //shortest time순으로 정렬하고, i, j순으로 정렬(다 오름차순)
        sort(shortest.begin(), shortest.end(), sortbyth);//time

        for(int i=0; i<shortest.size(); i++){
            cout<<"shortest time 정렬 후"<<get<0>(shortest[i])<<" "<<get<1>(shortest[i])<<" "<<get<2>(shortest[i])<<"\n";
        }

        // shortest_i.push_back(make_tuple(get<0>(shortest[0]), get<1>(shortest[0]), get<2>(shortest[0])));
        for(int i=0; i<shortest.size(); i++){//time 같으면
            if(get<2>(shortest[0]) == get<2>(shortest[i])){
                shortest_i.push_back(make_tuple(get<0>(shortest[i]), get<1>(shortest[i]), get<2>(shortest[i])));
            }
        }

        for(int i=0; i<shortest_i.size(); i++){
            cout<<"shortest_i 정렬 전"<<get<0>(shortest_i[i])<<" "<<get<1>(shortest_i[i])<<" "<<get<2>(shortest_i[i])<<"\n";
        }

        sort(shortest_i.begin(), shortest_i.end());//i

        for(int i=0; i<shortest_i.size(); i++){
            cout<<"shortest_i 정렬 후"<<get<0>(shortest_i[i])<<" "<<get<1>(shortest_i[i])<<" "<<get<2>(shortest_i[i])<<"\n";
        }

        // shortest_j.push_back(make_tuple(get<0>(shortest_i[0]), get<1>(shortest_i[0]), get<2>(shortest_i[0])));
        for(int i=0; i<shortest_i.size(); i++){//i 같으면
            if(get<0>(shortest_i[0]) == get<0>(shortest_i[i])){
                shortest_j.push_back(make_tuple(get<0>(shortest_i[i]), get<1>(shortest_i[i]), get<2>(shortest_i[i])));
            }
        }

        for(int i=0; i<shortest_j.size(); i++){
            cout<<"shortest_j 정렬 전"<<get<0>(shortest_j[i])<<" "<<get<1>(shortest_j[i])<<" "<<get<2>(shortest_j[i])<<"\n";
        }

        sort(shortest_j.begin(), shortest_j.end(), sortbysec);

        for(int i=0; i<shortest_j.size(); i++){
            cout<<"shortest_j 정렬 후"<<get<0>(shortest_j[i])<<" "<<get<1>(shortest_j[i])<<" "<<get<2>(shortest_j[i])<<"\n";
        }

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
        cout<<"time"<<get<2>(shortest_j[0])<<"\n";
    
    }else if(can_eat.size() == 1){//1개 먹을 수 있을 때->그냥 그 위치에 있는 물고기 먹는다.
        cout<<"1 in"<<"\n";
        int time  = abs(baby_shark[0].first - can_eat[0].first) + abs(baby_shark[0].second - can_eat[0].second);
        // cout<<"time"<<time<<"\n";
        time_final.push_back(time);
        //아기상어 원래 위치에 0값 넣기
        area[baby_shark[0].first][baby_shark[0].second] = 0;
        //먹는 물고기 위치에 아기상어 9값 넣기
        area[can_eat[0].first][can_eat[0].second] = 9;
        baby_shark.clear();
        baby_shark.push_back(make_pair(can_eat[0].first, can_eat[0].second));
        //아기상어가 먹은 물고기 수(eat_num) +1
        eat_num++;
        cout<<"time"<<time<<"\n";

    }

    //아기상어가 먹은 물고기의 수(eat_num)가 아기상어의 크기와 같게 되면 아기 상어 크기 size+1, eat_num = 0초기화
    if(eat_num == size){
        size += 1;
        shark_size.push_back(size);
        eat_num = 0;
    }

    //마지막쯤에 먹을 수 있는 물고기-> num수 다시 재기
    num = 0;//num초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(0<area[i][j] && area[i][j]<size){//먹을 수 있는 물고기
                num++;
            }
        }
    }

    can_eat.clear();
    shortest.clear();
    shortest_i.clear();
    shortest_j.clear();

    return num;
}


int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>area[i][j];
            if(area[i][j] == 9){//아기 상어 위치
                baby_shark.push_back(make_pair(i, j));
            }
            if(0<area[i][j] && area[i][j]<size){//먹을 수 있는 물고기 수
                num++;
            }
        }
    }

    shark_size.push_back(size);

    while(num>0){//먹을 수 있는 물고기가 하나라도 있으면 계속 eat_fish함수 진행
        num = eat_fish(shark_size[shark_size.size()-1]);
        cout<<"size"<<shark_size[shark_size.size()-1]<<"\n";
        cout<<"num"<<num<<"\n";
    }

    for(int i=0; i<time_final.size(); i++){
        final += time_final[i];
    }
    cout<<final<<"\n";
    
    return 0;
}