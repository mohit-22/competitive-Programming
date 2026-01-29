#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,k1,k2;
        cin >> n>>k1>>k2;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        vector<pair<int,int>>diff;
        for(int i=0 ; i<n ; i++){
            diff.push_back({abs(arr[i]-brr[i]),i});
        }
        sort(diff.begin(),diff.end(),greater<pair<int,int>>());
        for(int i=0 ; i<diff.size() ; i++){
            int idx = diff[i].second;
            int x = ((brr[idx]+arr[idx])/2)+1;
            int a = min(abs(x-arr[idx]),k1);
           
            if(k1>0){
                if(x>arr[idx]) arr[idx]+=a;
                else arr[idx]-=a;
            }
            if(a==0){
                if(brr[idx]>arr[idx]){
                    arr[idx]+=k1;
                    k1=0;
                }
                else if(brr[idx]<arr[idx]){
                    arr[idx]-=k1;
                    k1=0;
                }
                
            }
            int b = min(abs(arr[idx]-brr[idx]),k2);
            if(k2>0){
                if(arr[idx]>brr[idx]) brr[idx]+=b;
                else brr[idx]-=b;
            }
            if(b==0){
                if(arr[idx]>brr[idx]){
                    brr[idx]+=k2;
                    k2=0;
                }
                else if(arr[idx]<brr[idx]){
                    brr[idx]-=k2;
                    k2=0;
                }
                
            }
            k1-=a;
            k2-=b;
            if(k1==0 && k2==0) break;
        }
        if(k1>0){
            arr[diff[diff.size()-1].second]+=k1;
        }
        if(k2>0){
            brr[diff[diff.size()-1].second]+=k2;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            int a = abs(arr[i]-brr[i]);
            ans += a*a;
        }
        cout<<ans<<endl;
        
        
    // }
    return 0;
}