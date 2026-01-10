#include <bits/stdc++.h>
using namespace std;

#define int long long



int evaluate(string &a, string &b) {
    vector<int> nums;
    vector<char> ops;

    string cur = "";
    cur += a[0];

    for (long long i = 0; i < b.size();  i++) {
        if (b[i] == '/') {
            // concatenate
            cur += a[i + 1];
        } else {
            // operator found
            nums.push_back(stoll(cur));
            ops.push_back(b[i]);
            cur = "";
            cur += a[i + 1];
        }
    }
    nums.push_back(stoll(cur));

    // Now evaluate: first handle '*'
    vector<int> newNums;
    vector<char> newOps;

    newNums.push_back(nums[0]);

    for (long long i = 0; i < ops.size(); i++) {
        if (ops[i] == '*') {
            newNums.back() *= nums[i + 1];
        } else {
            newNums.push_back(nums[i + 1]);
            newOps.push_back(ops[i]);
        }
    }

    // Now only '+' left
    int result = newNums[0];
    for (long long i = 0; i < newOps.size(); i++) {
        result += newNums[i + 1];
    }

    return result;
}


int funcn(int i,int j,string &s,string &str, map<tuple<int,int,string>,int>&dp){

    if(i==s.length()-1){
        return evaluate(s,str);
    }
    auto key = make_tuple(i,j,str);
    if(dp.count(key)) return dp[key];
    str.push_back('+');
    int plus = INT_MAX;
    if(s.length()-i>2 || j==1)  plus = funcn(i+1,j,s,str,dp);
    str.pop_back();

    str.push_back('*');
    int multi = INT_MAX;
    if(s.length()-i>2 || j==1)  multi = funcn(i+1,j,s,str,dp);
    str.pop_back();

    int nontake = INT_MAX;
    str.push_back('/');
    if(j==0) nontake = funcn(i+1,1-j,s,str,dp);
    str.pop_back();

    return dp[key] =  min({plus,multi,nontake});

    
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s; 
        string str="";
        map<tuple<int,int,string>,int>dp;
        cout << funcn(0,0,s,str,dp) << "\n";
    }
    return 0;
}