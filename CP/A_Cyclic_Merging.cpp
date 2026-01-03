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
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            if(arr[i]>=arr[j]){
                // arr[j]=min(max(arr[j],arr[j-1]),max(arr[i],arr[j]));
                ans+=min(max(arr[j],arr[j-1]),max(arr[i],arr[j]));
                j--;
            }
            else{
                // arr[i]=min(max(arr[i],arr[i+1]),max(arr[i],arr[j]));
                ans+=min(max(arr[i],arr[i+1]),max(arr[i],arr[j]));
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}