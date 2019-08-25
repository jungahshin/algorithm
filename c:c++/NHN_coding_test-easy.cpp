#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

int a,b,t,r,start,goal;
int start_index;
int goal_index;
vector<pair<int,int>> goal_include;
vector<pair<int,int>> start_include;
vector<int> final;
int area[101];//구역 번호 저장
int x_[101];//x좌표 저장
int y_[101];//y좌표 저장
int r_[101];//반지름 저장
int num = 0;
bool flag = 0;

int main(){
    cin>>num;//구역 수
	
	for(int i =0; i<num; i++){
		cin>>t;//구역 번호
		cin>>a;//x좌표
		cin>>b;//y좌표
		cin>>r;//반지름 크기
		area[i] = t;
        x_[i] = a;
        y_[i] = b;
        r_[i] = r;
	}

    cin>>start;//시작 구역 번호
    cin>>goal;//지도가 있는 구역 번호

    if(start == goal){
        cout<<start<<"\n";
        return 0;
    }else{
        //start구역이 몇 번째 인지 모른다..
        for(int i=0; i<num; i++){//start구역의 인덱스 찾기
            if(area[i] == start){
                start_index = i;
            }
        }

        for(int i=0; i<num; i++){//goal구역의 인덱스 찾기
            if(area[i] == goal){
                goal_index = i;
            }
        }

        goal_include.push_back(make_pair(goal, r_[goal_index]));
        start_include.push_back(make_pair(start, r_[start_index]));

        for(int i=0; i<num; i++){//start를 포함하는 구역을 찾아 list에 넣는다.
            if(sqrt(pow(x_[start_index]-x_[i],2) + pow(y_[start_index]-y_[i],2)) < (r_[i]-r_[start_index])){
                start_include.push_back(make_pair(area[i], r_[i]));//구역과 반지름 저장
            }
        }

        for(int i=0; i<num; i++){//goal구역을 포함하는 구역을 찾아 list에 넣는다.
            if(sqrt(pow(x_[goal_index]-x_[i],2) + pow(y_[goal_index]-y_[i],2)) < (r_[i]-r_[goal_index])){
                goal_include.push_back(make_pair(area[i], r_[i]));//구역과 반지름 저장
            }
        }

        //반지름 순으로 정렬한다.(오름차순)
        sort(start_include.begin(), start_include.end(),[](const pair<int, int>& lhs, const pair<int, int>& rhs){
             return lhs.second < rhs.second; 
        });

        //반지름 순으로 정렬한다.(오름차순)
        sort(goal_include.begin(), goal_include.end(),[](const pair<int, int>& lhs, const pair<int, int>& rhs){
             return lhs.second < rhs.second; 
        });

        for(int i=0; i<start_include.size(); i++){
            for(int j=0; j<goal_include.size(); j++){
                if(start_include[i].first == goal_include[j].first){//구역이 같으면
                    num++;//중복의 개수를 센다.
                }
            }
        }

        if(num == 0){//하나도 중복 값이 없으면 둘은 전혀 어디에도 포함되지 않는 다른 곳에 있으므로 0을 지나야 한다.
            reverse(goal_include.begin(), goal_include.end());
            for(int i=0; i<start_include.size(); i++){
                final.push_back(start_include[i].first);//구역만 넣는다.
            }
            final.push_back(0);
            for(int i=0; i<goal_include.size(); i++){
                final.push_back(goal_include[i].first);
            }

        }else if(num == 1){//중복 값이 하나라도 있으면 두 구역은 어느 구역에 같이 포함되어 있는 것
            //일단 goal_include함수를 reverse로 순서를 바꾼 후에, start_include에 push_back으로 모두 추가한다.
            reverse(goal_include.begin(), goal_include.end());
            for(int i=0; i<goal_include.size(); i++){
                start_include.push_back(goal_include[i]);
            }
            for(int i=0; i<start_include.size(); i++){
                final.push_back(start_include[i].first);//구역만 넣는다.
            }
            //그리고 중복검사를 해서 중복이 있으면 하나를 삭제한다.
            final.erase(unique(final.begin(),final.end()),final.end());

        }else if(num >= 2){
            for(int i=0; i<start_include.size(); i++){
                for(int j=0; j<goal_include.size(); j++){
                    if(start_include[i].first == goal_include[j].first){
                        start_include.erase(start_include.begin()+i+1, start_include.end());
                        goal_include.erase(goal_include.begin()+j+1, goal_include.end());
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    break;
                }
            }
            //일단 goal_include함수를 reverse로 순서를 바꾼 후에, start_include에 push_back으로 모두 추가한다.
            reverse(goal_include.begin(), goal_include.end());
            for(int i=0; i<goal_include.size(); i++){
                start_include.push_back(goal_include[i]);
            }
            for(int i=0; i<start_include.size(); i++){
                final.push_back(start_include[i].first);//구역만 넣는다.
            }
            //그리고 중복검사를 해서 중복이 있으면 하나를 삭제한다.
            final.erase(unique(final.begin(),final.end()),final.end());
        }

        for(int i=0; i<final.size(); i++){
            cout<<final[i]<<" ";
        }
        return 0;
    }
    
}