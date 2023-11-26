class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;

        for(int i=nums2.size()-1; i>=0; i--){
            int element = nums2[i];

            while(!s.empty() && element>=s.top()){
                s.pop();
            }

            if(!s.empty()){
                mp[element] = s.top(); 
            }
            else{
                mp[element] = -1;
            }
            s.push(element);
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};
