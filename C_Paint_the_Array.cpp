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
        for(int i=0  ;i<n ; i++){
            cin>>arr[i];
        }
        bool flag = true;
        for(int i=0 ; i<n-1 ;i++){
            if(arr[i]==arr[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==false){
            cout<<0<<endl;
            continue;
        }
        int ans1=0;
        for(int i=0 ; i<n ; i+=2){
            ans1 = __gcd(ans1,arr[i]);
        }
        int ans2=0;
        for(int i=1 ; i<n ; i+=2){
            ans2 = __gcd(ans2,arr[i]);
        }
        // if(ans1!=ans2){
        //     cout<<max(ans1,ans2)<<endl;
        // }

        bool found1=true,found2=true;
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i]%ans1==0 && arr[i+1]%ans1==0){
                found1=false;
            }
            if(arr[i]%ans2==0 && arr[i+1]%ans2==0){
                found2=false;
            }
        }
        if(found1==true){
            cout<<ans1<<endl;
        }
        else if(found2==true){
            cout<<ans2<<endl;
        }
        else{
            cout<<0<<endl;
        }

        // else cout<<0<<endl;
    }
    return 0;
}