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

void applyDifferences(
    int n,
    int step,
    const vector<int>& L,
    const vector<int>& offset,
    const vector<long long>& diffA,
    const vector<long long>& diffB,
    vector<long long>& ans
) {
    for (int r = 0; r < step; ++r) {
        int Lr = L[r];
        if (Lr <= 0) continue;

        int baseIdx = offset[r];
        long long curA = 0, curB = 0;

        int j = 0;
        for (int pos = r; pos < n && j < Lr; pos += step) {
            curA += diffA[baseIdx + j];
            curB += diffB[baseIdx + j];
            ans[pos] += curA * (long long)j + curB;
            ++j;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int,int>> ops(q);
        for (int i = 0; i < q; ++i) {
            int l, r; cin >> l >> r;
            ops[i] = {l-1, r-1}; // convert to 0-based
        }

        vector<int64> ans(n, 0);

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

        // int maxT = 0;
        // while ((1 << maxT) <= n) ++maxT;
        // if (maxT > 0) --maxT;
        int maxT = 0;
        while ((1LL << (maxT + 1)) <= n) ++maxT;


        for (int t = 0; t <= maxT; ++t) {
            if (2 * t >= 62) break;
            if (t + 1 >= 62) break;
            int64 powt = 1LL << t;             
            // int step = (int)(1LL << (t + 1));  
            long long stepLL =(int)(1LL << (t + 1));
            if (stepLL > 2LL * n) break;
            int step = (int)stepLL;         
            int64 baseD = 1LL << (2 * t);      
            int64 inc = baseD << 1;

           
            vector<int> L(step, 0);
            

            int r = 0;
            while (r < step) {
                if (r < n) {
                    L[r] = ((n - 1 - r) / step) + 1;
                } else {
                    L[r] = 0;
                }
                ++r;
            }

            vector<int> offset(step + 1);
            int totalSlots = 0;

            r = 0;
            while (r < step) {
                offset[r] = totalSlots;
                totalSlots += L[r] + 1;
                ++r;
            }
            offset[step] = totalSlots;

            // if (totalSlots == 0) continue;
            const long long SAFE_SLOTS = 20000000LL;
            if (totalSlots <= 0) continue;
            if ((long long)totalSlots > SAFE_SLOTS) {
                continue;
            }



            vector<int64> diffA(totalSlots);
            vector<int64> diffB(totalSlots);
            for (int i = 0; i < totalSlots; ++i) {
                diffA[i] = 0;
                diffB[i] = 0;
            }

            // for (auto &op : ops) {
                
            //     int l0 = op.first;
            //     int r0 = op.second;
            //     int len = r0 - l0 + 1;
            //     if (len < powt) continue;

                
            //     long long baseSum = (long long)l0 - 1 + powt;
            //     int rem = (int)((baseSum % step + step) % step);

            //     if (rem < 0) rem += step;

            //     int lmod = l0 % step;
            //     int delta = rem >= lmod ? rem - lmod : rem + step - lmod;
            //     int first = l0 + delta;
            //     if (first > r0) continue;


            //     int j0 = (first - rem) / step;
            //     int j1 = (r0 - rem) / step;
            //     if (j0 < 0) j0 = 0;
            //     if (j1 < j0) continue;

            //     int Lr = L[rem];
            //     if (Lr <= 0) continue;
            //     if (j0 >= Lr) continue;
            //     if (j1 >= Lr) j1 = Lr - 1;

            //     int64 x0 = (int64)first - l0 + 1;
            //     int64 k0 = (x0 - powt) / step;

            //     int64 two_k0_plus1 = k0 * 2 + 1;
            //     __int128 v = (__int128)baseD * (__int128)two_k0_plus1;
            //     if (v > (__int128)LLONG_MAX) v = (__int128)LLONG_MAX;
            //     if (v < (__int128)LLONG_MIN) v = (__int128)LLONG_MIN;
            //     int64 baseVal = (int64)v;




            //     int64 A = inc;
            //     int64 B = baseVal - (int64)j0 * inc;

            //     int idx0 = offset[rem] + j0;
            //     int idx1 = offset[rem] + j1 + 1;
            //     if (idx0 < 0 || idx0 >= totalSlots) continue;
            //     if (idx1 < 0 || idx1 >= totalSlots) continue;

            //     diffA[idx0] += A;
            //     diffA[idx1] -= A;
            //     diffB[idx0] += B;
            //     diffB[idx1] -= B;

            // }

                        for (auto &op : ops) {
                int l0 = op.first; // zero-based
                int r0 = op.second;
                int len = r0 - l0 + 1;
                if (len < powt) continue; 

                // compute remainder class where the needed positions fall
                long long baseSum = (long long)l0 - 1 + powt; 
                int rem = (int)((baseSum % step + step) % step);

                // if r0 < rem there are no positions in this class inside [l0..r0]
                if (r0 < rem) continue;

                // j0 = index inside the remainder-class for the first valid element
                long long numer_j0 = baseSum - rem;
                if (numer_j0 < 0) continue; // safety (shouldn't normally happen)
                int j0 = (int)(numer_j0 / step);

                // j1 = last index inside the remainder-class with pos <= r0
                int j1 = (r0 - rem) / step;

                int Lr = L[rem];
                if (Lr <= 0) continue;
                if (j0 >= Lr) continue;
                if (j1 < j0) continue;
                if (j1 >= Lr) j1 = Lr - 1;

                // value for class index j: value = baseD * (2*(j-j0) + 1)
                // which equals: (inc) * j + (baseD - inc * j0)
                int64 A = inc;
                int64 B = baseD - inc * (int64)j0;

                int idx0 = offset[rem] + j0;
                int idx1 = offset[rem] + j1 + 1; // exclusive end in diff arrays

                // idx0 and idx1 must be inside [0..totalSlots-1]
                // (we built offsets with +1 sentinel per class, so idx1 is safe)
                diffA[idx0] += A;
                diffA[idx1] -= A;
                diffB[idx0] += B;
                diffB[idx1] -= B;
            }


            applyDifferences(n, step, L, offset, diffA, diffB, ans);

           

        }

        

   
        bool first = true;
        for (int i = 0; i < n; ++i) {
            if (!first) cout << ' ';
            first = false;
            cout << ans[i];
        }
        cout << '\n';

    }
    return 0;
}
