class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cnt=0, start=0, end=0, n = nums.size();
        while(end < n-1){
            cnt++;
            int max_end=end+1;
            for(int i=start ; i<=end; i++){
                if(i+nums[i]>=n-1) return cnt;
                max_end=max(max_end , i+nums[i]);
            }
            start=end+1;
            end = max_end;
        }         
        return cnt;
    }
};