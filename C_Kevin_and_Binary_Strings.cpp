#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int idx=-1;
        int n = s.length();
        for(int i=0 ; i<s.length()  ;i++){
            if(s[i]=='0'){
                idx = i;
                break;
            }
            
        }
        int y = n-idx;
        if(idx==-1){
            cout<<n<<" "<<n<<" "<<1<<" "<<n<<endl;
            continue;
        }
        // cout<<1<<" "<<y<<" "<<1<<" "<<n<<endl;
        int x = -1;
        int z = -1;
        for(int i=idx ; i<n ; i++){
            string sub = s.substr(idx,i-idx+1);
            string subrev = sub;
            for (char &c : subrev) {
                c = (c == '0' ? '1' : '0');  
            }
            size_t pos = s.find(subrev);
            if (pos != string::npos) {
                 if(n-pos>=y){
                    x = pos;
                    z = pos+y-1;
                 }
            } 
        }
        cout<<x+1<<" "<<z+1<<" "<<1<<" "<<n<<endl;
       

    }
    return 0;
}