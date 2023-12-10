class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(INT_MAX);

        for(int i=2*n-1; i>=0; i--){
            int item = nums[i%n];

            while(!s.empty() && item >= s.top()){
                s.pop();
            }

            if(s.top() == INT_MAX){
                ans[i%n] = -1;
            }
            else{
                ans[i%n] = s.top();
            }
            s.push(item);
        }
        return ans;
    }
};
