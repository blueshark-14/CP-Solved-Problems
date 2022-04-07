class Solution {
public:
    int divide(long long dividend, long long divisor) {
           
        
        bool neg=false;
        
        if( dividend<0 && divisor>0 ) {neg=true;}
        if(dividend>0 && divisor<0) {neg=true;  }
        
        if(dividend<0)  dividend = (-1)*dividend ;
        if(divisor<0)  divisor = (-1)*divisor ;
        
        vector<int>v;
        long long x=(long long)dividend;
        while(x){  /// e.g.  1234  into array :  1  2  3  4
            v.push_back(x%10);
            x/=10;
        }
        
        reverse(v.begin(), v.end());
        long long n=0,  ans=0;
        
        for(int i=0; i<v.size(); i++){
            
            n=n*10+v[i];
            
            bool ok=false;
            
            if(n>=divisor){
                ok=true;
                long long sum=0; int i ;
                for( i=1;  ; i++){
                    if(sum+divisor> n) {  i--;break;}
                    sum+=divisor;
                }
                
                ans=ans*10+i; /// quotient
                n=n-sum;       
            }
            
            if(!ok) ans=ans*10; /// if taking extra digit n< divisor
           
        }
        
        if(neg) ans= ans*(-1);  /// if negative ans
       if(ans>2147483647) ans=2147483647; /// overflow condition
        return ans;
    }
};