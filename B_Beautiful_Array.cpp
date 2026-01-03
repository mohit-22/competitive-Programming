

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,b,s;
        cin >> n>>k>>b>>s;

        if (k * b > s || (k*b)+(k-1)+(n-1)*(k-1)<s ) {
            cout << -1 << endl;
            continue;
        }
        
        vector<int>v(n,0);
        v[0] = k*b;
        s -=k*b;
        for(int i=0 ; i<n ; i++){
            int add = min(k-1,s);
            v[i]+=add;
            s-=add;
        }

        for(int i=0 ; i<n ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}