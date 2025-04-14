//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        unordered_map<char,int>freq;
        for(char ch : s){
            freq[ch]++;
        }
    char result = CHAR_MAX;
    int maxCount = 0;

    for (auto &pair : freq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            result = pair.first;
        } else if (pair.second == maxCount) {
            result = min(result, pair.first);
        }
    }

    return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends