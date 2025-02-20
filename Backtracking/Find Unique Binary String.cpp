// approach - 1

// backtracking 

// tc = pow(2,n);
// sc = o(n)



class Solution {
public:
    bool found = false; 
    
    void f(vector<string>& nums, string& ans, set<string>& st, int n, string temp) {
        if (temp.size() == n) {
            if (st.find(temp) == st.end()) {
                ans = temp;
                found = true;
            }
            return;
        }
        
        if (found) return; 
        
        f(nums, ans, st, n, temp + '0');
        
        if (found) return; 
        
        f(nums, ans, st, n, temp + '1');
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        set<string> st(nums.begin(), nums.end());
        f(nums, ans, st, n, "");
        return ans;
    }
};


// approach - 2
// Cantor's Diagonalization (Optimized Approach)

// tc = o(n)
// sc = o(1)

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};
