/*
Problem link:- https://codeforces.com/contest/2078/problem/C
*/

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
#define pb push_back
#define mll map<ll, ll>
#define umll unordered_map<ll, ll>
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vll b(2 * n);
    for (ll i = 0; i < 2 * n; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    ll sum = 0;
    vll a;
    for (ll i = 1; i < n; i++)
    { 
        a.pb(b[i]);
        a.pb(b[n + i - 1]);
        sum += b[n + i - 1] - b[i];
    }
    a.pb(sum + b[0] + b[2 * n - 1]);
    a.pb(b[0]);
    cout << b[2 * n - 1];
    for (ll i = 0; i < 2 * n; i++)
        cout << " " << a[i];
    cout << endl;
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
