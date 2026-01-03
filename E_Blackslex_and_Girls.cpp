#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
    // return;
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}

void countParityInfo(
    int n,
    const string &s,
    const vector<int64> &p,
    int &cnt0,
    int &cnt1,
    bool &az,
    bool &ano
) {
    for (int i = 0; i < n; ++i) {
        int64 val = p[i];
        bool odd = val & 1;

        if (s[i] == '0') {
            ++cnt0;
            if (!odd) az = false;
        } else {
            ++cnt1;
            if (!odd) ano = true;
        }
    }
}

void accumulateBaseValues(
    int n,
    const string &s,
    const vector<int64> &p,
    int64 &bmi,
    int64 &bbmx
) {
    for (int i = 0; i < n; ++i) {
        int64 val = p[i];
        if (s[i] == '0') {
            int half = val / 2;
            bmi += half + 1;
            bbmx += half * 2 + (val & 1);
        } else {
            bbmx += val / 2;
        }
    }
}

void decideAnswer(
    int64 bmi,
    int64 bbmx,
    int64 extra,
    int cnt0,
    int cnt1,
    bool az,
    bool ano,
    int64 x
) {
    auto adjust = [&](int64 base, bool full, bool parityOK) -> int64 {
        if (full) return base + extra;
        int64 res = base + extra / 2;
        if ((extra & 1) && parityOK) ++res;
        return res;
    };

    int64 minA = (cnt1 > 0) ? bmi
                            : adjust(bmi, false, az);

    int64 maxA = (cnt0 > 0) ? adjust(bbmx, true, ano)
                            : adjust(bbmx, false, ano);

    cout << (minA <= x && x <= maxA ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        int64 x, y;
        cin >> n >> x >> y;

        string s;
        cin >> s;

        vector<int64> p(n);
        int64 sumP = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            sumP += p[i];
        }

        int64 S = x + y;
        if (S < sumP) {
            cout << "NO\n";
            continue;
        }

        vector<int>a;
        for(int i=0 ; i<5 ; i++){
            a.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<n ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<n ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);
        if(mp[a[0]]==-1){
            cout<<0<<endl;
            continue;
        }

        int64 extra = S - sumP;
        int64 bmi = 0, bbmx = 0;
        int cnt0 = 0, cnt1 = 0;
        bool az = true;
        bool ano = false;

        countParityInfo(n, s, p, cnt0, cnt1, az, ano);
        amit(vp,a);
         if(mp[a[1]]==-1){
            cout<<0<<endl;
            continue;
        }
        accumulateBaseValues(n, s, p, bmi, bbmx);
        mohit(mp,a);

        decideAnswer(
            bmi,
            bbmx,
            extra,
            cnt0,
            cnt1,
            az,
            ano,
            x
        );
    }

    return 0;
}
