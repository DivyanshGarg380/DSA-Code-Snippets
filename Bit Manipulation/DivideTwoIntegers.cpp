#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    bool sign = (dividend < 0 == divisor < 0);
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    while(a>=b){
        short q = 0;
        while(a > (b << (q+1))) q++;
        ans += (1<<q);
        a -= (b << q);
    }
    if(ans == (1<<31) && sign) return INT_MAX;
    return sign ? ans : -ans;
}

// TC: O(log(n)^2)
// SC: O(1)