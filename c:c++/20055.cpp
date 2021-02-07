#include <iostream>
using namespace std;
 
int n, k, l;
pair<int, bool> convey[210];
 
void conveyMove(){
    pair<int, bool> temp[210];
    int num = convey[2*n].first;
    for(int i=1; i<2*n; i++){
        int x = convey[i].first;
        int y = convey[i].second;
        if(i>=n){
            y = false;
        }
        temp[i+1] = make_pair(x, y);
    }
    temp[1] = make_pair(num, false);
    for(int i=1; i<=2*n; i++){
        convey[i] = make_pair(temp[i].first, temp[i].second);
    }
}
 
void robotMove(){
    for(int i=n-1; i>=1; i--){
        if(convey[i].second && !convey[i+1].second){
            if(convey[i+1].first>=1){
                convey[i+1].second = true;
                convey[i].second = false;
                convey[i+1].first--;
            }
        }
    }
}
 
bool check()
{
    int num = 0;
    for(int i=1; i<=2*n; i++){
        if(convey[i].first==0){
            num++;
        }
    }
 
    if(num>=k){
        return true;
    }
 
    return false;
}
 
int main()
{
    cin>>n>>k;
    for(int i=1; i<=2*n; i++){
        cin>>l;
        convey[i] = make_pair(l, false);
    }
 
    int cnt = 0;
 
    while(1){
        cnt++;
        conveyMove();
        if(convey[n].second){
            convey[n].second = false;
        }
 
        robotMove();
        if(convey[n].second){
            convey[n].second = false;
        }
        
        if(convey[1].first!=0){
            convey[1].second = true;
            convey[1].first--;
        }   
        if(check()){
            break;
        }    
    }
 
    cout<<cnt<<"\n";
    return 0;
}