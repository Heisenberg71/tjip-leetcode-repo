class Solution {
public:
    static const int MAX_CHAR_LIM = 26;
    
    vector <int> index_of[MAX_CHAR_LIM];
    vector <int> :: iterator it;

    bool isMatched(string &currentWord){
        int currentIndex = -1;
        for(int i = 0; i < currentWord.size(); i++){
            it = lower_bound(index_of[ currentWord[i] - 'a' ].begin(), index_of[ currentWord[i] - 'a' ].end(), currentIndex + 1);
            if(it == index_of[ currentWord[i] - 'a' ].end()) return 0;
            currentIndex = *it;
        }
        return 1;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i = 0; i < s.size(); i++){
            index_of[ s[i] - 'a' ].push_back(i);
        }

        int matchedSubsequence = 0;
        for(auto eachWord : words){
            matchedSubsequence += isMatched(eachWord);
        }

        return matchedSubsequence;
    }
};
