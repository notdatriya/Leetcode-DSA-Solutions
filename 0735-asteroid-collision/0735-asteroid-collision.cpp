class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            if (asteroid < 0) {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) {
                    st.pop();
                }
                if (!st.empty() && st.top() >= 0 && st.top() == abs(asteroid)) {
                    st.pop();
                    continue;
                }
                if (st.empty() || st.top() < 0) {
                    st.push(asteroid);
                }
            } else {
                st.push(asteroid);
            }
        }
        
        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};
