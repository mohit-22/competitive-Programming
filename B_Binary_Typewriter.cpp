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
        int ct=0;
        for(int i=0  ;i<n-1 ; i++){
            char ch1 = s[i];
            char ch2 = s[i+1];
            if(ch1!=ch2){
                ct++;
            }
        }
        if(ct==0){
            if(s[0]=='0') cout<<s.size()<<endl;
            else cout<<s.size()+1<<endl;
        }
        else if(ct==1){
            cout<<s.size()+1<<endl;
            
        }
        else {
            int ct=1;
                for(int i=0  ;i<n-1 ; i++){
                    if(s[i]!=s[i+1]) ct++;
                }

            if(s[0]=='1') cout<<s.size()+ct-2<<endl;
            else cout<<s.size()+ct-3<<endl;
            
        }

    }
    return 0;
}