class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
       stack<pair<char, int>>st;
        
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                if(!st.empty()){
                    if(st.top().first == '('){
                        st.pop();
                    }else{
                        st.push({')', i+1 });
                    }
                }else{
                    st.push({')', i+1});
                }
            }else{
                st.push({'(', i+1});
            }
        }
        
        
        int mx=0, pos=n;
        int tm=n;
        while(!st.empty()){
            pos = st.top().second;
            mx=max(mx,  tm-pos);
            tm=pos-1;
            st.pop();
            pos--;
           
        }
        
       mx=max(mx , pos);
          
        return mx;
    }
};