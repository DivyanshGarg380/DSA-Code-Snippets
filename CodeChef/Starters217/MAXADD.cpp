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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        long long S = 0;
        for (long long x : B) S += x;

        long long pref = 0;
        long long K = LLONG_MIN;
        for (int i = 0; i < N; i++) {
            pref += B[i];
            long long cand = A[i] + (S - pref);
            K = max(K, cand);
        }

        long long t = max(1LL, K - S);

        long long ans = 0;

        if (t > M) {
            ans = M * K;
        } else {
            ans += (t - 1) * K;
            long long cnt = M - t + 1;
            long long sumX = (t + M) * cnt / 2;
            ans += sumX + cnt * S;
        }

        cout << ans << '\n';
    }
    return 0;
}

// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.