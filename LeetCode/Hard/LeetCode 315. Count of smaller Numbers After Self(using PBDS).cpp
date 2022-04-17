#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       
 tree<
       int,
     null_type,
     less_equal<int>,
     rb_tree_tag,
     tree_order_statistics_node_update>t;
        
        int n=nums.size();
        vector<int>res(n);
        for(int i=n-1; i>=0; i--){
            t.insert(nums[i]);
            res[i]=t.order_of_key(nums[i]);
        }
        return res;
    }
};