class Solution {
    int fx[4]={0, 0, 1, -1};
    int fy[4]={1, -1, 0, 0};
    int dp[202][202];
    /// recursion function
    int recur(vector<vector<int>>& matrix, int i, int j, int n, int m){
        if(dp[i][j] != -1){
             return  dp[i][j];
        }
        int mx=0, cnt=1;
        for(int k=0; k<4; k++){
           int vx=i+fx[k];
           int vy=j+fy[k];
          
         if( (vx>=0&&vx<n) && (vy>=0 && vy<m) && (matrix[i][j] < matrix[vx][vy] ) ) {
             cnt=1+recur(matrix , vx, vy, n , m);
         }
          mx=max(mx, cnt);  
            
       }
        
        return dp[i][j]=mx;
        
    } 
public:
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         
        int n=matrix.size();
        int m=matrix[0].size();
       
        memset(dp, -1, sizeof(dp));
        int mx=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 
                int tm=recur(matrix , i, j, n,m);
                if(mx<tm) mx=tm;
            }
        }
        
        return mx;
        
    }
};