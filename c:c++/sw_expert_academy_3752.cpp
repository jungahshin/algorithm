//가능한 시험 점수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, problem_num;
int a[101] = {0, };
bool Select[101];
vector<int> v;
vector<int> final;
int final_num = 0;
vector<int> final_v;
 
void DFS(int Idx, int Cnt){
    for(int i = 1; i<=problem_num; i++){
        if(i == Cnt){
            for (int i = 0; i <problem_num ; i++)
            {
                if (Select[i] == true)
                {
                    v.push_back(a[i]);
                }
            }
            final_num = 0;
            for(int i=0; i<v.size(); i++){
                final_num += v[i];
            }
            final.push_back(final_num);
            v.clear();
            // return;
        }
    }
 
    for (int i = Idx; i < problem_num; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;

        DFS(i, Cnt + 1);
        Select[i] = false;
    }

}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        for(int h=0; h<101; h++){
            Select[h] = false;
        }
        final.push_back(0);
        cin>>problem_num;
        for(int j=0; j<problem_num; j++){
            cin>>a[j];
        }

        DFS(0,0);
        
        sort(final.begin(), final.end());
        final.erase(unique(final.begin(), final.end()), final.end());
        final_v.push_back(final.size());
        final.clear();
    }
    for(int i=0; i<final_v.size(); i++){
        cout<<"#"<<i+1<<" "<<final_v[i]<<"\n";
    }
}