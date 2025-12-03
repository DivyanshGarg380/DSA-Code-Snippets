/*
Problem link:- https://codeforces.com/contest/2093/problem/B
*/

#include <bits/stdc++.h>
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif
#define ll long long
#define vll vector<ll>
#define vi vector<int>  
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    bool met_positive = false;
    int count_zero = 0;

    for (auto i = n - 1; i >= 0; --i)
    {
        if (s[i] != '0')
        {
            met_positive = true;
        }
        else if (met_positive)
        {
            count_zero++;
        }
    }

    cout << n - (count_zero + 1) << '\n';
}

int main()
{
    ll t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
