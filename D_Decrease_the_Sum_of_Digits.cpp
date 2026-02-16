#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull sum_digits(ull x){
    ull s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ull n;
        int s;
        cin >> n >> s;

        if(sum_digits(n) <= s){
            cout << 0 << "\n";
            continue;
        }

        ull ans = 0;

        for(int k=0;k<=18;k++){
            while(sum_digits(n) > s){
                ull add = 1;
                for(int i=0;i<=k;i++) add *= 10;
                ull need = add - (n % add);
                if(need == add) break;
                n += need;
                ans += need;
            }
        }

        cout << ans << "\n";
    }
}