#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int arr[n];
        int brr[m];
        set<int>s1;
        set<int>s2;
        int ct=0;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            s1.insert(arr[i]);  
        }
        for(int i=0 ; i<m ; i++){
            cin>>brr[i];
            s2.insert(brr[i]);
        }
        for(auto it :s1){
            if(s2.find(it)!=s2.end()) ct++;
        }
        int x = min(n,m);
        if(n<=m) cout<<2*x-2*ct+1<<endl;
        else cout<<2*x-2*ct+2<<endl;
        
    }
    return 0;
}