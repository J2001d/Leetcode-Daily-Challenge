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
    
    bool checkInclusion(string s1, string s2) {
        int k = sz(s1);
        int n = sz(s2);
        if(k>n){
            return false;
        }
        if(k==n){
            sort(all(s1));
            sort(all(s2));
            if(s1 == s2){
                return true;
            }
            return false;
        }
        
        unordered_map<char,int> g1;
        rep(i,0,k){
            g1[s1[i]]++;
        }
        
        unordered_map<char,int> g2;
            
        rep(i,0,n){       
            if(i<k){
                g2[s2[i]]++;
            }
            if(i==k && g1==g2){
                return true;
            }
            else if(i>=k){
                g2[s2[i]]++;
                g2[s2[i-k]]--;
                if(g2[s2[i-k]] == 0){
                    g2.erase(s2[i-k]);
                }
                if(g1==g2){
                    return true;
                }
                // watch(g1);
                // watch(g2);
            }
        }
        if(g1==g2){
            return true;
        }
        return false;
        
    }
};
