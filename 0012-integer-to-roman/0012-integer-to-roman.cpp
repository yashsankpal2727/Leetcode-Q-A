class Solution {
public:
    string intToRoman(int num) {
        char symbols[]   = { 'M',  'D', 'C', 'L', 'X', 'V', 'I' };
        int  values[]    = { 1000, 500, 100,  50,  10,  5,   1  };
        char sub[]       = { 'C',  'C', 'X', 'X', 'I', 'I', '\0'};
        int  subValues[] = { 100,  100,  10,  10,  1,   1,   0 };
        string numeral;
        int i = 0;
        while (num > 0) {
            if (values[i] <= num) {
                num -= values[i];
                numeral += symbols[i];
            } else if (values[i] - subValues[i] <= num) {
                num = num - values[i] + subValues[i];
                numeral += sub[i];
                numeral += symbols[i];
            } else {
                i += 1;
            }
        }
        return numeral;
    }
};