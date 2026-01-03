#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,d,p,k;
        cin >> n>>d>>p>>k;
        int arr[n];
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        if(k+1>n){
            cout<<"NO"<<endl;
            continue;
        }
        sort(arr,arr+n,greater<int>());
        vector<int>v;
        for(int i=0 ; i<=k ; i++){
            v.push_back(arr[i]);
        }
        sort(v.begin(),v.end());
        int x = d;
        bool flag = true;
        for(int i=0 ; i<v.size() ; i++){
            if(x<arr[i]){
                flag=false;
                break;
            }
            x+=p;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}