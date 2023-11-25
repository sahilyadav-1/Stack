int countRev (string s)
{
    // your code here
    int n = s.size();
    if(n&1) return -1;
    
    int ans = 0;
    stack<int> st;
    for(int i=0; i<n; i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                st.push(s[i]);
                ans++;
            }
            else{
                st.pop();
            }
        }
    }
    return ans+st.size()/2;
}
