class Solution {
public:
  
    int minTotalDistance(vector<vector<int>> &grid) {
        vector<int>X, Y;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    X.push_back(i);
                    Y.push_back(j);
                }
            }
        }
        int res=0;
        int mid = (X.size())/2;
        for(int i=0; i<X.size(); i++){
            res+=abs(X[i]-X[mid]);
        }
        sort(Y.begin(), Y.end());
        mid = (Y.size())/2;
        for(int i=0; i<Y.size(); i++){
            res+=abs(Y[i]-Y[mid]);
        } 
        return res;      
    }
};