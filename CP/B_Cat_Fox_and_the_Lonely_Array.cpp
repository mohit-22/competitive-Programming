#include <bits/stdc++.h>
using namespace std;

#define int long long

void increasebit (int x,vector<int>&v){
    int bit=0;
    while(x>0 && bit<v.size()){
        if(x&1){
            v[bit]++;
        }
        bit++;
        x>>=1;
    }
}

void decIndexForSetBits(int x,vector<int>&v){
    int bit=0;
    while(x>0 && bit<v.size()){
        if(x&1){
            v[bit]--;
        }
        bit++;
        x>>=1;
    }
}


bool check(int k,vector<int>&arr){
    int n = arr.size();
    vector<int>bits(32,0);
    for(int i=0 ; i<k ; i++){
        increasebit(arr[i],bits);
    }
    vector<int>freq=bits;
    int start=1,end=start+k-1;
    while(end<n){
        decIndexForSetBits(arr[start-1],freq);
        increasebit(arr[end],freq);
        for(int i=0 ; i<32 ; i++){
            if(bits[i]>0 && freq[i]<=0) return false;
            if(bits[i]<=0 && freq[i]>0) return false;
        }
        start++;
        end++;
    }

    return true;
    
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int low=1,high=n;
        int ans=n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,arr)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans<<endl;
        // cout<<endl;
    }
    return 0;
}