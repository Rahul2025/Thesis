    #include <cstdio>
    #include <cmath>
    #include <queue>
    #include <algorithm>
    #include <vector>
     
    using namespace std;
     
    typedef long double ldb;
     
    int main() {
    ldb k;
    scanf("%Lf", &k);
    int n = 1;
    while(powl(2, n / (n + ldb(1))) <= k) ++n;
    printf("%d\n", 2 * n);
    vector<ldb> v;
    for(int i = 0; i < n; ++i) {
    v.push_back(powl(2, i / ldb(n)) / 2.0);
    v.push_back(powl(2, i / ldb(n)) / 2.0);
    }
    ldb s = 0;
    for(unsigned i = 0; i < v.size(); ++i)
    s += v[i];
    for(unsigned i = 0; i < v.size(); ++i)
    v[i] /= s;
    vector<pair<int,int> > proof;
    for(unsigned i = 0; i + 1 < v.size(); i += 2) {
    proof.push_back(make_pair(v.size(), i));
    v.push_back(v[i] + v[i + 1]);
    }
    reverse(proof.begin(), proof.end());
    vector<int> no(v.size(), 0);
    int z = 0;
    for(unsigned i = 0; i < proof.size(); ++i) {
    printf("%d %.15Lf\n", no[proof[i].first], v[proof[i].second]);
    no[proof[i].second] = ++z;
    no[proof[i].second + 1] = no[proof[i].first];
    }
    }
 
