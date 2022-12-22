#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl
typedef long long ll;
typedef unsigned long long ull;

// canConstruct(target,wordBank) return a boolean indeicating whether or not the target can be constructed by concatenating elements of wordBank

bool canConstructRec(string target,vector<string>& wordBank) {
    if (target=="") return true;
    for (auto& it:wordBank) {
        ll found=target.find(it);
        if (found!=string::npos) {
            if (found==0) {
                string suff=target.substr(it.length());
                if (canConstructRec(suff,wordBank)) return true;
            }
        }
    }
    return false;
}

bool canConstruct(string target,vector<string>& wordBank) {
    ll n=target.length();
    vector<bool> v(n+1,false);
    for (ll i=0;i<n+1;i++) {
        if (i==0) v[i]=true;
        else {
            string nt=target.substr(n-i,i);
            for (auto& it:wordBank) {
                ll found=nt.find(it);
                if (found!=string::npos) {
                    if (found==0) {
                        // string suff=target.substr(it.length());
                        // if () return true;
                        if (v[i-it.length()]) {
                            v[i]=true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return v[n];
}

vector<vector<string>> canConstructStrs(string target,vector<string>& wordBank) {
    int n=target.length();
    vector<vector<string>> init(1,vector<string>(1,""));
    vector<vector<vector<string>>> v(n+1,init);
    for (int i=1;i<n+1;i++){
        string nt=target.substr(n-i,i);
        for (auto& it:wordBank) {
            vector<string> temp={it};
            int found=nt.find(it);
            if (found!=string::npos) {
                if (found==0) {
                    int x=i-it.length();
                    if (x==0) {
                        v[i].push_back(temp);
                    }
                    else {
                        vector<vector<string>> temp1=v[x];
                        if (temp1!=init) {
                            for (auto& it1:temp1) {
                                if (it1==temp1[0]) continue;
                                it1.insert(it1.begin(),temp.begin(),temp.end());
                                v[i].push_back(it1);
                            }
                        }
                    }
                }
            }
        }
    }
    return v[n];
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<vector<string>> init(1,vector<string>(1,""));
    vector<string> out;
    vector<vector<string>> vs=canConstructStrs(s,wordDict);
    if (vs==init) return out;
    for (auto& it:vs) {
        if (it==vs[0]) continue;
        string s1="";
        int len=it.size();
        for (int i=0;i<len;i++) {
            if (i==0) {
                s1+=it[0];
                // print("This is for 0");
                // print(s1);
                // print("0 ended");
                continue;
            }
            s1=s1+" ";
            s1+=it[i];
            // print(s1);
        }
        out.push_back(s1);
    }
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    vector<string> v(n,"");
    cin>>s;
    for (int i=0;i<n;i++) cin>>v[i];
    vector<vector<string>> init(1,vector<string>(1,""));
    vector<vector<string>> vs=canConstructStrs(s,v);
    if (vs==init) {
        print("Not possible");
    }
    else {
        // for (auto& it:vs) {
        //     if (it==vs[0]) continue;
        //     for (auto& it1:it) cout<<it1<<" ";
        //     cout<<endl;
        // }
        vector<string> vs1=wordBreak(s,v);
        for (auto& it:vs1) {
            print(it);
        }
    }
    return 0;
}