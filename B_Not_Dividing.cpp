

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
        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i = 0 ; i<n-1;i++){
            if (arr[i]==1){
                arr[i]++;
            }
            while(arr[i+1]%arr[i]==0 ){
                arr[i+1] +=1;
            }
            if(i!=0){
                while( arr[i]%arr[i-1]==0){
                    arr[i]+=1;
                }
            }
        }
        if(arr[n-1]%arr[n-2]==0) arr[n-1]++; 
        for(int i = 0 ;i<n ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}