#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include <cmath>
#include <cstdio>
#include <typeinfo> 
using namespace std;

int area[11][11] = {0, };
int tree[101][101] = {0, };
int vitamin[11][11];//맨 처음 양분의 값은 5로 초기화
vector<pair<int, int>> tree_location;
vector<pair<int, int>> same;
vector<int> age_;
int same_num[11][11] = {0, };//각 칸에 중복되는 나무들이 있는지 판별하는 용도
int n,k,x,y,age,a,b,c,d;
int m,num=0;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(){//1년마다 반복
    //spring
    int num = tree_location.size();
    int visited[11][11] = {0, };//1년마다 초기화하기
    vector<tuple<int, int, int>> summer;
    for(int y=0; y<tree_location.size(); y++){
        cout<<tree_location[y].first<<"!"<<tree_location[y].second<<"\n";
    }
    for(int i=0; i<num; i++){//나무가 자신의 나이만큼 양분먹고 나이+1
        int a=tree_location[i].first;
        int b=tree_location[i].second;
        same.push_back(make_pair(age_[i], i));

        cout<<a<<"//"<<b<<"\n";
        if(same_num[a][b]>=2 && !visited[a][b]){//한 칸에 여러개의 나무가 있는 경우
            cout<<"2이상 in"<<"\n";
            visited[a][b] = 1;
            for(int j=i+1; j<num; j++){//같은 위치에 있는 나무들을 찾는다
                int c=tree_location[j].first;
                int d=tree_location[j].second;
                cout<<c<<d<<"\n";
                if(a==c && b==d){//위치가 같고 방문한 적이 없으면
                    cout<<"same 벡터에 추가"<<"\n";
                    // visited[c][d] = 1;
                    same.push_back(make_pair(age_[j], j));//나무 나이를 넣어준다
                }
            }
            //same에 들어있는 나무의 나이를 비교해서 가장 어린 나무부터 양분 먹고 부족해서 못먹는애든 죽음
            if(same.size()>1){
                sort(same.begin(), same.end());//first(나이)기준으로 정렬
                
                for(int h=0; h<same.size(); h++){
                    cout<<"same 들어옴"<<same[h].first<<same[h].second<<"\n";
                }

                for(int k=0; k<same.size(); k++){
                    if(vitamin[a][b]>0 && vitamin[a][b] >= same[k].first){
                        vitamin[a][b] -= same[k].first;
                        age_[(same[k].second)]++;
                        cout<<vitamin[a][b]<<"/"<<age_[(same[k].second)]<<"\n";
                    }else{//양분이 부족한 경우-->즉사
                        cout<<"양분 부족"<<"\n";
                        //summer를 위해 벡터에 죽은 나무의 위치, 죽은 나무 나이/2값 저장
                        cout<<same[k].first<<"죽은 나무 나이/위치"<<same[k].second<<"\n";
                        summer.push_back(make_tuple(a,b,(same[k].first)/2));
                        //tree_location지우고
                        tree_location.erase(tree_location.begin()+(same[k].second));
                        //age_도 지우고
                        age_.erase(age_.begin()+(same[k].second));
                        //same_num--(중복되는 나무수 빼기)
                        same_num[a][b]--;
                        if(i == same[k].second){
                            i=i-1;
                        }
                        for(int y=0; y<tree_location.size(); y++){
                            cout<<"죽은 나무 처리"<<tree_location[y].first<<"!"<<tree_location[y].second<<"\n";

                        }
                    }
                }
            }
            
        }else if(same_num[a][b] == 1 && !visited[a][b] && vitamin[a][b] >= age_[i]){//한 칸에 나무가 한개 있는 경우
            cout<<"1 in"<<"\n";
            visited[a][b] = 1;
            vitamin[a][b] -= age_[i];
            age_[i]++;
            // cout<<vitamin[a][b]<<age_[i]<<"\n";d
        }else if(same_num[a][b] == 1 && !visited[a][b] && vitamin[a][b] < age_[i]){//즉사 시켜야함
            //summer를 위해 벡터에 죽은 나무의 위치, 죽은 나무 나이/2값 저장
            summer.push_back(make_tuple(a,b,(age_[i]/2)));
            //tree_location지우고
            tree_location.erase(tree_location.begin()+i);
            //age_도 지우고
            age_.erase(age_.begin()+i);
            //same_num--(중복되는 나무수 빼기)
            same_num[a][b]--;
        }
        same.clear();
    }

    //summer(봄에 죽은 나무가 양분이 된다.)->'죽은 나무 나이/2'값이 나무가 있던 칸에 양분으로 추가
    for(int i=0; i<summer.size(); i++){
        cout<<"summer in"<<"\n";
        cout<<get<0>(summer[i])<<get<1>(summer[i])<<get<2>(summer[i])<<"\n";
        vitamin[get<0>(summer[i])][get<1>(summer[i])] += get<2>(summer[i]);//양분 추가
        cout<<vitamin[get<0>(summer[i])][get<1>(summer[i])]<<"\n";
    }
    summer.clear();//summer끝날때 해준다.

    //autumn(나무의 나이가 5의 배수인 것들 번식->인접한 8개의 칸)
    for(int i=0; i<num; i++){
        // cout<<tree_location.size()<<"\n";
        if(age_[i]>0 && (age_[i] % 5) == 0){//나이가 5의 배수
            cout<<"autumn in"<<"\n";
            //인접한 8개의 칸에 번식(r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1)
            int spread_x = tree_location[i].first;
            int spread_y = tree_location[i].second;
            for(int j=0; j<8; j++){
                int final_x = spread_x+dx[j];
                int final_y = spread_y+dy[j];
                if(0<final_x && final_x<=n && 0<final_y && final_y<=n){
                    //tree_location추가(push_back)
                    //age_추가->1로 추가(push_back)
                    //그 위치에 same_num++
                    tree_location.push_back(make_pair(final_x, final_y));
                    age_.push_back(1);
                    same_num[final_x][final_y]++;//그 위치의 나무수 +1
                }
            }
        }
    }

    //winter(땅에 양분 추가->각 칸에 추가되는 양분의 양 a[r][c])
    cout<<"winter in"<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vitamin[i+1][j+1] += area[i+1][j+1];
        }
    }
}

int main(){
    cin>>n>>m>>k;//n*n크기, m개 나무의 수, k년 후
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cin>>area[i+1][j+1];//추가되는 양분의 값
        }
    }

    for(int i=0; i<m; i++){
        cin>>x>>y>>age;//나무의 위치및 나이
        tree_location.push_back(make_pair(x,y));
        age_.push_back(age);
        same_num[x][y]++;
    }

    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            vitamin[i][j] = 5;
        }
    }

    for(int j=0; j<k; j++){//k년 만큼 반복한다.
        cout<<j<<"년"<<"\n";
        dfs();
    }


    cout<<tree_location.size()<<"\n";

}
