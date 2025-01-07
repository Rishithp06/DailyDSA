class Solution {
public:
// At any point in the recursion:

// You cannot add a closing parenthesis ()) if it would result in more closing parentheses than opening ones already added.
// You can only add an opening parenthesis (() if the total number of opening parentheses added so far is less than 
// 𝑛
// n.
// Base Case:

// When the number of opening and closing parentheses added equals 
// 𝑛
// n, you have a valid combination.
// Recursive Approach
// Start with an empty string and two counters:

// open: The number of opening parentheses added.
// close: The number of closing parentheses added.
// At each recursive call:

// If open < n, add an opening parenthesis and recurse.
// If close < open, add a closing parenthesis and recurse.

    void generatee(int n,int open,int close,string current,vector<string>&res)
    {
        if(open==n && close==n)
        {
            res.push_back(current);
            return;
        }

        if(open<n)
        {
            generatee(n,open+1,close,current+"(",res);
        }
        if(close<open)
        {
            generatee(n,open,close+1,current+")",res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generatee(n,0,0,"",res);
        return res;
    }
};