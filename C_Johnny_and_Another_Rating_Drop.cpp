#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        bitset<64>b(n);
        string s = b.to_string();
        s = s.substr(s.find('1'));

        int x = 1;
        int z = s.length()-1;
        int ans = 0;
        while(x<=s.length()){
            int y = 1LL <<x;
            ans+=(x*(n/y));
            if(n%y!=0 && s[z]=='1') ans+=x;
            z--;
            x++; 
        }
        cout<<ans<<endl;
        
    }
    return 0;
}