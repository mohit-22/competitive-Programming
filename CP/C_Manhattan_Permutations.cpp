#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        if(k%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        if(k==0){
            cout<<"Yes"<<endl;
            for(int i=0  ;i<n ; i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
        }
        int x = k;
        vector<pair<int,int>>v;
        vector<bool>v1(n,true);
        int i=0;
        bool flag = true;
        while(x>0 && i<=(n-1)/2){
            if(x-2*(n-(2*i)-1)>=0){
                if(v1[i] && v1[n-i-1]){
                    v.push_back({i,n-i});
                    v.push_back({n-i-1,i+1});
                    v1[i]=false,v1[n-1]=false;
                    x-=2*(n-2*i-1);
                    i++;
                }
                else flag = false;
                
            }
            else{
                int y = x/2;
                int p = i;
                int q = i+1+y;
                if(v1[p] && v1[q-1]){
                    v.push_back({p,q});
                    v.push_back({q-1,p+1});
                    v1[p]=false,v1[q]=false;
                    x=0;
                }
                else flag = false;   
            }
        }

        if(!flag || x>0){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        sort(v.begin(),v.end());
        vector<int>v2(n,0);
        for(int i=0 ; i<n ; i++){
            v2[i] = i+1;
        }
        for(auto it:v){
            v2[it.first] = it.second;
        }
        for(auto it:v2){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}