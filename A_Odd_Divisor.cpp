#include <bits/stdc++.h>
using namespace std;

#define int long long

bool hasOddDivisor(int n) {
    while (n % 2 == 0) {
        n /= 2;  
    }
    return (n > 1); 
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 != 0) 
            cout << "YES" << endl;  
        else {
            if (hasOddDivisor(n)) 
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    return 0;
}
