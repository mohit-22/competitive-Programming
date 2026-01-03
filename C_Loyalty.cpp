#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n>>x;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // int s=0;
        // int i=0;
        // int ans=0;
        // while(s<x && i<n){
        //     s+=arr[i];
        //     if(s>=x){
        //         ans+=arr[i];
        //         i++;
        //         break;
        //     }
        //     i++;
        // }
        // int y = s/x;
        // // cout<<y<<endl;
        // for(int j=i ; j<n ; j++){
        //     s+=arr[j];
        //     if(s/x>y){
        //         y=s/x;
        //         ans+=arr[j];

        //     }
        // }
        // cout<<ans<<endl;
        // for(int i=0 ; i<n ; i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        int i=0;
        int j=n-1;
        int s=0;
        vector<int>v;
        int ans=0;
        while(i<=j){
            if((s+arr[j])/x>s/x){
                v.push_back(arr[j]);
                s+=arr[j];
                ans+=arr[j];
                j--;
            }
            else{
                v.push_back(arr[i]);
                s+=arr[i];
                i++;
            }

        }
        cout<<ans<<endl;
        for(int i=0 ; i<n ; i++){
            cout<<v[i]<<" "; 
        }
        cout<<endl;
        
    }
    return 0;
}