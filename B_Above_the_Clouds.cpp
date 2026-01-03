#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;

        unordered_map<char,int>m;
        for(int i=0 ; i<n ; i++){
            m[s[i]]++;
        }
        bool flag=false;
        for(int i=1 ; i<n-1 ; i++){
            if (m[s[i]] >= 2) {
                flag = true;
                break;
            }
        }
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}