#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int final = 0;
int connect[40002];
int DP[40002];
 
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		DP[i] = 1;
		cin >> connect[i];
	}
 
	for (int i = 1; i <= n; i++) {
		for (int j = i-1; j > 0; j--) {
			if (connect[i] > connect[j] && DP[i] <= DP[j]) {
				DP[i] = DP[j] + 1;
			}
		}
        final = max(final, DP[i]);
	}
 
    cout<<final<<"\n";
	return 0;
}