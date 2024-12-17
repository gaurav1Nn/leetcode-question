#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n); 
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        vector<int> pse(n, -1); 
        stack<int> gt;
        for (int i = 0; i < n; ++i) {
            while (!gt.empty() && heights[gt.top()] >= heights[i]) {
                gt.pop();
            }
            if (!gt.empty()) {
                pse[i] = gt.top();
            }
            gt.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int height = heights[i];
            int breadth = nse[i] - pse[i] - 1;
            int area = height * breadth;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
