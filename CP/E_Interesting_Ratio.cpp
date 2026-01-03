#include <bits/stdc++.h>
using namespace std;


#define int long long


const int maxN = 10000000;
vector<bool> isPrime(maxN + 1, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = 2*i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
int32_t main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int k=1 ; k<=n ; k++){
            int x = n/k;
            for (int i = 2; i <= x; i++) {
                if (isPrime[i]) {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}