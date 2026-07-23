class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        int carry = b;

        while ((a & b) != 0) {
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        }

        return a | b;
    }
};
