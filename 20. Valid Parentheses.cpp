class Solution {
public:
    
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n==1){
            return false;
        }
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else if (s[i] == '}'){
                 if(!st.empty() && st.top() == '{'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else if (s[i] == ']'){
                 if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
