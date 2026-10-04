class Solution {
public:
    bool checkValidString(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

        function<bool(int, int)> dfs = [&](int index, int balance) -> bool {
            if (balance < 0)
                return false;
            if (index == n)
                return balance == 0;

            int& result = memo[index][balance];
            if (result != -1)
                return result == 1;

            bool valid;
            if (s[index] == '(') {
                valid = dfs(index + 1, balance + 1);
            } else if (s[index] == ')') {
                valid = dfs(index + 1, balance - 1);
            } else {
                valid = dfs(index + 1, balance) ||
                        dfs(index + 1, balance + 1) ||
                        dfs(index + 1, balance - 1);
            }

            result = valid ? 1 : 0;
            return valid;
        };

        return dfs(0, 0);
    }
};