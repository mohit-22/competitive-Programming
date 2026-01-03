#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n>>m>>k;
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
        for(int i=0 ; i<n ; i++){
            int x,y;
            cin>>x>>y;
            v1.push_back({x,y});
        }
        for(int i=0 ; i<m ; i++){
            int x,y;
            cin>>x>>y;
            v2.push_back({x,y});
        }
        bool flag = true;
        priority_queue<int>q;
        int j=0;
        int sum=1;
        int p=0;
        int ct=0;
        while(j<n && v1[j].first<k){
            for(int i=p;i<m ; ){
                while(i<m &&  v2[i].first<v1[j].first){
                    q.push(v2[i].second);
                    p=i+1;
                    i++;
                }
                break;
            }
            int x = v1[j].second-v1[j].first+2;
            // int sum2=1;
            while(sum<x && !q.empty()){
                // sum2+=q.top();
                sum+=q.top();
                q.pop();
                ct++;
            }
            if(x>sum){
                flag=false;
                break;
            }
            j++;
        }

        while(j<n){
            int x = v1[j].second-v1[j].first+2;
            if(x>sum){
                flag=false;
                break;
            }
            j++;
        }

        if(!flag) cout<<-1<<endl;
        else cout<<ct<<endl;

        
    }
    return 0;
}