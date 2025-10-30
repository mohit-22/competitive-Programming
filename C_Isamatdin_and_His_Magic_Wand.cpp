#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        bool even = false;
        bool odd = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0) even = true;
            else odd = true;
        }
        vector<long long> b = a;
        if (even && odd) {
            sort(b.begin(), b.end());
            for (int i = 0; i < n; ++i) {
                cout << b[i]<<" ";
            }
        } 
        else {
            for (int i = 0; i < n; ++i) {
                cout << a[i]<<" ";
            }
           
        }
         cout <<endl;
    }
    return 0;
}
