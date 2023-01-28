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

class SummaryRanges {
public:
    
    set<pair<int,int>> st;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int L = value -1;
        int H = value +1;
        
        
        // High value should be start of next range
         auto it1 = find_if(all(st), [&](const pair<int,int>& p ){ 
             return p.f1 == H; 
         });
            
         auto it2 = find_if(all(st) , [&](const pair<int,int> &p){
             return p.s2 == L; 
         });
        
        
        if (it1 != st.end() && it2 != st.end()){
            st.insert({it2->f1 , it1->s2});
            st.erase(it1);
            st.erase(it2);
        }else if(it1 != st.end()){
            st.insert({value,it1->s2});
            st.erase(it1);
        }else if(it2 != st.end()){
            st.insert({it2->f1,value});
            st.erase(it2);
        }else{
            auto it = find_if(all(st), [&](const pair<int,int>& p ){ 
                // if value is in between two points
                 return p.s2 >= value && value >= p.f1; 
             });
            if(it == st.end())
                st.insert({value,value});
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        for(auto x:st){
            ans.pb({x.f1,x.s2});
        }
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
