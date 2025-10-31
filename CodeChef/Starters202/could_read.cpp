#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define inp(a,n) for(ll i=0;i<n;i++){cin>>a[i];}
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend() 
const ll mod=1e9+7;

ll apowb(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
        if(exp%2!=0) res*= base;
        base*=base;
        exp/=2;
    }
    return res;
}

ll mod_pow(ll base, ll exp, ll mod) {
    ll res=1; 
    base%=mod;
    while(exp>0) {
        if(exp%2!=0) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    vi as = a;
    sort(all(as));
    if(as == a){
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<i+1<<" "<<i+2<<'\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
