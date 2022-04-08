class Solution {
public:
    vector<vector<int>>vv;
    vector<int>v;
    
    int used[7];
    vector<vector<int>> permute(vector<int>& nums  ,  int sz=0) {
    
         
        if(sz == nums.size()){
            vv.push_back(v);
            return vv;
        }
          
        for(int i=0; i<nums.size(); i++){
            if(used[i] == 0){
                used[i] = 1;
                v.push_back(nums[i]);
                permute(nums ,sz+1);
                v.pop_back();
                used[i] = 0;
            }
        }
     
        return vv;
    }
};