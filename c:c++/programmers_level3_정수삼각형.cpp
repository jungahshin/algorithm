//정수 삼각형
#include <string>
#include <vector>

using namespace std;

int dp[501][501] = {0, };//자기 자신까지 더한 지금까지의 경로
int dx[2] = {-1, -1};
int dy[2] = {-1, 0};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=0; i<triangle.size(); i++){
        for(int j=0; j<triangle.size(); j++){
            dp[i][j] = -1;
        }
    }
    //왼쪽, 오른쪽 가에 있는 숫자들(triangle[i][0])
    int temp = 0;
    int temp_1 = 0;
    for(int i=0; i<triangle.size(); i++){
        temp += triangle[i][0];
        temp_1 += triangle[i][i];
        dp[i][0] = temp;
        dp[i][i] = temp_1;
    }

    for(int i=0; i<triangle.size(); i++){
        for(int j=0; j<triangle.size(); j++){
            if(dp[i][j] != -1){
                continue;
            }else{//아직 정의되지 않았으면
                for(int k=0; k<2; k++){
                    int final_x = dx[k]+i;
                    int final_y = dy[k]+j;
                    if(final_x<final_y || final_y<0){
                        break;
                    }
                    //범위 안에 있다면
                    dp[i][j] = max(dp[i][j], dp[final_x][final_y]+triangle[i][j]);
                }
            }
        }
    }
    //다 돌고 나서 dp[triangle.size()-1][i] 중 가장 큰 값
    for(int i=0; i<triangle.size()-1; i++){
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    return answer;
}