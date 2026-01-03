#include <bits/stdc++.h>
using namespace std;

#define int long long

bool canfit(int k,int arr[],int h){
    // sort(arr,arr+k,greater<int>());
    vector<int> temp(arr, arr+k);   // copy first k elements
    sort(temp.begin(), temp.end(), greater<int>());
    int sum=0;
    for(int i=0 ; i<k ; i+=2){
        sum+=arr[i];
    }
    if(sum<=h){
        return true;
    }
    return false;
}

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,h;
        cin >> n>>h;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int low = 1;
        int high = n;
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canfit(mid,arr,h)==true){
                ans = max(ans,mid);
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<ans<<endl;
    // }
    return 0;
}