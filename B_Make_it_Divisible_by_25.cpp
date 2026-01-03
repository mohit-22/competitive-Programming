#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;

        int ans=INT_MAX;


        for(int i=s.size()-1 ; i>=1 ; i--){
            if((s[i]=='0' && s[i-1]=='0') || (s[i]=='5' && s[i-1]=='2') || (s[i]=='0' && s[i-1]=='5') || (s[i]=='5' && s[i-1]=='7')){
                ans = s.size()-i-1;
                break;
            }
        }

            int idx0=-1;
            int idx5=-1;

            int idx01=-1;
            int idx51=-1;
            for(int i=s.size()-1 ; i>=0 ; i--){
                if(s[i]=='0'){
                    idx0 = max(i,idx0);
                }
                else if(s[i]=='5'){
                    idx5 = max(i,idx5);
                }
            }

            if(idx0!=-1){
                for(int i=idx0-1 ; i>=0 ; i--){
                    if(s[i]=='0'|| s[i]=='5'){
                        idx01 = i;
                        break;
                    }
                }
                ans = min(ans,(int)(s.size()-1-idx0+idx0-idx01-1));  
            }
            if(idx5!=-1){
                for(int i=idx5-1 ; i>=0 ; i--){
                    if(s[i]=='2' || s[i]=='7'){
                        idx51 = i;
                        break;
                    }
                }
                ans = min(ans,(int)(s.size()-1-idx5+idx5-idx51-1)); 
            }
            
            cout<<ans<<endl;

        
        
    }
    return 0;
}