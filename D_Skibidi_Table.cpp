#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<ull> pow4(n+1);
        pow4[0]=1;
        for(int i=1;i<=n;i++) pow4[i]=pow4[i-1]*4ULL;
        int mapDigit[2][2];
        mapDigit[0][0]=0;
        mapDigit[1][1]=1;
        mapDigit[1][0]=2;
        mapDigit[0][1]=3;
        int dx[4]={0,1,1,0};
        int dy[4]={0,1,0,1};
        while(q--){
            string op;
            cin>>op;
            if(op=="->"){
                ull x,y;
                cin>>x>>y;
                x--,y--;
                ull res=0;
                for(int b=n-1;b>=0;--b){
                    int hx = (int)((x>>b)&1ULL);
                    int hy = (int)((y>>b)&1ULL);
                    int d = mapDigit[hx][hy];
                    res += (ull)d * pow4[b];
                }
                cout<< (res + 1ULL) << '\n';
            } else {
                ull d;
                cin>>d;
                ull rem = d-1;
                ull x=0,y=0;
                for(int b=n-1;b>=0;--b){
                    ull digit = rem / pow4[b];
                    rem %= pow4[b];
                    x = (x<<1) | (ull)dx[digit];
                    y = (y<<1) | (ull)dy[digit];
                }
                cout<< (x+1) << ' ' << (y+1) << '\n';
            }
        }
    }
    return 0;
}
