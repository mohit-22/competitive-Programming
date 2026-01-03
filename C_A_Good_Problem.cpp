#include <bits/stdc++.h>
using namespace std;

#define int long long

// unsigned long long smallest_pow2_in_range(unsigned long long L, unsigned long long R) {
//     const unsigned long long LIMIT = 1000000000000000000ULL; // 1e18
//     unsigned long long p = 1ULL;
//     // Fast-forward p to be >= L
//     while (p < L) {
//         if (p > LIMIT) break; // safety (though not strictly needed)
//         p <<= 1;
//     }
//     if (p >= L && p <= R) return p;
//     return 0ULL;
// }


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,r,k;
        cin >> n>>l>>r>>k;

        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        if(n%2!=0){
            cout<<l<<endl;
            continue;
        }

        if (l == r) {
            cout << -1 << '\n';
            continue;
        }
        // else{
        //     if(l!=r){
        //         bool flag = false;
        //         int w = -1;
        //         for(int i=l+1 ; i<=r ; i++){
        //             if(__builtin_popcountll(i)==1 && i!=1){
        //                 w = i;
        //                 flag = true;
        //                 break;
        //             }
        //         }   
        //         if(flag){
        //             int x = n-2;
        //             if(k>x) cout<<w<<endl;
        //             else cout<<l<<endl;
        //             // cout<<w<<endl;
        //         }
        //         else cout<<-1<<endl;
        //     }
        //     else cout<<-1<<endl;
        // }


        // unsigned long long L = (unsigned long long)(l + 1); // original loop started at l+1
        // unsigned long long R = (unsigned long long)r;
        // unsigned long long p = smallest_pow2_in_range(L, R);

        // if (p == 0ULL || p == 1ULL) {
        //     cout << -1 << '\n';
        //     continue;
        // }

        int power = floor(log2(l));
        int p = pow(2,power+1);

        if(p>r){
            cout<<-1<<endl;
            continue;
        }

        // your current heuristic: if k > n/2 output p else output l
        // (I preserved your logic here; note: correctness of the heuristic is separate)
        long long x = n-2;
        if (k > x) cout << p << '\n';
        else cout << l << '\n';
        
    }
    return 0;
}