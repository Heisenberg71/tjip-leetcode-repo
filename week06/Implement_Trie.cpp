class Trie {
private:
    class trieNode{
    public:
        const static int LIM = 26;
        bool hasEnd;
        shared_ptr<trieNode> next[LIM];
        trieNode(){
            hasEnd = false;
            for(int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
    };
public:
    shared_ptr<trieNode> root;
    Trie() {
        root = make_shared<trieNode>();
    }
    
    void insert(string word) {// T.C: O(string length), M.C: O(string length)
        auto currNode = root;
        for(char& ch: word){
            int index = ch - 'a';
            if(currNode -> next[index] == nullptr) currNode -> next[index] = make_shared <trieNode>();
            currNode = currNode -> next[index];
        }
        currNode -> hasEnd = true;
    }
    
    bool search(string word, bool isPrefix = false) {// T.C: O(string length), M.C: O(string length)
        auto currNode = root;
        for(char& ch: word){
            int index = ch - 'a';
            if(currNode -> next[index] == nullptr) return false;
            currNode = currNode -> next[index];
        }
        return isPrefix || currNode -> hasEnd;
    }
    
    bool startsWith(string prefix) {// T.C: O(string length), M.C: O(string length)
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
