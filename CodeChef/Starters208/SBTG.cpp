#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int n,x,k;
        cin >> n >> x >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());

        for(int i=0; i<k; i++)
        {
            a[i] = 0;
            x += 100;
        }

        int max = 0;
        for(int s : a)
        {
            if(s > x)
                max++;
        }
        cout << max+1 << '\n';
    }
}
