#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int M, N;
	int dp[100001] = {0, },
		candy[100001] = {0, },
		row[100001] = {0, },
		num[100001] = {0, };

	while (1) {
		scanf("%d %d", &M, &N);
		if (N == 0 &&  M == 0) { 
			return 0;
		}

		for (int i = 1; i <= M; i++){
			for (int j = 1; j <= N; j++) {
				scanf("%d", &candy[j]);
			}
			num[1] = candy[1];
            //행
			for (int j = 2; j <= N; j++) {
				num[j] = max(num[j - 1], num[j - 2] + candy[j]);
			}
			row[i] = num[N];
		}
        
        //열
		dp[1] = row[1];
		for (int i = 2; i <= M; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + row[i]);
		}

		printf("%d\n", dp[M]);
	}
}