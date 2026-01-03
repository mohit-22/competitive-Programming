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
        int sum=0;
        map<int,int>mp;
        mp[0] = 1;
        bool flag = false;
        for(int i=0; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n ; i++){
            if(i%2!=0) arr[i] = (0-arr[i]);
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()){
                flag= true;
                break;
            }
            else mp[sum]++;

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}