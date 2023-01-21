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
    vector<string> ans;
    
    int conv(string s){
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }
    bool isValid(string &s){
        vector<string> Help;
        string tmp = "";
        for(auto &x:s){
            if(x == '.'){
                if(tmp == ""){
                    continue;
                }
                Help.pb(tmp);
                
                tmp = "";
            }else{
                tmp += x;
            }
        }
        // if(sz(tmp) >= 2 && tmp[0] == '0'){
        //     return false;
        // }
        // int Here = conv(tmp);
        // if(Here >= 0 && Here <= 255){
        //     return true;
        // }
        
        Help.pb(tmp);
        
        if(sz(Help) == 4){
            for(auto tmp:Help){
                if(sz(tmp) == 0){
                    return false;
                }
                if(sz(tmp) >= 2 && tmp[0] == '0'){
                    return false;
                }
                int Here = conv(tmp);
                if(Here >= 0 && Here <= 255){

                }else{
                    return false;
                }
            }
            return true;
        }
        return false;       
    }
    
    void helper(string &s,int i,string curr){
        
        if(i >= sz(s)){
            // watch(curr);
            if(isValid(curr)){
                ans.pb(curr);
            }
            return;
        }
        
        curr.pb(s[i]);
        
        helper(s,i+1,curr + ".");
        helper(s,i+1,curr);
        
    }

    
    vector<string> restoreIpAddresses(string s) {
        helper(s,0,"");
        return ans;
    }
};
