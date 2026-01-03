#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
        string s;
        cin>>s;
        vector<int>front(s.size());
        vector<int>back(s.size());
        for(int i=1 ; i<s.size() ; i++){
            if(s[i]=='v' && s[i-1]=='v'){
                front[i] = front[i-1]+1;
            }
            else{
                front[i] = front[i-1];
            }
        }
        for(int i=s.size()-2 ; i>=0 ; i--){
            if(s[i]=='v' && s[i+1]=='v'){
                back[i] = back[i+1]+1;
            }
            else back[i] = back[i+1];
        }
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='o'){
                ans+=(front[i]*back[i]);
            }
        }
        cout<<ans<<endl;
    

    return 0;
}