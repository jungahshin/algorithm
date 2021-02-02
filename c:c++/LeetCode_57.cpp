class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
           int Start = intervals[i][0];
           int End = intervals[i][1];
            bool check = false;
 
            for(int j=0; j<ans.size(); j++){
                if(ans[j][1]>=Start){
                    check = true;
                    if(ans[j][1]<End){
                        ans[j][1] = End;
                    }
                    break;
                }
            }
            
            if(check==false){
                vector<int> temp;
                temp.push_back(Start);
                temp.push_back(End);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};