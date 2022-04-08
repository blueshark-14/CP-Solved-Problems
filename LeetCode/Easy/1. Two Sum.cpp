class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         vector<int>v;
        vector<pair<int, int>>a;
        
        for(int i=0; i<nums.size(); i++){
            a.push_back({nums[i], i } );
        }
        
        sort(a.begin() , a.end());
       
        int lo, hi, mid, pos, val;
        for(int i=0; i<a.size() ; i++){
            val =target - a[i].first ;
            pos=-1;
            lo= i+1, hi = a.size()-1;
            while(lo<=hi){
                mid=(lo+hi)/2;
                
                if(a[mid].first == val) {pos=a[mid].second ; break;}
                else  if(a[mid].first>val) hi=mid-1;
                else lo = mid+1;
            }
            
            if(pos!=-1){
               
                v.push_back(a[i].second);
                v.push_back(pos);
                break;
            }
            
        }
        
        return v;
        
    }
};