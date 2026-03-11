#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s,a;
        cin>>s>>a;
        map<char,int>mps;
        map<char,int>mpa;
        for(auto it:s){
            mps[it]++;
        }
        for(auto it:a){
            mpa[it]++;
        }
        bool flag = true;
        for(auto it:mps){
            if(it.second>mpa[it.first]){
                flag=false;
                break;
            }
        }
        if(!flag){
            cout<<"Impossible"<<endl;
            continue;
        }

        string ans;
        int i=0;
        for(auto it:mpa){
            if(i<s.length() &&  it.first<s[i]){
                int x = mpa[it.first]-mps[it.first];
                while(x>0){
                    ans.push_back(it.first);
                    mpa[it.first]--;
                    x--;
                }
            }
            else{
                while(i<s.length() && s[i]<=it.first){
                    ans.push_back(s[i]);
                    mpa[it.first]--;
                    mps[it.first]--;
                    i++;
                }
                int x = mpa[it.first]-mps[it.first];
                while(x>0){
                    ans.push_back(it.first);
                    mpa[it.first]--;
                    x--;
                }

            }
        }
        cout<<ans<<endl;



        
        
    }
    return 0;
}