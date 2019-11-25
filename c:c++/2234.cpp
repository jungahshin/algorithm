//성곽
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[100][100] = {0, };
int check[4] = {0, 1, 2, 3};
int visited[100][100] = {0, };
vector <int> num[100][100];
int room = 0;
int biggest = 0;
int m, n;
vector<int> final;
bool wall_remove_temp = false;

void go(int x_start, int y_start){
    for(int i=x_start; i<m; i++){
        for(int j=y_start; j<n; j++){
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int temp = 0;
            while(!q.empty()){
                temp++;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(num[x][y].size() == 0){//다 닫혀 있는 경우
                    visited[x][y] = 1;
                }
                for(int k=0; k<num[x][y].size(); k++){
                    if(num[x][y][k] == 0){//서
                        int final_x = x;
                        int final_y = y-1;
                        if(0 <= final_x && final_x < m && 0 <= final_y && final_y < n && visited[final_x][final_y] == 0){
                            if(visited[x][y] == 0){
                                visited[x][y] += 1;
                            }
                            visited[final_x][final_y] = visited[x][y] + 1;
                            q.push(make_pair(final_x, final_y));
                        }
                    }else if(num[x][y][k] == 1){//북
                        int final_x = x-1;
                        int final_y = y;
                        if(0 <= final_x && final_x < m && 0 <= final_y && final_y < n && visited[final_x][final_y] == 0){
                            if(visited[x][y] == 0){
                                visited[x][y] += 1;
                            }
                            visited[final_x][final_y] = visited[x][y] + 1;
                            q.push(make_pair(final_x, final_y));
                        }                        
                    }else if(num[x][y][k] == 2){//동
                        int final_x = x;
                        int final_y = y+1;
                        if(0 <= final_x && final_x < m && 0 <= final_y && final_y < n && visited[final_x][final_y] == 0){
                            if(visited[x][y] == 0){
                                visited[x][y] += 1;
                            }
                            visited[final_x][final_y] = visited[x][y] + 1;
                            q.push(make_pair(final_x, final_y));
                        }
                    }else if(num[x][y][k] == 3){//남
                        int final_x = x+1;
                        int final_y = y;
                        if(0 <= final_x && final_x < m && 0 <= final_y && final_y < n && visited[final_x][final_y] == 0){
                            if(visited[x][y] == 0){
                                visited[x][y] += 1;
                            }                            
                            visited[final_x][final_y] = visited[x][y] + 1;
                            q.push(make_pair(final_x, final_y));
                        }                       
                    }
                }
                biggest = max(biggest, temp);
            }
            if(wall_remove_temp == true){
                return;
            }
        }
    }
}

void wall_remove(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int check_temp[4] = {0, };
            for(int k=0; k<num[i][j].size(); k++){
                for(int t=0; t<4; t++){
                    if(num[i][j][k] == check[t]){
                        check_temp[t] = 1;
                    }
                }
            }
            for(int k=0; k<4; k++){
                if(check_temp[k] == 0){//벽이다.
                    memset(visited, 0, sizeof(visited));
                    if(check[k] == 0){//서, (i, j-1)
                        if(0 <= i && i < m && 0 <= (j-1) && (j-1) < n){
                            num[i][j].push_back(check[k]);
                            wall_remove_temp = true;
                            go(i, j);
                            num[i][j].pop_back();
                        }
                    }else if(check[k] == 1){//북
                        if(0 <= (i-1) && (i-1) < m && 0 <= j && j < n){
                            num[i][j].push_back(check[k]);
                            wall_remove_temp = true;
                            go(i, j);
                            num[i][j].pop_back();
                        }                        
                    }else if(check[k] == 2){//동
                        if(0 <= i && i < m && 0 <= (j+1) && (j+1) < n){
                            num[i][j].push_back(check[k]);
                            wall_remove_temp = true;
                            go(i, j);
                            num[i][j].pop_back();
                        }                        
                    }else if(check[k] == 3){//남
                        if(0 <= (i+1) && (i+1) < m && 0 <= j && j < n){
                            num[i][j].push_back(check[k]);
                            wall_remove_temp = true;
                            go(i, j);
                            num[i][j].pop_back();
                        }
                    }
                }
            }
        }
    }
}

void room_check(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 1){
                room ++;
            }
        }
    }    
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 1){
                num[i][j].push_back(1);
                num[i][j].push_back(2);
                num[i][j].push_back(3);
            }else if(a[i][j] == 2){
                num[i][j].push_back(0);
                num[i][j].push_back(2);
                num[i][j].push_back(3);
            }else if(a[i][j] == 3){
                num[i][j].push_back(2);
                num[i][j].push_back(3);               
            }else if(a[i][j] == 4){
                num[i][j].push_back(0);
                num[i][j].push_back(1);      
                num[i][j].push_back(3);          
            }else if(a[i][j] == 5){
                num[i][j].push_back(1);      
                num[i][j].push_back(3); 
            }else if(a[i][j] == 6){
                num[i][j].push_back(0);      
                num[i][j].push_back(3);                 
            }else if(a[i][j] == 7){
                num[i][j].push_back(3);                 
            }else if(a[i][j] == 8){
                num[i][j].push_back(0);
                num[i][j].push_back(1);      
                num[i][j].push_back(2);                
            }else if(a[i][j] == 9){
                num[i][j].push_back(1);      
                num[i][j].push_back(2);                 
            }else if(a[i][j] == 10){
                num[i][j].push_back(0);      
                num[i][j].push_back(2);                 
            }else if(a[i][j] == 11){
                num[i][j].push_back(2);              
            }else if(a[i][j] == 12){
                num[i][j].push_back(0);
                num[i][j].push_back(1);
            }else if(a[i][j] == 13){
                num[i][j].push_back(1);
            }else if(a[i][j] == 14){
                num[i][j].push_back(0);
            }else if(a[i][j] == 0){
                num[i][j].push_back(0);
                num[i][j].push_back(1);
                num[i][j].push_back(2);
                num[i][j].push_back(3);
            }
        }
    }
    go(0, 0);
    room_check();
    final.push_back(room);
    final.push_back(biggest);
    wall_remove();
    final.push_back(biggest);
    for(int i=0; i<final.size(); i++){
        cout<<final[i]<<"\n";
    }
}