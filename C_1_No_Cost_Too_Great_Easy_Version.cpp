#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=200005;
int s[N];

set<int>allDivisors(int n) {
    // vector<int> divs;

    // if (n > 1) {
    //     f.insert(n);
    //     mp[n]++;
    // }
    // for (int i = 2; i * i <= n; i++) {
    //     if (n % i == 0) {
    //         f.insert(i);
    //         mp[i]++;
    //         if (i != n / i){
    //             f.insert(n / i);
    //             mp[n / i]++; 
    //         }
    //     }
    // }
    set<int>f;
    while(n>1){
        f.insert(s[n]);
        n = n/s[n];
    }
    return f;

}

int32_t main(){

    for(int i=0 ; i<N ; i++){
        s[i]=i;
    }
    for(int i=2 ; i*i<N ; i++){
        if(s[i]==i){
            for(int j=i*i ; j<N ; j+=i){
                if(s[j]==j) s[j]=i;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        vector<int>b;

        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0 ; i<n  ;i++){
            int x;
            cin>>x;
            b.push_back(x);
        }
        set<int>f;
        map<int,int>mp;
        for(int i=0 ; i<n ; i++){
           set<int>f =  allDivisors(v[i]);
           for(auto it:f){
                mp[it]++;
           }
        }
        for(auto it:f){
            mp[it]++;
        }
        bool flag = false;
        for(auto it:mp){
            if(it.second>1){
                flag = true;
                break;                
            }
        }
        if(flag){
            cout<<0<<endl;
            continue;
        }

        // set<int>f1;
        f.clear();
        map<int,int>mp1;
        for(int i=0 ; i<n ; i++){
            set<int>f = allDivisors(v[i]+1);
             for(auto it:f){
                mp1[it]++;
            }
        }
       
        for(auto it:mp1){
            if(mp.find(it.first)!=mp.end()){
                flag=true;
                break;
            }
        }

        if(flag) cout<<1<<endl;
        else cout<<2<<endl;

        // cout<<1<<endl;




        
        
    }
    return 0;
}
