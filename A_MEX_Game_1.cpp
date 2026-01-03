#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int>s;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        auto p = s.begin();
        int q = *p;
        int w = 0;
        while(!s.empty()){
            int x = w;
            if(s.find(x)==s.end()){
                cout<<x<<endl;
                break;
            }
            else{
                auto y = s.lower_bound(x+1);
                auto z = s.upper_bound(x+1);
                z--;
                if(y!=s.end()){
                    s.erase(y);
                    if(s.find(x+1)==s.end()){
                        cout<<x+1<<endl;
                        break;
                    }
                }
                else{
                    cout<<x+1<<endl;
                    break;
                }
                auto it = s.find(w);   // find gives iterator to first occurrence
                if(it != s.end()){
                    s.erase(it);  // erases only that one occurrence
                }
                w++;

                
            }
            // s.erase(x);

        }
    }
    return 0;
}