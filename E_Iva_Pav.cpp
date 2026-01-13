#include <bits/stdc++.h>
using namespace std;

#define int long long

void funcn(int idx,int x , vector<vector<int>>&v){
    bitset<32> b(x);  

    vector<int> v1;
    for(int i = 0; i < 32; i++){
        v1.push_back(b[i]);   
    }
    // reverse(v1.begin(),v1.end());
    for(int j=0  ; j<32 ; j++){
        v[idx][j] = (v[idx-1][j]+v1[j]);
    }

}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        vector<vector<int>>v(n+1,vector<int>(32,0));
        for(int i=1 ;i<n+1 ; i++){
            funcn(i,arr[i-1],v);
        }


        int q;
        cin>>q;
        while(q--){
            int l,k;
            cin>>l>>k;
            int ans=-1;
            int low = l;
            int high = n;
            while(low<=high){
                int mid = low+(high-low)/2;
                vector<int>v1;
                vector<int>v2 = v[mid];
                vector<int>v3 = v[l-1];
                int num=0;
                for(int i=0 ; i<32 ; i++){
                    if(v2[i]-v3[i]>=mid-l+1){
                        num += (1<<i);
                    }
                }
                if(num>=k){
                    low = mid+1;
                    ans = max(mid,ans);
                }else{
                    high = mid-1;
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;

    }
    return 0;
}