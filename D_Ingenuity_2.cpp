#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(string &ans){
    for(int i=0  ;i<ans.length()-1 ; i++){
        if(ans[i]!=ans[i+1]) return false;
    }
    return true;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n  ;
        string s;
        cin>>s;
        string ans="";
        if(n==2){
            if(s[0]==s[1]){
                ans+='R';
                ans+='H';
                cout<<ans<<endl;
                continue;
            }else{
                cout<<"NO"<<endl;
                continue;
            }
        }

        int ctn=0,cts=0,ctw=0,cte=0;
        int ctns=0, ctwe=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='N'){
                ctn++;
                ans+='R';
                ctns++;
            }
            else if(s[i]=='S') {cts++;ans+='R';ctns++;}
            else if(s[i]=='W') {ctw++;ans+='H';ctwe++;}
            else {cte++;ans+='H';ctwe++;}
        }
        // cout<<ctn<<" "<<cts<<" "<<ctw<<" "<<cte<<endl;
        if(ctn>=cts){
            ctn-=(cts);
            cts=0;
        }else{
            cts-=(ctn);
            ctn=0;
        }

        if(cte>=ctw){
            cte-=(ctw);
            ctw=0;
        }else{
            ctw-=(cte);
            cte=0;
        }
        // cout<<ctn<<" "<<cts<<" "<<ctw<<" "<<cte<<endl;
        if(ctn%2!=0 || cts%2!=0 || ctw%2!=0 || cte%2!=0){
            cout<<"NO"<<endl;
            continue;
        }

        // cout<<ans<<endl;
        int x = (max(ctn,cts))/2;
        int y = (max(ctw,cte))/2;
        int i=0;
        while((x>0 || y>0) && i<n){
            if((s[i]=='N' ) && x>0 && ctn!=0){
                ans[i] = 'H';
                x--;
            }
            else if((s[i]=='S' ) && x>0 && cts!=0){
                ans[i] = 'H';
                x--;
            }
            else if ((s[i]=='W' ) && y>0 && ctw!=0){
                ans[i]='R';
                y--;
            }  
            else if ((s[i]=='E') && y>0 && cte!=0){
                ans[i]='R';
                y--;
            }
            i++; 
        }

        // cout<<ans<<endl;
        
        
        if(check(ans)){
             for(int i=0 ; i<n ; i++){
                if(s[i]=='N'){
                    ans[i]='H';
                    break;
                }
            }
            for(int i=0 ; i<n ; i++){
                if(s[i]=='S'){
                    ans[i]='H';
                    break;
                }
            }
        }
       
        

        if(check(ans)){
            for(int i=0 ; i<n ; i++){
                if(s[i]=='W'){
                    ans[i]='R';
                    break;
                }
            }
            for(int i=0 ; i<n ; i++){
                if(s[i]=='E'){
                    ans[i]='R';
                    break;
                }
            }
        }
        
        


        cout<<ans<<endl;




    }
    return 0;
}