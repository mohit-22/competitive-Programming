#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        int i=0;
        int j=n-1;
        int x = -1;
        int y=-1;
        while(i<j){
            if(s[i]!=s[j]){
                x= i;
                y=j;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        if(x==-1 && y==-1){
            cout<<0<<endl;
            continue;
        }
        
        bool flag = true;
        int ct=1;
        int m = y-1;
        while(i<m){
            if(s[i]!=s[m]){
                if(s[i]==s[y]){
                    ct++;
                    i++;
                }
                else if(s[m]==s[y]){
                    ct++;
                    m--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else {
                i++;
                m--;
            }
        }
        bool flag2=true;
        int ct1=1;
        m = x+1;
        while(m<j){
            if(s[m]!=s[j]){
                if(s[m]==s[x]){
                    ct1++;
                    m++;
                }
                else if(s[j]==s[x]){
                    ct1++;
                    j--;
                }
                else{
                    flag2 = false;
                    break;
                }
            }
            else {
                m++;
                j--;
            }
        }
        if(flag==false && flag2==false){
            cout<<-1<<endl;
            continue;
        }
        else if(flag==false){
            cout<<ct1<<endl;
        }
        else if(flag2==false){
            cout<<ct<<endl;
        }
        else{
            cout<<min(ct,ct1)<<endl;
        }

        
    }
    return 0;
}