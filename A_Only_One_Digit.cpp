#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s = to_string(n);
        char mn = s[0];  

        for (int i = 1; i < s.length(); i++) {
            if (s[i] < mn) {
                mn = s[i];  // Update if a smaller digit is found
            }
        }

        cout << mn << endl;
    }
    return 0;
}
