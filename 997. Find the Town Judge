void __print(int x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << x; }
void __print(const char *x) { cout << x; }
void __print(const string &x) { cout << x; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cout << '{';
    __print(x.first);
    cout << ", ";
    __print(x.second);
    cout << '}';
}
template<typename T>
void __print(const T &x) {
    int f = 0;
    cout << '{';
    for (auto &i : x) {
        cout << (f++ ? ", " : "");
        __print(i);
    }
    cout << "}";
}
void _print() {
    cout << "]\n";
}
template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) {
        cout << ", ";
    }
    _print(v...);
}

#define watch(x...) cout << "[" << #x << "] = ["; _print(x)
#define lld               long double
#define INF               1000000000000000000
#define pb                push_back
#define all(x)            x.begin(),x.end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define sz(x)             (int)((x).size())
#define f1                first
#define s2                second
#define fix(x)            fixed << setprecision(x)
#define endl              "\n"
#define bigprime          1000000007
#define MOD               1000000007
#define gcd(a,b)          __gcd((a),(b))
#define lcm(a,b)          (a/gcd(a,b))*b
#define scanvec(a,n)      rep(i,0,n){cin>>a[i];}
#define fast              ios_base::sync_with_stdio(false);cin.tie(NULL);
#define makeuniq(v)       v.resize(unique(all(v)) - v.begin());
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> st;
        int N = sz(trust);
        rep(i,1,n+1){
            st.insert(i);
        }
        rep(i,0,N){
            // watch(trust[i][0]);
            st.erase(trust[i][0]);
        }
        vector<int> ans;
        if(!st.empty()){
            queue<int> q;
            for(auto x:st){
                q.push(x);
                // watch(x);
            }
            
            while(!q.empty()){
                int ele = q.front();
                // watch(ele);
                q.pop();
                set<int> check;
                for(auto x:trust){
                    if(x[1] == ele){
                        check.insert(x[0]);
                    }
                }
                // watch(sz(check));
                if(sz(check) == n-1){
                    ans.pb(ele);
                }
            }
        }
        if(sz(ans) == 1){
            return ans[0];
        }
        return -1;
    }
};
