class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            auto st = stack<int>();
            int n = heights.size();
            int m = 0;
    
            for(int i = 0; i <= n; i++) {
                int h = (i == n) ? 0 : heights[i];
                
                while(!st.empty() && h < heights[st.top()]) {
                    int t = st.top(); st.pop();
    
                    int height = heights[t];
                    int r = i - 1;
                    int l = st.empty() ? 0 : st.top() + 1;
                    int w = r - l + 1;
                    m = max(m, w * height);
                }
    
                st.push(i);
            }
            return m;
        }
    };