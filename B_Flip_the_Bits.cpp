#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a;
        cin>>a;
        string b;
        cin>>b;
        int x = n-1;
        while(x >= 0 && a[x] == b[x]) {
            x--;
        }
        bool flag = true;
        for(int i = x ; i>=0 ;){
            int ct0=0;
            int ct1=0;
            while(i>=0 &&  a[i]!=b[i]){
                if(a[i]=='0') ct0++;
                else ct1++;
                i--;
            }
           
            if(ct0!=ct1){
                flag = false;
                break;
            }
            ct0=0;
            ct1=0;
            while(i>=0 && a[i]==b[i]){
                if(a[i]=='0') ct0++;
                else ct1++;
                i--;
            }
            if(ct0!=ct1){
                 flag = false;
                break;
            }
            
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}