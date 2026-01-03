#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;

        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        bool flag = true;
        int x = arr[k-1];
        sort(arr.begin(),arr.end());
        int level = 1;
        int curr_time = 0;
        while(flag){
            auto it = upper_bound(arr.begin(),arr.end(),x);
            if(it - arr.begin()>=n){
                break;
            }
            curr_time+=*it-x;
            if(*it-x>x-curr_time){
                flag=false;
                break;
            }
            
            x = *it;
            
            
        }

        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }
    return 0;
}