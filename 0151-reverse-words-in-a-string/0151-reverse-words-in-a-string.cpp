class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string token  = "";
        string result = "";

        while(ss >> token) {

            result = token + " " + result;
        }

        int n = result.size();
        return result.substr(0, n-1);
    }
};