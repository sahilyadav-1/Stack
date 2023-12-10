class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string str = "";
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }

                st.pop();

                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }

                int k_times = stoi(number);
                while(k_times--){
                    for(int i=0; i<str.length(); i++){
                        st.push(str[i]);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
