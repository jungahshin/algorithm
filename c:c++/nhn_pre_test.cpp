#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib> //abs함수
#include <cmath>
using namespace std;

int n,w;
int num = 0;
string name;
string name_list[101][101];
vector<string> v;
vector<string> v_du;
queue<string> q;
string after;
int mod;

void go(int num, int n, int w){//시계방향으로 돌아감-->변경된 값을 그대로 name_list에 넣는 식으로
	for(int j=num-1; j<n-num; j++){
		v.push_back(name_list[num-1][j]);
	}
	for(int i=num-1; i<n-num; i++){
		v.push_back(name_list[i][n-num]);
	}
	for(int j=n-num; j>num-1; j--){
		v.push_back(name_list[n-num][j]);
	}
	for(int i=n-num; i>num-1; i--){
		v.push_back(name_list[i][num-1]);
	}
	
	//w만큼 이동(시계 방향)
	for(int i=0; i<v.size(); i++){//v_du에 복사해놓기
		v_du.push_back(v[i]);
	}
	
	for(int i=0; i<v.size(); i++){
		if(i+(w%v.size()) > v.size()-1){
			v_du[i+(w%v.size())-v.size()] = v[i];
		}else{
			v_du[i+(w%v.size())] = v[i];
		}
	}
	
	for(int i=0; i<v_du.size(); i++){
		q.push(v_du[i]);
	}
	
	//다시 name_list에 집어넣기
	for(int j=num-1; j<n-num; j++){
		after = q.front();
		name_list[num-1][j] = after;
		q.pop();
	}
	for(int i=num-1; i<n-num; i++){
		after = q.front();
		name_list[i][n-num] = after;
		q.pop();
	}
	for(int j=n-num; j>num-1; j--){
		after = q.front();
		name_list[n-num][j] = after;
		q.pop();
	}
	for(int i=n-num; i>num-1; i--){
		after = q.front();
		name_list[i][num-1] = after;
		q.pop();
	}
	v.clear();
	v_du.clear();
}

void go_back(int num, int n, int w){//반시계방향으로 돌아감-->변경된 값을 그대로 name_list에 넣는 식으로
	for(int j=num-1; j<n-num; j++){
		v.push_back(name_list[num-1][j]);
	}
	for(int i=num-1; i<n-num; i++){
		v.push_back(name_list[i][n-num]);
	}
	for(int j=n-num; j>num-1; j--){
		v.push_back(name_list[n-num][j]);
	}
	for(int i=n-num; i>num-1; i--){
		v.push_back(name_list[i][num-1]);
	}
	
	//w만큼 이동(반시계 방향)
	for(int i=0; i<v.size(); i++){//v_du에 복사해놓기
		v_du.push_back(v[i]);
	}

	mod = w%v.size();
	for(int i=0; i<v.size(); i++){
		if(i-mod < 0){
			v_du[i-mod+v.size()] = v[i];
		}else{
			v_du[i-mod] = v[i];
		}
	}

	
	for(int i=0; i<v_du.size(); i++){
		q.push(v_du[i]);
	}
	
	//다시 name_list에 집어넣기
	for(int j=num-1; j<n-num; j++){
		after = q.front();
		name_list[num-1][j] = after;
		q.pop();
	}
	for(int i=num-1; i<n-num; i++){
		after = q.front();
		name_list[i][n-num] = after;
		q.pop();
	}
	for(int j=n-num; j>num-1; j--){
		after = q.front();
		name_list[n-num][j] = after;
		q.pop();
	}
	for(int i=n-num; i>num-1; i--){
		after = q.front();
		name_list[i][num-1] = after;
		q.pop();
	}
	v.clear();
	v_du.clear();
}


void determine(int n,int w){//판별하기
		for(int i=n-1; i>=0; i-=2){
			if(i>0 && w>0){//양수(테두리 시계방향)
				num++;
				go(num, n, abs(w));
				w = -w;//'-'부호 붙이기
			}else if(i>0 && w<0){//음수(테두리 반시계방향)
				num++;
				go_back(num, n, abs(w));
				w = -w;
			}
		}
}	

int main() {
	cin>>n>>w;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>name;
			name_list[i][j] = name;
		}
	}

	if(w > 0){//양수->테두리 시계방향으로 돌아감
		determine(n,w);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<name_list[i][j];
				if(j != n-1){
					cout<<" ";
				}
			}
			cout<<"\n";
		}
	}
	else if(w == 0){//돌아가지 않고 제자리
		//입력받은 그대로 출력하면 된다.
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<name_list[i][j];
				if(j != n-1){
					cout<<" ";
				}
			}
			cout<<"\n";
		}
	}
	else{//음수->테두리 반시계방향으로 돌아감
		determine(n,w);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<name_list[i][j];
				if(j != n-1){
					cout<<" ";
				}
			}
			cout<<"\n";
		}
	}
	
	return 0;
}