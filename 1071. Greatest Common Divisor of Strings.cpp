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
#define ll 				  long long
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

/*
#define int long long 
#undef int 
*/

class Solution {
public:
    
    unordered_set<string> helper(string s) {
        unordered_set<string> ans;
        string t;

        rep (i, 0, sz(s)) {
            t += s[i];

            int f = 1;

            for (int j = i + 1; j < sz(s); j += i + 1) {
                if (t != s.substr(j, sz(t))) {
                    f = 0;
                    break;
                }
            }
            if (f){
                ans.insert(t);
            }
        }
        return ans;
    }
    
    string gcdOfStrings(string str1, string str2) {
        
        // checking if any portion of string in repeating in itself if then add to set
        unordered_set<string> s1 = helper(str1);
        unordered_set<string> s2 = helper(str2);
        
        string ans;
        int len = 0;
        // watch(s1);
        // watch(s2);
        
        // Now we are finding common string in both with max length
        for(string s : s1) {
            if(s2.find(s) != s2.end() && sz(s) > len) {
                len = sz(s);
                ans = s;
            }
        }
        
        return ans;
    }
};
