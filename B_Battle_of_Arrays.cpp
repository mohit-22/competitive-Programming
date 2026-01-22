#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        for(int i=0  ;i<n ; i++){
            int x;
            cin>>x;
            pq1.push(x);
        }
        for(int i=0 ; i<m ; i++){
            int x;cin>>x;
            pq2.push(x);
        }
        string ans="";
        while(pq1.size()!=0 || pq2.size()!=0){
            int x = pq1.top();
            int y = pq2.top();
            pq2.pop();
            if(y<=x) {}
            else{
                y-=x;
                pq2.push(y);
            }
            if(pq2.size()==0){
                ans = "Alice";
                break;
            }
            
            x = pq1.top();
            y = pq2.top();
            pq1.pop();
            if(y>=x) {}
            else{
                x-=y;
                pq1.push(x);
            }
            if(pq1.size()==0){
                ans = "Bob";
                break;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}