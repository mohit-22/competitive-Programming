#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        // int n;
        // cin >> n;
        string s;
        cin>>s;
        map<char,int>mp;
        int sum=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='2' || s[i]=='3') mp[s[i]]++;
            sum+=(s[i]-'0');
        }
        int next = ((sum + 8) / 9) * 9;
        int available=0;
        for(auto it: mp){
            if(it.first=='2') available+=(2*it.second);
            else available+=(6*it.second);
        }
        bool flag = false;
        while(next-sum<=available){
            int x = sum;
            if(next-sum>=6){
                int y = (next-sum)/6;
                if(mp['3']>=y) sum+=y*6;
                else sum+=mp['3']*6;
            }
            if((next-sum)%2==0){
                if((next-sum)<=mp['2']*2){
                    flag=true;
                    break;  
                }
                else{
                    next+=9;
                    sum = x;
                }
            }
            else{
                next+=9;
                sum = x;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}