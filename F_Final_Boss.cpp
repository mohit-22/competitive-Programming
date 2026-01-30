#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int64 h;
        int n;
        cin >> h >> n;
        vector<int64> a(n), c(n);
        for(int i=0;i<n;++i) cin >> a[i];
        for(int i=0;i<n;++i) cin >> c[i];

        auto enough = [&](int64 T)->bool{
            __int128 total = 0;
            for(int i=0;i<n;++i){
                int64 uses = (T - 1) / c[i] + 1;
                total += (__int128)uses * a[i];
                if(total >= h) return true;
            }
            return total >= h;
        };

        int64 low = 1, high = 1;
        while(!enough(high)){
            high = min<int64>(high * 2, (int64)9e18);
        }

        while(low < high){
            int64 mid = low + (high - low) / 2;
            if(enough(mid)) high = mid;
            else low = mid + 1;
        }
        cout << low << '\n';
    }
    return 0;
}