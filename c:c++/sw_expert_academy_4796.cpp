//의석이의 우뚝선 산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;
int a[50001] = {0, };
vector<int> v;
vector<int> up_sort;
vector<int> up_sort_temp;
vector<int> down_sort;
vector<int> down_sort_temp;
vector<pair<int, int>> temp;
int final = 0;
vector<int> final_num;

void go(){
    for(int i=3; i<=n; i++){
        for(int j=0; j<n-i+1; j++){
            for(int k=0; k<i; k++){
                v.push_back(a[j+k]);
            }
            //v에 들어있는 값들이 '우뚝선 산'규칙에 맞으면 final++
            for(int h=0; h<v.size(); h++){
                temp.push_back(make_pair(v[h], h));
            }
            sort(temp.begin(), temp.end());//오름 차순 정렬(first기준)
            for(int z=0; z<=(temp[temp.size()-1].second); z++){//v의 있는 그대로를 넣은 up_sort
                up_sort.push_back(v[z]);
            }
            for(int z=0; z<=(temp[temp.size()-1].second); z++){//v를 넣어서 정렬한 up_sort_temp
                up_sort_temp.push_back(v[z]);
            }
            sort(up_sort_temp.begin(), up_sort_temp.end());
            for(int z=(temp[temp.size()-1].second); z<v.size()-1; z++){
                down_sort.push_back(v[z]);
            }
            for(int z=(temp[temp.size()-1].second); z<v.size()-1; z++){
                down_sort_temp.push_back(v[z]);
            }
            sort(down_sort_temp.begin(), down_sort_temp.end());
            if(up_sort == up_sort_temp && down_sort == down_sort_temp){
                final++;
            }
            v.clear();
            temp.clear();
            up_sort.clear();
            up_sort_temp.clear();
            down_sort.clear();
            down_sort_temp.clear();
        }
    }
}

int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        final = 0;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>a[j];
        }
        go();
        final_num.push_back(final);
    }
    for(int i=0; i<final_num.size(); i++){
        cout<<"#"<<i+1<<" "<<final_num[i]<<"\n";
    }
}