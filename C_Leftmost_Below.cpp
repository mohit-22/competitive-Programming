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
        bool flag = true;
        // int y = 2*arr[0]-1;
        int y = arr[0];
        for(int i=1 ; i<n ; i++){
            if(arr[i]>2*y-1){
                flag=false;
                break;
            }
            y = min(y,arr[i]);
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}