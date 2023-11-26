class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
        }
        s = "";
        while(!st.empty()){
            char element = st.top();
            s = element + s;
            st.pop();
        }
        return s;
    }
};
