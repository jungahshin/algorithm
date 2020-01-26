//시험 감독
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
long long n, b, c, mem;
long long final = 0;

void go(){
    for(int i=0; i<v.size(); i++){//v[i]는 각 반의 학생수
        long long sum = 0;//남은 학생 수(각 반)
        long long num = 0;//총 감독 수(각 반)
        sum = v[i]-b;//부감독이 맡아야하는 학생수
        if(sum <= 0){
            num++;
            final += num;
            continue;
        }else{
            num++;
            num += (sum/c);//몫만큼을 더해주고
            if((sum%c) > 0){//나머지가 있다면 +1 해준다.
                num++;
            }
        }
        final += num;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>mem;
        v.push_back(mem);
    }
    cin>>b>>c;//총감독(1명)이 맡는 학생 수, 부감독(여러명)이 맡는 학생 수
    go();
    cout<<final<<"\n";
}