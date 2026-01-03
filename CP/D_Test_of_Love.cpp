#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n>>m>>k;
        string s;
        cin>>s;
        vector<int>v;
        vector<int>vp(3,0);
        map<int,vector<int>>mp;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='L') v.push_back(i);
            if(s[i]=='L'){
                vp[0]++;
                mp[i] = vp;
            }
            else if(s[i]=='W'){
                vp[1]++;
                mp[i] = vp;
            }
            else{
                vp[2]++;
                mp[i]=vp;
            }
        }
        if(m>=n+1){
            cout<<"YES"<<endl;
            continue;
        }
        bool flag = true;
        if(v.size()==0){
            int j=-1;
            for(int i=0 ; i<min(n,m) ; i++){
                if(s[i]=='W'){
                    j=i;
                }
            }
            if(j==-1){
                cout<<"NO"<<endl;
                continue;
            }

            int ct=1;
            for(int i=j+1 ; i<n ; i++){
                if(s[i]=='C'){
                    flag=false;
                    break;
                }
                else if (s[i] == 'W') ct++;
            }
            if(ct>k){
                flag=false;

            }

            // if(vp[2]>=1 || vp[1]>k){
            //     cout<<"NO"<<endl;
            //     continue;
            // }
            if(!flag) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }

        

        // vector<int>A ;
        // if(v[0]-1>=0 ){
        //     A= mp[v[0]-1];
        //     if(A[2]>=1 || A[1]>k){
        //         cout<<"NO"<<endl;
        //         continue;
        //     }
        // }
        vector<int> A(3,0);  // NEW — important!

        if(v[0]-1 >= 0 && v[0]+1>m){
            A = mp[v[0]-1];
        }
        // if(A[2] >= 1 || A[1] > k){   // NOW SAFE
        //     cout<<"NO"<<endl;
        //     continue;
        // }

        int j=-1;
            for(int i=0 ; i<min(n,m) ; i++){
                if(s[i]=='W'){
                    j=i;
                }
            }
            if(j==-1){
                cout<<"NO"<<endl;
                continue;
            }

            int ct1=1;
            for(int i=j+1 ; i<v[0] ; i++){
                if(s[i]=='C'){
                    flag=false;
                    break;
                }
                else if (s[i] == 'W') ct1++;
            }
            if(ct1>k){
                flag=false;

            }

            // if(vp[2]>=1 || vp[1]>k){
            //     cout<<"NO"<<endl;
            //     continue;
            // }
            if(!flag) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;

        int ct =0;
        if(v[0]-1>=0) ct= A[1];
        
        // vector<pair<int,int>>vpp;
        for(int i=0 ; i<v.size()-1 ; i++){
            if(v[i+1]-v[i]>m){
                vector<int>B = mp[v[i+1]-1];
                vector<int>C = mp[v[i]]; ;
                // if(v[i]-1>=0 ){
                //     C = mp[v[i]-1];
                // }
                int x = B[1]-C[1];
                int y = B[2]-C[2];
                ct+=x;
                if(y>=1 || ct>k){
                    flag = false;
                    break;
                }
                
            }
        }
        // if(n-v[v.size()-1]-1>m){
        //     for(int i=v[v.size()-1]+1 ;i<n ;i++){
        //     if(s[i]=='C'){
        //         flag=false;
        //         break;
        //     }
        //     else if(s[i]=='W'){
        //         ct++;
        //     }
        // }
        // }

        if(!v.empty()){
            if(n - v.back()  > m){
                for(int i = v.back() + 1; i < n; ++i){
                    if(s[i] == 'C'){
                        flag = false;
                        break;
                    } else if(s[i] == 'W'){
                        ct++;
                    }
                }
            }
        }
        
        if(ct>k) flag=false;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        

        
        
        
    }
    return 0;
}