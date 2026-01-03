#include <bits/stdc++.h>
using namespace std;

#define int long long

int binary_search(vector<int>&parray , int val,int n){

    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(parray[mid]<=val){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n>>q;

        vector<int>steps(n),query(q);
        for(int i=0 ; i<n ; i++){
            cin>>steps[i];
        }
        for(int i=0 ; i<q ; i++){
            cin>>query[i];
        }

        vector<int>psum(n),parray(n);
        psum[0] = steps[0];
        parray[0] = steps[0];
        for(int i=1 ; i<n ; i++){
            psum[i] = psum[i-1]+steps[i];
            parray[i] = max(parray[i-1],steps[i]);
        }

        for(int i=0 ; i<q ;i++){
            int val = query[i];
            int x = binary_search(parray,val,n);

            if(x==-1) cout<<0<<" ";
            else cout<<psum[x]<<" ";
        }
        cout<<endl;

        
    }
    return 0;
}