#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int ans=-1;
        for(int id=2 ; id<=60 ; id++){
            bool flag = false;
            for(int i=0 ; i<n ; i++){
                if(gcd(arr[i],id)==1){
                    flag=true;
                    break;
                }
            }
            if(flag){
                ans=id;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}