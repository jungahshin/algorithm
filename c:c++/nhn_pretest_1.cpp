#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
string m;
int m_num;//enqueue 숫자
vector<int> v;
vector<int> temp;
vector<int> final_out;
vector<int> finally;
vector<tuple<int, int, int>> final;
vector<tuple<int, int, int>> final_i;

bool sortbyth(const tuple<int, int, int>& a,  
              const tuple<int, int, int>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
} 

void go(){
	for(int i=0; i<v.size(); i++){
		if(v[i] != 0){//dequeue가 아니라면
			//enqueue해준다.
			final_out.push_back(v[i]);
		}else{//dequeue-->빈도수가 가장 높은 값 중에 가장 먼저 enqueue된 것
			int visited[101] = {0, };
			for(int j=0; j<final_out.size(); j++){
				if(!visited[j] && final_out[j] != 0){
					temp.push_back(final_out[j]);
					visited[j] = 1;
				}
				for(int k=0; k<final_out.size(); k++){
					if(final_out[j] == final_out[k] && !visited[k] && final_out[k] != 0){
						temp.push_back(final_out[k]);
						visited[k] = 1;
					}
				}
				//다른 값으로 넘어가는 구간(v에 있는 갯수를 따로 저장)
				if(temp.size() != 0){
					final.push_back(make_tuple(temp.size(), final_out[j], j));
				}
				temp.clear();
			}

			//final에 있는 값들로 dequeue하기
			
			sort(final.begin(), final.end());//빈도수로 정렬(오름)

            for(int i=0; i<final.size()-1; i++){//빈도수 같으면
                if(get<0>(final[final.size()-1]) == get<0>(final[i])){
                    final_i.push_back(make_tuple(get<0>(final[i]), get<1>(final[i]), get<2>(final[i])));
                }
            }

            final_i.push_back(make_tuple(get<0>(final[final.size()-1]), get<1>(final[final.size()-1]), get<2>(final[final.size()-1])));

            sort(final_i.begin(), final_i.end(), sortbyth);//들어온 순서로

			for(int i=0; i<final_out.size(); i++){
				if(final_out[i] == get<1>(final_i[0])){
					final_out.erase(final_out.begin()+i);//큐역할
					finally.push_back(get<1>(final_i[0]));//출력할 것
					break;
				}
			}

			final.clear();
			final_i.clear();
		}
	}
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>m;
		if(m == "enqueue"){
			cin>>m_num;
			v.push_back(m_num);
		}
		if(m == "dequeue"){
			v.push_back(0);
		}
	}
	
	go();
	
	for(int i=0; i<finally.size(); i++){
		cout<<finally[i];
		if(i != finally.size()-1){
			cout<<" ";
		}
	}
	
	cout<<"\n";
	
	return 0;
}