#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        int mn=INT_MAX;
        int ct=0;
        int ct2=0;
        bool flag = false;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            arr[i] = arr[i]%k;
            if(arr[i]==0){
                flag = true;
            }
            mn = min(mn,k-arr[i]);
            if(arr[i]%2==0) ct++;
            else ct2++;
        }
        if(flag==true){
            cout<<0<<endl;
            continue;
        }
        if(k!=4) cout<<mn<<endl;
        else{
            if(ct>=2) cout<<0<<endl;
            else if(ct==0){
                cout<<min(mn,2LL)<<endl;
            }
            else cout<<1<<endl;
        }

        
    }
    return 0;
}