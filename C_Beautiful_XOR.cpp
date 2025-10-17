#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;

        int msb_a = 63 - __builtin_clzll(a);
        int msb_b = 63 - __builtin_clzll(b);
        if (msb_b > msb_a) {
            cout << -1 << "\n";
            continue;
        }
        int n = a;
        string s="";
        while(n>0){
            s = char('0' + (n%2))+s;
            n=n/2;
        }
        int m = b;
        string s2="";
        while(m>0){
            s2= char('0' + (m%2))+s2;
            m=m/2;
        }
        int p = s.length();
        int q = s2.length();
        if(p>q){
            int x = p-q;
            while(x--){
                s2= char('0')+s2;
            }
        }
        else{
            int x = q-p;
            while(x--){
                s= char('0')+s;
            }
        }
         p = s.length();
         q = s2.length();
        int i=p-1;
        int j = q-1;
        int y = 0;
        int ct=0;
        vector<int>v;
        while(i>=0 ){
            if(s[i]!=s2[j]){
                v.push_back(pow(2,y));
                ct++;
            }
            i--;
            j--;
            y++;

        }
        cout<<ct<<endl;
        for(auto it:v){
            cout<<it<<" ";
        }
        if(ct!=0) cout<<endl;

        // cout<<s<<" "<<s2<<endl;

    }
    return 0;
}