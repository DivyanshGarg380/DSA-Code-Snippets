/*
Problem link:- https://codeforces.com/contest/2093/problem/B
*/
// This code is contributed and not written by the repo owner
#include <bits/stdc++.h>
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define wh(t) while (t--)
#define fi(n) for (ll i = 0; i < n; i++)
#define fj(n) for (ll j = 0; j < n; j++)
#define fu(i, s, e) for (ll i = s; i <= e; i++)
#define fd(i, s, e) for (ll i = s; i >= e; i--)
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<string> a(n);
    fi(n) cin >> a[i];

    fi(n)
    {
        fj(m)
        {
            if (a[i][j] == '1')
            {
                ll row(0);
                fu(k, 0, j)
                {
                    if (a[i][k] == '1')
                        row++;
                }

                ll col = 0;
                for (ll k = 0; k <= i; k++)
                {
                    if (a[k][j] == '1')
                        col++;
                }

                if (row < j + 1 && col < i + 1)
                {
                    cout << "nO\n";
                    return;
                }
            }
        }
    }
    cout << "YeS\n";
}

int main()
{
    ll t;
    t = 1;
    cin >> t;
    wh(t)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
