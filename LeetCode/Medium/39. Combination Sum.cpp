class Solution {
public:
    vector<vector<int>>vv;
    vector<int>v;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int sum=0, int i=0) {
        
        if(i>=candidates.size()) return vv;
        if(sum == target){
            vv.push_back(v);
            return vv;
        }
        
           if(sum+candidates[i]<=target) { 
               v.push_back(candidates[i]) ;
               combinationSum(candidates, target, sum+candidates[i], i);
               v.pop_back(); 
           }
            
            combinationSum(candidates, target, sum, i+1);
         
     
        
        return vv;
    }
};