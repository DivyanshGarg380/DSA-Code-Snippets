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
        string S;
        cin >> S;
        int balance = 0;
        int ways = 0;
        for(int i = 0; i < S.size(); i++){
            char ch = S[i];
            if(ch == '1') balance++;
            else balance--;
            if(balance > 0) ways++;
        }
        cout << ways << "\n";
    }
}


// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.