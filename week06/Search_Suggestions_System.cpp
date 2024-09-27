//O(P + S*MAX_P*3)  P = number of all characters in products vector of strings
                 // S = size of searchString
                 // MAX_P = max string length of products vector of strings


class Solution {
private:
    const static int LIM = 26;

    class trieNode{
    public:
        int hasEnd;
        trieNode* next[LIM];
        trieNode(){
            hasEnd = false;
            for(int i = 0; i < LIM; i++)
                next[i] = nullptr;
        }
    };

    void insert(string& str, trieNode* root){
        auto currNode = root;
        for(int i = 0; i < str.size(); i++){
            int index = str[i] - 'a';
            if(currNode -> next[index] == nullptr) currNode -> next[index] = new trieNode();
            currNode = currNode -> next[index];
        }
        currNode -> hasEnd = true;
    }

    void getSuggestions(trieNode* currNode, vector <string> &suggestion, string& prefix){
        if(suggestion.size() == 3 || currNode == nullptr) return;
        if(currNode -> hasEnd) suggestion.push_back(prefix);
        for(int ch = 0; ch < LIM; ch++){
            if(currNode -> next[ch] != nullptr){
                prefix.push_back((char)(ch + 'a'));
                getSuggestions(currNode -> next[ch], suggestion, prefix);
                prefix.pop_back();
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trieNode* root = new trieNode();
        for(int i = 0; i < products.size(); i++)
            insert(products[i], root);        
        
        vector < vector<string> > allSuggestions;
        auto currNode = root;
        string prefix;
        for(int i = 0; i < searchWord.size(); i++){
            prefix.push_back(searchWord[i]);
            if(currNode != nullptr) currNode = currNode -> next[ searchWord[i] - 'a' ];
            vector <string> suggestion;
            getSuggestions(currNode, suggestion, prefix);
            allSuggestions.push_back(suggestion);
        }

        return allSuggestions;
    }
};
