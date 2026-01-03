#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = "";
        while (n > 0) {
            s = char('0' + (n % 2)) + s;
            n /= 2;
        }
        // cout<<s<<endl;
        int p=0;
        int j=s.length()-1;
        for(int i=0 ;i<s.length() ; i++){
            if(s[i]=='1'){
                p=i;
                break;
            }
        }
        for(int i=s.length()-1 ; i>=0 ; i--){
            if(s[i]=='1'){
                j=i;
                break;
            }
        }
        // cout<<p<<" "<<j<<endl;
        int x = j;
        int y = p;
        bool flag = true;
        while(p<=j){
            if(s[p]!=s[j]){
                flag=false;
                break;
            }
            p++;
            j--;
        }
        
        int u = x-y+1;
        if(u%2!=0){
            if(s[(x+y)/2]=='1'){
                flag=false;
                // break;
            }
        }
        

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}