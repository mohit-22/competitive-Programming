#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> dp;
int getPrev(char prev){
    if(prev == ' ') return 0;
    if(prev == 'a') return 1;
    return 2;
}

int solve(int i,char prev,string &s){
    int p = getPrev(prev);

    if(i>=s.length() && prev=='a'){
        return 1;
    }
    else if(i>=s.length()) return 0;

    if(dp[i][p] != -1)
        return dp[i][p];

    int take = 0;
    if(prev=='a' && s[i]=='b'){
       take+= solve(i+1,'b',s);
    }
    if(prev=='b' && s[i]=='a'){
        take+= solve(i+1,'a',s);
    }
    if(prev==' ' && s[i]=='a'){
        take+=solve(i+1,'a',s);
    }
    int nontake = 0;
    nontake+=solve(i+1,prev,s);

    return dp[i][p] = take+nontake;
}

int32_t main(){
    string s1;
    cin>>s1;

    string s;
    for(int i=0 ; i<s1.length() ; ){
        if(s1[i]!='b' && s1[i]!='a') i++;
        else if(s1[i]=='b'){
            s.push_back('b');
            while(s1[i]=='b') i++;
        }
        else{
            s.push_back('a');
            i++;
        }
    }
    cout<<s<<endl;
    dp.assign(s.length()+1, vector<int>(3, -1));

    int i=-1;
    for(int j=0 ; j<s.length() ; j++){
        if(s[j]=='a'){
            i=j;
            break;
        }
    }
    if(i==-1){
        cout<<0<<endl;
        return 0;
    }

    

    // int x =  solve(i+1,'a',s);
    int y = solve(i,' ',s);
    // return x+y;
    cout<<y<<endl;


}