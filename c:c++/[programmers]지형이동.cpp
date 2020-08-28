// [programmers] 지형 이동
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstring>
 
using namespace std;
 
int visited[301][301] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int check[301][301] = {0, }; // 영역을 구분하기 위한 배열
int parent[90001] = {0, };
vector<pair<int, pair<int, int>>> connect; // {사다리 비용, {영역1, 영역2}}
 
int find(int a){
 if(a==parent[a]){
     return a;
 }
  
 return parent[a] = find(parent[a]);
}
 
 
int solution(vector<vector<int>> land, int height) {
   int answer = 0;
   queue<pair<int, int>> q;
   int r = land.size();
   int c = land[0].size();
   int idx = 0; // 영역을 표시하는 수
  
   // 영역 표시하기
   for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
           if(!visited[i][j]){
               idx++;
               int num = 10001;
               q.push(make_pair(i, j));
              
               while(!q.empty()){
                   int x = q.front().first;
                   int y = q.front().second;
                   check[x][y] = idx;
                   visited[x][y] = 1;
                   q.pop();
                  
                   for(int k=0; k<4; k++){
                       int nx = x+dx[k];
                       int ny = y+dy[k];
                       if(0<=nx && nx<r && 0<=ny && ny<c && !visited[nx][ny]){
                           if(abs(land[x][y]-land[nx][ny])<=height){
                               visited[nx][ny] = 1;
                               q.push(make_pair(nx, ny));
                               check[nx][ny] = idx;
                           }
                       }
                   }
               }
           }
       }
   }
 
 
   // 영역간 발생하는 사다리 비용 계산
   for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
           for(int k=0; k<4; k++){
               int nx = i+dx[k];
               int ny = j+dy[k];
               if(0<=nx && nx<r && 0<=ny && ny<c){
                   if(check[i][j]!=check[nx][ny]){
                       connect.push_back(make_pair(abs(land[i][j]-land[nx][ny]), make_pair(check[i][j], check[nx][ny])));
                   }
               }
           }               
       }
   }
  
  
   // 가장 적은 사다리 비용으로 영역을 연결(MST->kruskal)
   sort(connect.begin(), connect.end()); // 비용순으로 정렬
   for(int i=1; i<=idx; i++){
       parent[i] = i;
   }
   for(int i=0; i<connect.size(); i++){
       int x = connect[i].second.first;
       int y = connect[i].second.second;
       int cost = connect[i].first;
      
       int a = find(x);
       int b = find(y);
      
       if(a!=b){
           parent[a] = b;
           answer += cost;
       }
   }
  
   return answer;
}