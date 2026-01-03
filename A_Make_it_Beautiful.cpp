#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i = 0 ; i<n ; i++){
            cin>>v[i];
        }
        reverse(v.begin(),v.end());
        int count = 1;
        for(int i = 0 ; i<n-1 ; i++){
            if(v[i]==v[i+1]) count++;
        }
        if(count==n) cout<<"NO"<<endl;
        else{
            if(v[0]==v[1]){
                swap(v[0],v[n-1]);
                cout<<"YES"<<endl;
                for(int i = 0  ;i<n ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"YES"<<endl;
                for(int i = 0  ;i<n ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
        }

    }
    return 0;
}