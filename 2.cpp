#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define print(x) cout<<x<<'\n'
#define printe(x) cout<<x<<endl
#define prints(x) cout<<x<<" "
#define rep(i,a,b) for (int i=a;i<b;i++)
#define maxVec(v) *max_element(v.begin(),v.end())
#define minVec(v) *min_element(v.begin(),v.end())
#define sortVec(v) sort(v.begin(),v.end())
#define bpcnt(a) __builtin_popcount(a)
#define bpcntll(a) __builtin_popcountll(a)
inline ll lsb(ll n) {return n&-n;}
inline ll msb(ll n) {return (1 << (31 - __builtin_clz(n)));}

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
// bool sortbysec(const pair<ll,ll> &a,
// 			const pair<ll,ll> &b)
// {
// 	return (a.second < b.second);
// }
// Fill whole array with 0.
// memset(arr, 0, n*sizeof(arr[0]));
// Min heap: priority_queue<ll, vector<ll>, greater<ll> > min

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(26,0);
    int dist = 0;
    rep(i,0,n) {
        if (f[s[i]-'a']==0) dist++;
        f[s[i]-'a']++;
    }
    int maxdist;
    for (int i=1;i<=dist;i++) {
        if (n%i==0) maxdist = i;
    }
    int finFreq = n/maxdist;
    vector<pair<int,char>> pos;
    vector<pair<int,char>> neg;
    vector<pair<int,char>> negpos;
    rep(i,0,26) {
        if (f[i]!=0) {
            if (f[i] < finFreq) {
                neg.push_back({f[i]-finFreq, i+'a'});
                negpos.push_back({f[i], i+'a'});
            }
            else if (f[i] > finFreq) {
                pos.push_back({f[i]-finFreq, i+'a'});
            }
        }
    }
    sort(pos.begin(),pos.end(),greater<pair<int,char>>());
    sortVec(neg);
    sortVec(negpos);
    int possz = pos.size(), negsz = neg.size();
    if (possz==0 and negsz==0) {
        print(0);
        print(s);
        return;
    }
    int ipos=0, ineg=0, ops=0;
    map<char,vector<pair<char,int>>> m;
    while (true) {
        if (ipos==possz) break;
        int op = min(pos[ipos].first,-1*neg[ineg].first);
        ops += op;
        m[pos[ipos].second].push_back({neg[ineg].second,op});
        pos[ipos].first -= op;
        neg[ineg].first += op;
        if (pos[ipos].first==0) ipos++;
        if (neg[ineg].first==0) ineg++;
        if (ipos==possz) break;
    }
    vector<pair<int,char>> nw;
    rep(i,ineg,negsz) {
        if (i==ineg) {
            nw.push_back({finFreq+neg[ineg].first, neg[ineg].second});
        }
        else nw.push_back({negpos[i].first, negpos[i].second});
    }
    sortVec(nw);
    int i=0,j=nw.size()-1;
    while (true) {
        if (i>=j) break;
        int op = min(nw[i].first, finFreq-nw[j].first);
        ops += op;
        m[nw[j].second].push_back({nw[i].second,op});
        nw[j].first += op;
        nw[i].first -= op;
        if (nw[j].first==finFreq) j--;
        if (nw[i].first==0) i++;
        if (i>=j) break;
    }
    
    print(ops);
    rep(i,0,n) {
        if (m.find(s[i])!=m.end() and !m[s[i]].empty()) {
            cout<<m[s[i]][0].first;
            m[s[i]][0].second--;
            if (m[s[i]][0].second==0) m[s[i]].erase(m[s[i]].begin());
        }
        else cout<<s[i];
    }
    cout<<nl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int it,t=1;
    cin>>t;
    for (it=0;it<t;it++) {
        solve();
    }
    return 0;
}
