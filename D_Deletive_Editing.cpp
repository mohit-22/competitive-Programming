#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s,t;
        cin>>s>>t;
        string a="";
        string b;
        b = s;

        int i = s.size()-1 , j=0;
        while(j<t.size() && i>=0){
            if(s[i]==t[j]){
                // a+=s[i];
                s.erase(i,1);
                i = s.size()-1;
                j++;
            }
            else {
                i--;
            }
        }
        
        int p=0,q=0;
        while(p<b.size() && q<s.size()){
            if(b[p]==s[q]){
                b.erase(p,1);
                p=0;
                q++;
            }
            else{
                p++;
            }
        }
        bool flag = true;
        for(int i=0 ; i<t.size() ; i++){
            if(b[i]!=t[i]){
                flag=false;
                break;
            }
        }
        if(flag==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
        
    }
    return 0;
}


