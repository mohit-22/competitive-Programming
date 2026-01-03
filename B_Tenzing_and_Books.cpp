#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int k = 0;
        bool flag = false;
        vector<int>a(n);

        for(int j=0 ; j<3 ; j++){  
            for(int i=0 ; i<n ; i++){
                cin >> a[i];
            }
            for(int i=0 ; i<n ; i++){
                if( (x | a[i]) != x ) break;
                k |= a[i];
            }
        }


        if(k==x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
