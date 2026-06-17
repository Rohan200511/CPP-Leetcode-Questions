class Solution {
public:
    int maxWidth;
    string getFinalWord(int i , int j , vector<string>& words , int evenSpaces , int extraSpaces){
        string s = "";

        for(int k = i ; k < j ; k++){
            s += words[k];

            if(k == j - 1) continue;

            for(int i = 1 ; i <= evenSpaces ; i++){
                s += ' ';

                if(extraSpaces > 0){
                    s += ' ';
                    extraSpaces--;
                }
            }
        }

        while(s.length() < maxWidth) s += ' ';
        return s;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        this->maxWidth = maxWidth;
        int n = words.size();

        vector<string>ans;

        int i = 0;

        while(i < n){
            int letterCount = words[i].length();
            int spacesSlots = 0;
            int j = i + 1;

            while(j < n && letterCount + words[j].length() + 1 + spacesSlots <= maxWidth){
                letterCount += words[j].length();
                spacesSlots++; 
                j++;  
            }
            int remSlots = maxWidth - letterCount;

            int evenSpaces = (spacesSlots == 0) ? 0 : remSlots / spacesSlots;
            int extraSpaces = (spacesSlots == 0 ? 0 : remSlots % spacesSlots);

            if(j == n){
                evenSpaces = 1;
                extraSpaces = 0;
            }

            string temp = getFinalWord(i , j , words , evenSpaces , extraSpaces);
            ans.push_back(temp);

            i = j;
        }
        return ans;
    }
};