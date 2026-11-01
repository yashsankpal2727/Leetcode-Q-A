class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Strict overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // 2. Count positive inputs and convert EVERYTHING to negative
        // We accumulate in negative space to prevent INT_MIN overflow
        int positives = 0;
        if (dividend > 0) {
            positives++;
            dividend = -dividend;
        }
        if (divisor > 0) {
            positives++;
            divisor = -divisor;
        }

        int quotient = 0;
        // Half of INT_MIN to check for underflow before doubling
        int HALF_INT_MIN = -1073741824; 

        // 3. Subtract maximum chunks (doubling the divisor using addition)
        while (dividend <= divisor) {
            int powerOfTwo = -1;
            int value = divisor;

            // Double the value as long as it fits inside the dividend
            // and won't underflow past INT_MIN
            while (value >= HALF_INT_MIN && dividend <= value + value) {
                value += value;
                powerOfTwo += powerOfTwo;
            }

            dividend -= value;
            quotient += powerOfTwo;
        }

        // 4. Apply correct sign to the quotient
        // If there was exactly 1 positive input, the result should be negative.
        // Otherwise, it should be positive (so we flip the negative quotient).
        return (positives == 1) ? quotient : -quotient;
    }
};