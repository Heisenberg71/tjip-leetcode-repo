/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    random_device rd;
    int getScore(string s1, string s2)
    {
        int score = 0;
        for(int i = 0; i < s1.size(); i++)
            score += (s1[i] == s2[i]);
        return score;
    }
    vector<string> prunning(int idx, int currScore, vector <string>& words){
        vector <string> newWords;
        for(auto eachWord: words){
            if(currScore == getScore(eachWord, words[idx])) newWords.push_back(eachWord);
        }
        return newWords;
    }
public:
    void findSecretWord(vector<string>& words, Master& master) {
        while(words.size() > 1){
            int idx = rd()%words.size();
            int score = master.guess(words[idx]);
            words = prunning(idx, score, words);
        }
        master.guess(words[0]);
    }
};
