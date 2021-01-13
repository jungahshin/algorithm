class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        vector<int> v;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i++]);
            }else{
                v.push_back(nums2[j++]);
            }
        }
        
        if(i<nums1.size()){
            while(i<nums1.size()){
                v.push_back(nums1[i++]);
            }
        }else{
            while(j<nums2.size()){
                v.push_back(nums2[j++]);
            }
        }
                
        int idx = v.size()/2;
        
        if(v.size()%2==0){
            ans = (double)(v[idx]+v[idx-1])/2;
        }else{
            ans = (double)v[idx];
        }
        
        return ans;
    }
};