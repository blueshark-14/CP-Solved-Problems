class Solution {
    
public:
  
    int minCostII(vector<vector<int>> &costs) {
       
        if(costs.size() == 0) return 0;
        int n=costs.size();
        int m=costs[0].size();
       
        int tot_1=0, tot_2=0, carry=-1;

        for(int i=0; i<n; i++){
            int mn1=2147483647, mn2=0,k, cost;
            for(int j=0; j<m; j++){
                cost=costs[i][j]+((j==carry) ? tot_2 : tot_1) ;
                if(cost<mn1){
                    mn2=mn1;
                    mn1=cost;
                    k=j;
                }else if(cost<mn2) mn2=cost;
            }
            tot_1=mn1;
            carry=k;
            tot_2=mn2;
        } 
    
       return tot_1;
    }
};