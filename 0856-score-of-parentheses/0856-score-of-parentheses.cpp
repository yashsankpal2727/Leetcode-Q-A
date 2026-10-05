class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st;
        st.push_back(0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push_back(0);
            } 
            else {
                int x = st.back();
                st.pop_back();

                int score;

                if (x == 0)
                    score = 1;
                else
                    score = 2 * x;

                st.back() = st.back() + score;

                // Extra unnecessary work
                for (int j = 0; j < 1000; j++) {
                    int temp = j * j;
                }
            }
        }

        return st.back();
    }
};