    #include <bits/stdc++.h>
    using namespace std;

    #define int long long

    int32_t main(){
        int t;
        cin >> t;
        while(t--){
            int n,x;
            cin >> n>>x;
            string s;
            cin>>s;
            
            int ct=0;
            vector<int>v;
            for(int i=0 ; i<n ; i++){
                if(s[i]=='#'){
                    v.push_back(i);
                    ct++;
                }
            }
            
            if(x==1 || ct==0 || x==n){
                cout<<1<<endl;
                continue;
            }

            int p = INT_MAX;
            int x = -1;
            for(int i=0 ; i<v.size() ; i++){
               if(v[i]<=x-1){
                p = min(p,abs((x-1)-v[i]-1));
                x = p;
               }
               else{
                    p = min(p,abs(v[i]-(x-1)-1));
               }
            }
            if(x!=p){
                
            }
            cout<<p<<endl;
            int ans = min(x,n-x+1)-p;

            cout<<ans<<endl; 
        }
        return 0;
    }