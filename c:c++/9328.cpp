//열쇠
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char map[101][101] = {0, };
vector<char> keys;//내가 가지고 있는 키들
string key;
string s;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int final = 0;//총 훔친 문서의 개수
vector<int> real_final;
int w, h, testcase;
int visited[101][101] = {0, };
vector<pair<pair<int, int>, char>> door;
//*-벽| .-빈 공간| $-훔쳐야하는 문서| 알파벳 대문자-문| 알파벳 소문자-열쇠(같은 열쇠, 같은 문 여러개 가능)

void go(){
    //가장자리 부분이 '.'이면 큐에 모두 넣어준다.
    //'.'빈 공간이면 큐에 넣고 문이면 내가 가지고 있는 열쇠중에 있는지 확인하고 있으면 큐에 넣는다.
    //$ 문서이면 ++하고 '.'으로 만들기
    //열쇠이면 내가 가지고 있는지 확인하고 없으면 추가! 그리고 '.'으로 만들기
    queue<pair<int, int>> q;
    for(int i=0; i<w; i++){
        if(map[0][i] == '.'){
            visited[0][i] = 1;
            q.push(make_pair(0, i));
            continue;
        }else if(map[0][i] == '$'){
            final++;
            visited[0][i] = 1;
            q.push(make_pair(0, i));
            map[0][i] = '.';
        }
        for(int j=0; j<26; j++){
            if(map[0][i] == Alphabet[j]){
                q.push(make_pair(-1, i));
                break;
            }
        }
        for(int j=0; j<26; j++){
            if(map[0][i] == alphabet[j]){
                visited[0][i] = 1;
                bool check = false;
                for(int k=0; k<keys.size(); k++){
                    if(alphabet[j] == keys[k]){//이미 가지고 있는 열쇠
                        check = true;
                    }
                }
                if(check == false){//가지고 있지 않다.->추가
                    keys.push_back(alphabet[j]);
                }
                q.push(make_pair(0, i));
                break;
            }
        }
    }
    for(int i=1; i<h-1; i++){
        if(map[i][0] == '.'){
            visited[i][0] = 1;
            q.push(make_pair(i, 0));
        }else if(map[i][0] == '$'){
            final++;
            visited[i][0] = 1;
            q.push(make_pair(i, 0));
            map[i][0] = '.';
        }
        for(int j=0; j<26; j++){
            if(map[i][0] == Alphabet[j]){
                q.push(make_pair(i, -1));
                break;
            }
        }
        for(int j=0; j<26; j++){
            if(map[i][0] == alphabet[j]){
                visited[i][0] = 1;
                bool check = false;
                for(int k=0; k<keys.size(); k++){
                    if(alphabet[j] == keys[k]){//이미 가지고 있는 열쇠
                        check = true;
                    }
                }
                if(check == false){//가지고 있지 않다.->추가
                    keys.push_back(alphabet[j]);
                }
                q.push(make_pair(i, 0));
                break;
            }
        }
    }
    for(int i=1; i<h-1; i++){
        if(map[i][w-1] == '.'){
            visited[i][w-1] = 1;
            q.push(make_pair(i, w-1));
        }else if(map[i][w-1] == '$'){
            final++;
            visited[i][w-1] = 1;
            q.push(make_pair(i, w-1));
            map[i][w-1] = '.';
        }
        for(int j=0; j<26; j++){
            if(map[i][w-1] == Alphabet[j]){
                q.push(make_pair(i, w));
                break;
            }
        }
        for(int j=0; j<26; j++){
            if(map[i][w-1] == alphabet[j]){
                visited[i][w-1] = 1;
                bool check = false;
                for(int k=0; k<keys.size(); k++){
                    if(alphabet[j] == keys[k]){//이미 가지고 있는 열쇠
                        check = true;
                    }
                }
                if(check == false){//가지고 있지 않다.->추가
                    keys.push_back(alphabet[j]);
                }
                q.push(make_pair(i, w-1));
                break;
            }
        }
    }
    for(int i=0; i<w; i++){
        if(map[h-1][i] == '.'){
            visited[h-1][i] = 1;
            q.push(make_pair(h-1, i));
        }else if(map[h-1][i] == '$'){
            final++;
            visited[h-1][i] = 1;
            q.push(make_pair(h-1, i));
            map[h-1][i] = '.';
        }
        for(int j=0; j<26; j++){
            if(map[h-1][i] == Alphabet[j]){
                q.push(make_pair(h, i));
                break;
            }
        }
        for(int j=0; j<26; j++){
            if(map[h-1][i] == alphabet[j]){
                visited[h-1][i] = 1;
                bool check = false;
                for(int k=0; k<keys.size(); k++){
                    if(alphabet[j] == keys[k]){//이미 가지고 있는 열쇠
                        check = true;
                    }
                }
                if(check == false){//가지고 있지 않다.->추가
                    keys.push_back(alphabet[j]);
                }
                q.push(make_pair(h-1, i));
                break;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int j=0; j<4; j++){
            int final_x = x+dx[j];
            int final_y = y+dy[j];
            if(0<=final_x && final_x<h && 0<=final_y && final_y<w && !visited[final_x][final_y]){
                if(map[final_x][final_y] == '.'){
                    visited[final_x][final_y] = 1;
                    q.push(make_pair(final_x, final_y));
                    continue;
                }else if(map[final_x][final_y] == '$'){
                    visited[final_x][final_y] = 1;
                    final++;
                    q.push(make_pair(final_x, final_y));
                    map[final_x][final_y] = '.';
                    continue;
                }
                //알파벳 대문자
                for(int i=0; i<26; i++){
                    if(map[final_x][final_y] == Alphabet[i]){
                        //열쇠가 있는지 확인
                        bool temp = false;
                        for(int k=0; k<keys.size(); k++){
                            if(tolower(Alphabet[i]) == keys[k]){
                                temp = true;
                                visited[final_x][final_y] = 1;
                                q.push(make_pair(final_x, final_y));
                                map[final_x][final_y] = '.';
                                break;
                            }
                        }
                        if(temp == false){//열쇠가 없어
                            door.push_back(make_pair(make_pair(final_x, final_y), Alphabet[i]));
                        }
                        break;
                    }
                }
                //알파벳 소문자(없으면 keys에 추가)
                for(int i=0; i<26; i++){
                    if(map[final_x][final_y] == alphabet[i]){
                        visited[final_x][final_y] = 1;
                        bool check = false;
                        for(int k=0; k<keys.size(); k++){
                            if(alphabet[i] == keys[k]){//이미 가지고 있는 열쇠
                                check = true;
                            }
                        }
                        if(check == false){//가지고 있지 않다.->추가
                            keys.push_back(alphabet[i]);
                        }
                        for(int k=0; k<door.size(); k++){
                            if(tolower(door[k].second) == alphabet[i]){
                                if(!visited[door[k].first.first][door[k].first.second]){
                                    q.push(make_pair(door[k].first.first, door[k].first.second));
                                    visited[door[k].first.first][door[k].first.second] = 1;    
                                    map[door[k].first.first][door[k].first.second] = '.';                                
                                }
                            }
                        }
                        q.push(make_pair(final_x, final_y));
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    cin>>testcase;
    for(int i=0; i<testcase; i++){
        final = 0;
        keys.clear();
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        door.clear();
        cin>>h>>w;
        for(int k=0; k<h; k++){
            cin>>s;
            for(int t=0; t<s.size(); t++){
                map[k][t] = s[t];
            }
        }
        cin>>key;
        if(key != "0"){
            for(int i=0; i<key.size(); i++){
                keys.push_back(key[i]);
            }            
        }
        go();
        real_final.push_back(final);
    }
    for(int i=0; i<real_final.size(); i++){
        cout<<real_final[i]<<"\n";
    }
}