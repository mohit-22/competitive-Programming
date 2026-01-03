#include <bits/stdc++.h>
using namespace std;

#define int long long



int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int mod = 998244353;
        string s;
        cin>>s;
        vector<int>v;
        int n = s.size();
        for(int i=0; i<n ; ){
            int ct=1;
            while(i+1<n &&  s[i]==s[i+1]){
                ct++;
                i++;
            }
            if(ct>=2) v.push_back(ct);
            i++;
        }
        int sum=0;
        int prod=1;
        for(int i=0 ; i<v.size() ;i++){
            sum+=v[i]-1;
            // // v[i] = ((v[i]+1)*v[i]);
            // prod*=v[i];
            int x = v[i];
            prod =( (prod%mod)*(v[i]%mod))%mod;
        }
        // int fact=0;
        // for(int i=0 ; i<v.size()  ;i++){
        //     fact+=(v[i]-1);
        // }
        int z= 1;
        for(int i=1 ; i<=sum ; i++){
            z =((z%mod)*(i%mod))%mod;
        }
        prod = prod%(998244353);
        prod = prod*z;
        prod = prod%(998244353);

        cout<<sum<<" "<<max(prod,1LL)<<endl; 

        // int sum=0;
        // int prod=1;
        // for(int i=0 ; i<v.size() ;i++){
        //     sum+=v[i]-1;
        //     int x = (v[i]*(v[i]-1))/2;
        //     prod *=x;
        // }
        // prod =( prod*v.size())%998244353;
        // cout<<sum<<" "<<prod<<endl;


        
    }
    return 0;
}