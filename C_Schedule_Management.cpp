#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int arr[m];
        map<int,int>mp;
        for(int i=0 ;i<m ; i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto it :mp){
            pq.push(it.second);
        }
        int x = n-mp.size();
        while(x--){
            int y = pq.top();
            pq.pop();
            y--;
            pq.push(y);
            pq.push(2);
        }
        priority_queue<int, vector<int>, greater<int>> pq2;

        priority_queue<int> temp = pq; 

        while(!temp.empty()) {
            pq2.push(temp.top());
            temp.pop();
        }
        
        while(pq.top()-1>=pq2.top()+2){
            int x = pq.top();
            int y = pq2.top();
            x--;
            y+=2;
            pq.pop();
            pq2.pop();
            pq.push(x);
            pq2.push(y);
        }
        cout<<pq.top()<<endl;
        
        
        
    }
    return 0;
}