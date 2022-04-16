class Solution {
public:
    int trap(vector<int>& height) {
        int mx=0;
        int pos=-1;
        for(int i=0; i<height.size(); i++){
            if(mx<height[i]){
                mx=height[i];
                pos=i;
            }
        }
        
        if(pos == -1) return 0;
        
        int result=0;
        mx=0;
        for(int i=0; i<pos; i++){
            if(mx>height[i]){
                result+=(mx-height[i]);
            }else if(mx<height[i]){
                mx=height[i];
            }
        }
        mx=0;
        for(int i=height.size()-1 ; i>pos ;i--){
            if(mx>height[i]){
                result+=(mx-height[i]);
            }else if(mx<height[i]){
                mx=height[i];
            }
        }
        
        return result;
    }
};