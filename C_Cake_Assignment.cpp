



#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int k,x;
        cin >> k>>x;

        int a = 1<<(k+1);
        int y = a-x;

        int z = 1<<k;
        int p = z;
        int q = z;
        vector<int>v;
        int ct=0;
        
        vector<int>f1;
        for(int i=1 ; i<=sqrt(p) ; i++){
            if(p%i==0){
                f1.push_back(i);
                int b = p/i;
                if(b!=i) f1.push_back(p/i);
            }
        }

        vector<int>f2;
        for(int i=1 ; i<=sqrt(p) ; i++){
            if(p%i==0){
                f2.push_back(i);
                int b = p/i;
                if(b!=i) f2.push_back(p/i);
            }
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        if(p>x){
            int m = x;
            
                int sum=0;
                int s=-1;
                for(int i=f1.size()-1 ; i>=0 ; i--){
                    sum+=f1[i];
                    if(sum%m==0){
                        s=i;
                        break;
                    }
                }
                int g = f1.size()-s-1;
                // ct = f1.size()-s;
                for(int i=1 ; i<=g ; i++){
                    v.push_back(2);
                }
                int h = (sum/x);
                int y = log2(h);
                ct+=y;
                ct+=g;
                for(int i=0 ; i<y ; i++){
                    v.push_back(1);
                }
            // }
        }
        else if(p<x){
            int m = y;
            
                int sum=0;
                int s=-1;
                for(int i=f2.size()-1 ; i>=0 ; i--){
                    sum+=f2[i];
                    if(sum%m==0){
                        s=i;
                        break;
                    }
                }
                int g = f2.size()-s-1;
                // ct = f1.size()-s;
                for(int i=1 ; i<=g ; i++){
                    v.push_back(1);
                }
                int h = (sum/y);
                int y = log2(h);
                ct+=y;
                ct+=g;
                for(int i=0 ; i<y ; i++){
                    v.push_back(2);
                }
        }
        else{
            ct=0;
        }

        cout<<ct<<endl;
        for(int i=0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}









