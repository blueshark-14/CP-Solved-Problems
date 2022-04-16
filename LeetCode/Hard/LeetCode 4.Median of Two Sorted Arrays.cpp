class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 
        int n,m;
        n=nums1.size();
        m=nums2.size();
        
        int a[n+2];
        int b[m+2];
        a[0]=-10000007;
        a[n+1]=10000007;
        b[0]=-10000007;
        b[m+1]=10000007;
        int i=1;
        for(auto x:nums1) a[i++]=x;
        i=1;
        for(auto x:nums2) b[i++]=x;
        
        int L=0, R=m+1, M;
        int half = (n+m)/2;
         double ret;
        while(L<=R){
            
            M = (L+R)/2;
          
            int index_a=half-M; 
            
            if( (index_a<n+2 && index_a>-1) && a[index_a]<=b[M+1] && a[index_a+1]>=b[M]){
               
                if((n+m)%2){
                    ret=(double)min(b[M+1]  , a[index_a+1]);
                }else {
                   ret=(double)(  max(b[M], a[index_a]) + min(b[M+1], a[index_a+1]) )/2;
                }
                break;
            }else if( index_a>=n+2 || ( index_a>-1 && b[M] < a[index_a]) ){
              L=M+1;  
            }else if( index_a<0 || ( index_a<n+2 && b[M] > a[index_a]) ) {
                R=M-1;
            }       
            
        }
        
        return ret;
        
    }
};