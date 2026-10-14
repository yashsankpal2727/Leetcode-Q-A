
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) {
            return "";
        }

        int q = sum / 9;
        int r = sum % 9;

        string result;

        result.append(q, '9');

        if (r > 0) {
            result += char('0' + r);
        }

        int zeros = num - q - (r > 0 ? 1 : 0);
        result.append(zeros, '0');

        return result;
    }
};