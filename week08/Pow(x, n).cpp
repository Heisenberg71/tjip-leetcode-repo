class Solution {
private:
double power(double x, int n)
{
    if(n == 0) return 1;
    double ans_with_power = power(x, n/2);
    ans_with_power *= ans_with_power;
    if(n%2) ans_with_power *= x;
    return ans_with_power;
}
public:
    double myPow(double x, int n) {
        if(n < 0) return power(1.0/x, abs(n));
        return power(x, n);
    }
};
