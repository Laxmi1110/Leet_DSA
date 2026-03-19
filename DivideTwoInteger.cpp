class Solution {
public:
    int divide(int dividend, int divisor) {
     
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        
        long long a = dividend;
        long long b = divisor;

       
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        long long result = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

           
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return (int)result;
    }
};
