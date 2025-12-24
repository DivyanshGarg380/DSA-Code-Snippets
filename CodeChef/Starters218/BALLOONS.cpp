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
        vector<int>arr(N);
        int cost = 0;
        for(int x = 0; x < arr.size(); x++){
            cin >> arr[x];
            cost += arr[x]*(x+1);
        }
        cout << cost << "\n";
    }
}

// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.