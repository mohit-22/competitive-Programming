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
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        int mn = arr[0];
        int mx= arr[n-1];
        int brr[n];
        int crr[n];
        for(int i=0 ; i<n ; i++){
            mn = min(mn,arr[i]);
            brr[i] = mn;
        }
        for(int i=n-1 ; i>=0 ; i--){
            mx = max(mx,arr[i]);
            crr[i] = mx;
        }
        string s;
        for(int i=0 ; i<n ; i++){
            if(arr[i]==brr[i] || arr[i]==crr[i]){
                s.push_back('1');
            }
            else s.push_back('0');
        }
        for(int i=0;i<s.size() ; i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}