class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            if(s[i] == 'a' || s[i] == 'b'){
                st.push(s[i]);
            }
            else if(s[i] == 'c' && st.size() >= 2){
                char ch = s[i];
                char b = st.top();
                st.pop();
                char a = st.top();
                st.pop();

                if(!(a == 'a' && b == 'b' && ch == 'c')){
                    st.push(a);
                    st.push(b);
                    st.push(ch);
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
