/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int>A(N),C(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        for(int i = 0; i < N; i++){
            cin >> C[i];
        }
        vector<int> ans = C;
        for(int i = 1; i < N; i++){
            ans[i] = min(ans[i], ans[i - 1]);
        }
        long long sum = 0;
        for(long long i = 0; i < N; i++){
            sum += ans[i] * A[i];
        }
        cout << sum << endl;
    }
}


// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.