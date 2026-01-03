#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char ch;
        cin >> n>>ch;
        string s;
        cin>>s;
        for(int i=0  ;i<n ; i++){
            s+=s[i];
        }
        int m = s.size();
        int mxct=INT_MIN;
        for(int i=0 ; i<m ; ){
            int idx=-1;
            if(s[i]==ch){
                idx=i;
                // i++;
                while(s[i]!='g' && i<m){
                    i++;
                }
                int ct = i-idx;
                mxct = max(ct,mxct);
                
            }
            i++;
        }

        cout<<mxct<<endl;

        
    }
    return 0;
}