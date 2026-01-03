#include <bits/stdc++.h>
using namespace std;

#define int long long

long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout<<(n*n)/4+1<<endl;
        
    }
    return 0;
}