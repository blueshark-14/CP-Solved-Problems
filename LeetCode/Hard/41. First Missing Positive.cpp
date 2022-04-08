class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        int v[500005];
        
        for(int i=1; i<=500001; i++){
            v[i]=0;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=500001){
                v[nums[i]]=1;
            }
        }
        int ans;
        for(int i=1; i<=500001; i++){
            if(v[i] == 0){
                ans=i;
                break;
            }
        }
        
        return ans;
        
    } 
};