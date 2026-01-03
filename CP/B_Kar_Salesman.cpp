#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;

        int sum = 0, mx = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
            mx = max(mx, a);
        }

        cout << max(mx, (sum + x - 1) / x) << '\n';
    }
    return 0;
}
