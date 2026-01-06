#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],brr[n];
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }

        for(int i=1 ; i<n ; i++){
            if(arr[i]>arr[i-1]){
                flag=false;
                break;
            }
            if(brr[i]<brr[i-1]){
                flag=false;
                break;
            }
            
        }
        
        int crr[n];
        for(int i=0 ; i<n ; i++){
            crr[i] = lcm(arr[i],brr[i]);
            if(arr[i]%brr[i]!=0 && brr[i]%arr[i]!=0){
                flag = false;
                break;
            }
        }

        for(int i=1 ; i<n ; i++){
            if(gcd(crr[i],arr[i-1])!=arr[i]){
                flag=false;
                break;
            }
        }

        for(int i=n-2 ; i>=0 ; i--){
            if(gcd(crr[i],brr[i+1])!=brr[i]){
                flag = false;
                break;
            }
        }

        if(n==1){
            if(arr[0]==brr[0]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            if(!flag) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }


        
        
    }
    return 0;
}