#define ll long long int
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int n = a.size();

        vector<int> ans;

        int carry = 0;

        while(!a.empty() || k!=0)
        {
            int lastDigit_1 = a.empty() ? 0 : a.back();
            int lastDigit_2 = k%10;

            int sum = lastDigit_1 + lastDigit_2 + carry;

            ans.push_back(sum%10);

            carry = sum/10;

            if(!a.empty()) {
                a.pop_back();
            }

            k = k/10;
        }

        if(carry!=0){
            ans.push_back(carry);
        } 

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
