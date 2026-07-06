class Solution {
    public:
        double myPow(double x, int n) {
            long long exp = n;  // 关键：n 可能是 INT_MIN，-n 会溢出
            double result = 1.0;
            double base = x;
    
            if (exp < 0) {
                exp = -exp;
                base = 1.0 / base;  // 负指数：先取倒数，再按正指数算
            }
    
            while (exp > 0) {
                if (exp & 1) {
                    result *= base; //如果指数是奇数，则结果乘以底数
                }
                base *= base; //底数平方
                exp >>= 1; //指数右移一位
            }
            return result; //返回结果
        }
    };