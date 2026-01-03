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
        set<int>s;
        for(auto it:arr){
            s.insert(it);
        }
        int i=0;
        int ans=-1;
        for(auto it:s){
            if(it!=i){
            ans=i;
                break;
            }
            i++;
        }
        if(ans==-1) cout<<s.size()<<endl;
        else cout<<ans<<endl;

    }
    return 0;
}