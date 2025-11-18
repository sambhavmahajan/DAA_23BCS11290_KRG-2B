class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(arr[i]);
        }
        return res;
    }
};
