#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==2){
            cout<<-1<<" "<<2<<endl;
            continue;
        }
        for(int i=0 ; i<n ; i++){
            if(i%2==0){
                cout<<-1<<" ";
            }
            else cout<<3<<" ";
        }
        cout<<endl;
    }
    return 0;
}