class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<vector<char>> mat(numRows, vector<char>(s.size(), '0'));

        int i = 0;
        int col = 0;

        while (i < s.size()) {
            for (int row = 0; row < numRows && i < s.size(); row++) {
                mat[row][col] = s[i++];
            }

            for (int row = numRows - 2; row > 0 && i < s.size(); row--) {
                col++;
                mat[row][col] = s[i++];
            }

            col++;
        }

        string res = "";
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c <= col; c++) {
                if (mat[r][c] != '0') res += mat[r][c];
            }
        }

        return res;
    }
};