#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

int a,b,t,r,start,goal;
int input[101][101] = {0, };//연결되어 있는 지 여부
int visited[101] = {0, };//방문했는 지 여부
int area[101];//구역 번호 저장
int x_[101];//x좌표 저장
int y_[101];//y좌표 저장
int r_[101];//반지름 저장
vector<int> final_list;

void bfs(int start, int goal , string str){//start, goal 구역 번호이다.
    visited[start] = 1;
    queue<pair<int,string> q;
    q.push(make_pair(start, str));//구역이랑 str 푸시
    while(!q.empty()){
        int front = q.front().first;
        string str = q.front().second;
        q.pop();
        if(front == goal){
            final_list.push_back(str);
            break;//함수 빠져 나온다.
        }
        for(int i=0; i<num; i++){
            if(!visited[(area[i])] && input[front][(area[i])]){
                visited[i] = 1;
                q.push(make_pair(area[i], str+to_string(area[i])+" "));
            }
        }

    }
}

// void dfs(int start, int i, string str){//start, i 모두 구역 번호이다
//     visited[start][i] = 1;
//     visited[i][start] = 1;
//     if(){//str의 마지막 요소가 goal이면--> 다른 final_list에 넣어 주기

//     }else if(){//str의 마지막 요소가 goal이 아니면, 

//     }else{//str의 마지막 요소가 goal이 아니고
//         for(int j=0; j<num; j++){
//             if(!visited[i][(t[j])] && input[i][(t[j])]){
//                 dfs(i, t[j], str+to_string(t[j])+" ");
//             }
//         }
//         //str의 마지막 요소가 goal이 아닌 경우,
//     }
// }

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

    // for(int i=0; i<num; i++){//기준
    //     for(int j=0; j<num; j++){
    //         //원의 중심 사이의 거리<반지름 차이면 --> 포함
    //         if(sqrt(pow(x_[i]-x_[j],2) + pow(y_[i]-y_[j],2)) < abs(r_[i]-r_[j])){
    //             input[(area[i])][(area[j])] = 1;
    //             input[(area[j])][(area[i])] = 1;
    //         }
    //         else if(abs(r_[i]-r_[j]) <= sqrt(pow(x_[i]-x_[j],2) + pow(y_[i]-y_[j],2)) && sqrt(pow(x_[i]-x_[j],2) + pow(y_[i]-y_[j],2)) <= abs(r_[i]+r_[j])){// 두 원이 접할때
    //             return 0;
    //         }
    //    
    //         //어떤것에 포함되는 것이 아닌 구역을 찾아라!
    //         //그리고 그 구역은 무조건 0과 연결관계를 1로 해준다.
    //     }
    // }
    


    for(int i=0 ; i<num; i++){//기준 구역--> 이 구역이 어떤 구역을 포함하고 있는 지 확인 후 포함 구역을 list에 넣고 정렬
        vector<int> sort_area;
        sort_area.push_back(area[i]);
        for(int j=0; j<num; j++){
            if(sqrt(pow(x_[i]-x_[j],2) + pow(y_[i]-y_[j],2)) < (r_[i]-r_[j])){
                sort_area.push_back(area[j]);//포함하는 구역을 list에 넣는다.
            }
        }
        sort(sort_area.begin(), sort_area.end());//list 정렬
        for(int i=0; i<sort_area.size()-1; i++){
            input[(sort_area[i])][(sort_area[i+1])] = 1;
        }
        intput[0]
    }



    bfs(start, goal, to_string(start)+" ");


}


//일단 맨 처음 원의 중심과 다른 원의 중심 사이의 거리가 반지름이 더 큰 원의 반지름보다 작으면 포함 관계이다.
//그러니 arr 값을 1로 채워준다. 7에 8이 포함되어 있으면 (7,8)과 (8,7)의 값이 1이다.
//그리고 나서 출발 하는 구역의 숫자에서 시작하여 그 구역과 연결되어 있는 지점


//처음 main의 bfs와 bfs함수 안의 bfs에서 모두 top으로 들어가는 변수들은 특정 list에 추가한다.
//왜냐하면 그것들은 어느 곳에 종속되면 visited가 1이 되기 때문에