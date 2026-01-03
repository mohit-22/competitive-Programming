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
        // int x = arr[n-1];
        // int ct=0;
        // int ans=0;
        // for(int i=n-1 ; i>=0 ; ){
        //     int m = i;
        //     while( i>=0 && arr[i]==x){
        //         ct++;
        //         i--;
        //     }
        //     m-=ct*2;
        //     m++;
        //     i=m-1;
        //     if(m>=0){
        //         ans++;
        //     }

        // }
        // cout<<ans<<endl;



        int x = arr[n-1];
        int ct=0;
        int ans = 0;
        for(int i=n-1 ; i>=0 ;i--){
            while(i>=0 && arr[i]==x){
                ct++;
                i--;
            }
            i++;
            i = n-2*(n-i);
            i--;
            if(i>=0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}