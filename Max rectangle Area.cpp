/*You are required to complete this method*/

class Solution{
    
  private:
    vector<int> nextSmaller(int* arr,int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int item = arr[i];

            while(s.top() != -1 && arr[s.top()] >= item){
                s.pop();
            } 

            if(s.top() == -1){
                ans[i] = n;
            }
            else{
                ans[i] = s.top();
            }
            
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(int* arr, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int item = arr[i];

            while(s.top() != -1 && arr[s.top()] >= item){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n) {
        vector<int> next = nextSmaller(heights,n);
        vector<int> prev = prevSmaller(heights,n);
        
        int ans=INT_MIN;

        for(int i=0; i<n; i++){
            int len = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int area = len*breadth;
            ans = max(ans,area);

        }
        return ans;
    }
    
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(M[i][j] != 0)
                    M[i][j] += M[i-1][j];
                else
                    M[i][j] = 0;
                
            }
            
            area = max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};
