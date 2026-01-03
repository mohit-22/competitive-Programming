#include <bits/stdc++.h>
using namespace std;
#define long long int 

int32_t main(){

    // int t;
    // cin>>t;
    // while(t--){
        string s;
        cin>>s;
        int n = s.length();
        for(int i=0 ; i<n-1 ; i++){
            if(s[i]==s[i+1]){
                if(s[i]!='z') s[i+1]=s[i]+1;
                else s[i+1] = 'a';
                if(i+1!=n-1){
                    if(s[i+1]==s[i+2]){
                        if(s[i+1]=='z') s[i+1]='a';    
                        else s[i+1]=s[i+1]+1;
                    }
                }
            }
        }
        cout<<s<<endl;
    // }    
    return 0;
}
