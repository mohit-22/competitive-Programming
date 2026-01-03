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
        vector<int>v;
        int sum=0;
        for(int i=0 ; i<n; i++){
            cin>>arr[i];
            if(arr[i]<0) v.push_back(i);
            sum+=arr[i];
        }
        vector<int>pref(n);
        pref[0] = arr[0];
        for(int i = 1;i<n ; i++){
            pref[i] = arr[i]+pref[i-1];
        }
        vector<int>pref2(n);
        pref2[n-1] = arr[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            pref2[i] = pref2[i+1]+arr[i];
        }
        // if(v.size()==0){
        //     if(arr[0]==0 || arr[n-1]==0){
        //         cout<<"NO"<<endl;
        //     }
        //     else cout<<"YES"<<endl;
        //     continue;
        // }
        

        // int mx = INT_MIN;
        // if(v[0]!=0) mx = pref[v[0]-1];
        // for(int i=1 ; i<v.size() ; i++){
        //     mx = max(mx,pref[v[i]-1]-pref[v[i-1]]);
        // }
        // if(v[v.size()-1]!=n-1){
        //     mx = max(pref[n-1]-pref[v[v.size()-1]],mx);
        // }
        // cout<<mx<<endl;
        // cout<<sum<<endl;
        // if(sum>mx) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            if(pref[i]<=0){
                flag = false;
                break;
            }
        }
        bool flag2 = true;
        for(int i=0 ; i<n ; i++){
            if(pref2[i]<=0){
                flag2 = false;
                break;
            }
        }
        if(flag==false || flag2==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}