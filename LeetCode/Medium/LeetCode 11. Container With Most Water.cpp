class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int L=0, R=n-1;
        int mx=0;
        while(L<R){
            mx=max(mx , (R-L)*min(height[L], height[R]) );
            if(height[L]<height[R]){
                L++;
            }else{
                R--;
            }
        }
        return mx;
    }
};