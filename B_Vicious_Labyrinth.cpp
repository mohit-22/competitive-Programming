#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        vector<int>v;
        int ct=1;
        int d = (k%2==0 ? k-1 : k);
        d = min(d, n - 1LL);

        for(int i=1 ; i<=n ;){
                while(ct<=n-d){
                    v.push_back(i+d);
                    ct++;
                    i++;
                }
                if(ct>n-d) break;
        }
        
        int ct1=1;
        
            for(int i=ct ; i<=n ; ){
                while(ct1<=d){
                    if(ct1%2!=0){
                        v.push_back(n-1);
                    }
                    else v.push_back(n);
                    ct1++;
                    i++;
                }
                if(i>n) break;
                
            }
        


            for(int i=0 ; i<v.size() ; i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
    
        
    }
    return 0;
}