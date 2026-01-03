#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int i=n-1;
        vector<int>divisior;
        while(i>0){
            if(n%i==0){
                divisior.push_back(i);
            }
            i--;
        }
        int ans=0;
        for(auto k : divisior){
            long long mx = LLONG_MIN;
            long long mn = LLONG_MAX;

            for(int i=0 ; i<n ; ){
                int ct=0;
                int sum=0;
                
                while(ct<k){
                    sum+=arr[i];
                    ct++;
                    i++;
                }
                mx = max(mx,sum);
                mn = min(mn,sum);
            }
            ans = max(ans,mx-mn);

        }
        cout<<ans<<endl;
    }
    return 0;
}