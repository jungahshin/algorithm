//아이 러브 크로아티아
#include <iostream>
#include <vector>
using namespace std;

int k, n, time_;
char check;//문제를 맞췄는지 여부
vector<pair<int, char>> game;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};//왼쪽->방향
int final = 0;

void play(){
    //210초 보다 커지는 지점에 break;
    int num = 0;//시간 경과
    int idx = k-1;
    for(int i=0; i<game.size(); i++){
        num += game[i].first;
        if(num > 210){
            final = arr[idx];
            break;
        }else if(num == 210 && i == game.size()-1 && game[i].second == 'T'){
            if(idx+1>7){
                idx = 0;
            }else{
                idx += 1;
            }
            final = arr[idx];
            break;
        }else if(num == 210 && i == game.size()-1 && (game[i].second == 'P' || game[i].second == 'N')){
            final = arr[idx];
            break;
        }
        if(game[i].second == 'T'){//왼쪽 사람에게 전달
            if(idx+1>7){
                idx = 0;
            }else{
                idx += 1;
            }
        }
    }
}

int main(){
    cin>>k;//처음 폭탄을 들고 있는 사람
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>time_>>check;
        game.push_back(make_pair(time_, check));
    }
    play();
    cout<<final<<"\n";
}