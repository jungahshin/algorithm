class Solution {
public:
    int visited[2001] = {0, };
    
    bool check(int Start, int End, string s){
        int half = (End+1-Start)/2; // 양쪽을 비교할 횟수
        for(int i=0; i<half; i++){
            if(s[Start+i]!=s[End-i]) return false;
        }
        return true;
    }
    
    int minCut(string s) {
        queue<int> q;
        q.push(0);
        int cuts = 0;
        
        while(1){
            int size = q.size();
            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();
                if(visited[curr]) continue;
                                
                // curr~j까지 팰린드롬이 되는 곳을 저장
                // 맨 마지막 혼자 남아도 팰린드롬이 되기 때문에 curr값까지 포함!
                for(int j=s.size()-1; j>=curr; j--){
                    if(!check(curr, j, s) || visited[j]) continue;
                    if(j==s.size()-1){
                        return cuts;
                    }
                    q.push(j+1);
                }
                visited[curr] = true;
            }
            
            cuts++;
        }
        
        return cuts;
    }
};