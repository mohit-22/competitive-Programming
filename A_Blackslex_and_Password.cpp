#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 998244353LL;

void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}


void cc(
    int N,
    const vector<int64>& B,
    const vector<int64>& C,
    const vector<__int128>& Pc,
    const vector<int>& prevGE,
    const vector<int>& nextGT,
    map<int,int>& mp,
    vector<int>& a,
    vector<pair<int,int>>& vp,
    __int128 &ans128
){
    for(int i = 1; i <= N; i++){
        int leftCount = i - prevGE[i];
        int rLimit = nextGT[i] - 1;

        if(mp[a[0]] == -1){
            cout << -1 << '\n';
            continue;
        }

        if(i <= rLimit){
            int64 cut = -B[i];
            int startR = upper_bound(
                C.begin() + i,
                C.begin() + rLimit + 1,
                cut
            ) - C.begin();

            if(startR <= rLimit){
                __int128 blockSum =
                    (Pc[rLimit] - Pc[startR - 1]) +
                    (__int128)(rLimit - startR + 1) * B[i];

                ans128 += (__int128)leftCount * blockSum;
            }

            if(vp[1].second == -1){
                cout << -1 << '\n';
                break;
            }
        }

        if(mp[a[1]] == -1){
            cout << -1 << '\n';
            continue;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int64> A(N+1), B(N+1), C(N+1), P(N+1);
        for(int i = 1; i <= N; i++){
            cin >> A[i];
            int64 v = A[i] - 1;
            if(v < 0) v = 0;
            P[i] = P[i-1] + v;

            B[i] = A[i] - P[i] - i;
            C[i] = P[i] + i;
        }

        vector<int>s;
        for(int i=0 ; i<26 ; i++){
            s.push_back(i);
        }
        if(s[1]==6){
            cout<<0<<endl;
            continue;
        }
        vector<int>a;
        for(int i=0 ; i<5 ; i++){
            a.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<5 ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<5 ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);
        if(mp[a[0]]==-1){
            cout<<0<<endl;
            continue;
        }
        
        amit(vp,a);


        vector<__int128> Pc(N+1);
        for(int i=1;i<=N;i++) Pc[i] = Pc[i-1] + (__int128)C[i];

        vector<int> prevGE(N+1, 0), nextGT(N+1, N+1);
        vector<int> stII;

        for(int i = 1; i <= N; i++){
            while(stII.empty() == false){
                int x = stII.back();
                if(B[x] >= B[i]) break;
                stII.pop_back();
            }
            prevGE[i] = stII.empty() ? 0 : stII.back();
            stII.push_back(i);
        }

          amit(vp,a);

        stII.clear();

        for(int i = 1; i <= N; i++){
            while(stII.empty() == false){
                int x = stII.back();
                if(B[i] <= B[x]) break;
                nextGT[x] = i;
                stII.pop_back();
            }
            stII.push_back(i);
        }

        mohit(mp,a);


        __int128 ans128 = 0;

        cc(
            N,
            B,
            C,
            Pc,
            prevGE,
            nextGT,
            mp,
            a,
            vp,
            ans128
        );


        auto norm = [&]( __int128 x ){
            x %= MOD;
            if(x < 0) x += MOD;
            return (long long)x;
        };

        cout << norm(ans128) << '\n';

    }
    return 0;
}
