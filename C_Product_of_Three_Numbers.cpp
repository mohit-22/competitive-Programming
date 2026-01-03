#include <bits/stdc++.h>
using namespace std;

#define int long long

// vector<long long> prime_factors(long long n) {
//     vector<long long> f;
//     while (n % 2 == 0) { f.push_back(2); n /= 2; }
//     for (long long d = 3; d * d <= n; d += 2) {
//         while (n % d == 0) { f.push_back(d); n /= d; }
//     }
//     if (n > 1) f.push_back(n);
//     return f;
// }

vector<long long> distinct_factors(long long n) {
    vector<long long> res;
    for (long long d = 2; d<=sqrt(n); d++) {
        if (n % d == 0) {
            res.push_back(d);
            n /= d;
        }
        if (res.size() == 2) break; // stop early to leave a big last factor
    }
    if (n > 1) res.push_back(n);
    return res;
}


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        long long n; cin >> n;
        auto f = distinct_factors(n);
        set<int>s;
        for(int i=0 ; i<f.size() ; i++){
            s.insert(f[i]);
        }
        if(s.size()<3) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(auto it : s){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}