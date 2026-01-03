#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int x=-1;
        int y = -1;
        int ct=0;
        for(int i=0; i<n ; i++){
            cin>>arr[i];
            if(arr[i]==0){
                ct++;
                y=i+1;
            }
            if(ct==1 && arr[i]==0) x=i+1;

        }
        int ct3=0;
        vector<int>v;
        int ct4=0;
        
        if(x==1 && y==n && ct==n){
            if(n%2==0){
                cout<<(n/2)+1<<endl;
                int x=0;
                cout<<1<<" "<<2<<endl;
                for(int i=2 ; i<n ; i+=2){
                    cout<<2+x<<" "<<2+x+1<<endl;
                    x++;
                }
                cout<<1<<" "<<n/2<<endl;
            }
            else{
                cout<<(n/2)+1<<endl;
                int x=0;
                int ct=1;
                cout<<1<<" "<<2<<endl;
                for(int i=2 ; i<n-3 ; i+=2){
                    cout<<2+x<<" "<<2+x+1<<endl;
                    x++;
                    ct++;
                }
                // cout<<n-2<<" "<<n<<endl;
                cout<<ct+1<<" "<<ct+3<<endl;
                cout<<1<<" "<<n/2<<endl;
            }
        }
        else if(x==1 && y==n && ct!=n){
            vector<int>vv;
            for(int i=0 ; i<n ; i++){
                if(arr[i]==0){
                    // cout<<i+1-ct4<<" "<<i+2-ct4<<endl;
                    vv.push_back(i+1-ct4);
                    vv.push_back(i+2-ct4);
                    ct3++;
                    ct4++;
                    i++;
                }
            }
            cout<<ct3+1<<endl;
            for(int i=0 ; i<vv.size() ; i+=2){
                cout<<vv[i]<<" "<<vv[i+1]<<endl;
            }
            cout<<1<<" "<<n-ct4<<endl;
            
        }
        else if(x==-1 && y==-1){
            cout<<1<<endl;
            cout<<1<<" "<<n<<endl;
        }  
        else if(x==y){
            if(x!=1){
                cout<<2<<endl;
                cout<<x-1<<" "<<x<<endl;
                cout<<1<<" "<<n-1<<endl;
            }
            else if(x==1){
                cout<<2<<endl;
                cout<<x<<" "<<x+1<<endl;
                cout<<1<<" "<<n-1<<endl;
            }
        }
        else{
            cout<<2<<endl;
            cout<<x<<" "<<y<<endl;
            cout<<1<<" "<<n-(y-x+1)+1<<endl;
        }
    }
    return 0;
}