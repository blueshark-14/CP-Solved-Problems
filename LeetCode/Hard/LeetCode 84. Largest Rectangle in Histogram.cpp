class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int L_small[n+1], R_small[n+1];

        L_small[0]=-1;
        R_small[n-1]=n;
        for(int i=0; i<n; i++){
            int p=i-1;
            while(p>=0 && heights[p]>=heights[i]){
                p=L_small[p];
            }
            L_small[i]=p;
        }
        
        for(int i=n-1; i>=0; i--){
            int p=i+1;
            while(p<n && heights[p]>=heights[i]){
                p=R_small[p];
            }
            R_small[i]=p;
        }
        int mx=0;
        for(int i=0; i<n; i++){
            int tm=heights[i]*(R_small[i]-L_small[i]-1);
            mx=max(mx, tm);
        }
        return mx;
    }
};