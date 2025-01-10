class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        //map digits to letters
        vector<string>mapping={
            "",     //0
            "",     //1
            "abc",  //2
            "def",  //3
            "ghi",  //4
            "jkl",  //5
            "mno",  //6
            "pqrs", //7
            "tuv",  //8
            "wxyz", //9
        };
        vector<string>result; //to store letter combo
        string current; //temporary string to build combos

        //backtrack ashte
        backtrack(digits,0,mapping,current,result);
        return result;
    }

    private:
    void backtrack(const string& digits,int index, const vector<string>&mapping,string current,vector<string>& result)
    {
        //base case: if the current combo has reached length of digits
        if(index==digits.size())
        {
            result.push_back(current);
            return;
        }

        //get the letters mapped to current digits
        string letters=mapping[digits[index]-'0'];

        //andre lets say you typed 23 in keypad , its 2&3, 23 is
        //string alva , our goal is to figure out which letters these
        //characters correspond to on a phone keypad for eg : 2 maps to abc
        //3 maps to def.


        // now 23 is digits alva , andre stored in digits variable which 
        //is a string. digits[0]=2 and digits[1]=3.

        //2& are chars , convert to int so that we can use as index.

        //chars are represented like 0,1,2,3....9 by ascii
        // '0'=48 , '1'=49 , '2'=50

        //subtracting '0' from '2' gives 50-48=2 that is 2.

        // use that 2 to access map. index 2 in map is abc . Hangee :)

        //now iterate over the chars represented by that letters , andre 
        //first you get string letters=mappping[digirs[index]-'0] , you get
        // 2 as mentioned in line 54 , you get abc mapped. Now do take or 
        //not take method for abc and generate all possible combos.

        //// Iterate over the letters(abc for 2 and def for 3) and recurse
        for(char letter:letters)
        {
            //include the letter in current combo
            current.push_back(letter);
            //move to next digit
            backtrack(digits,index+1,mapping,current,result);
            //backtrack by removing the last added letter
            current.pop_back();
        }
    }
};