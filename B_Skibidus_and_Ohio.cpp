#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        bool flag = false;
        for(int i = 0 ;i<n-1 ; i++){
            if(s[i]==s[i+1]){
                flag=true;
                break;
            }
        }
        if(flag==true) cout<<1<<endl;
        else cout<<n<<endl;
        
    }
    return 0;
}