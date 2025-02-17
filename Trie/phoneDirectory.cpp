struct TrieNode
{
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('#');
    }
    private:
    void insertUTIL(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUTIL(child, word.substr(1));
    }
    public:
    void insert(string word){
        insertUTIL(root,word);
    }
    void printSuggestions(TrieNode* curr,string & prefix,vector<string> & temp){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char c = 'a' ; c<='z';c++){
            TrieNode* next = curr->children[c-'a'];
            if(next){
                prefix+=c;
                printSuggestions(next,prefix,temp);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string queryStr){
        TrieNode  * prev = root;
        
        string prefix = "";
        vector<vector<string>> result;
        for(int i =0;i<queryStr.size();i++){
            char lastCh = queryStr[i];
            prefix+=lastCh;
            TrieNode* child = prev->children[lastCh-'a'];
            if(!child){
                break;
            }
            vector<string> temp;
            printSuggestions(child,prefix,temp);
            
            result.push_back(temp);temp.clear();
            prev = child;
        }
        return result;
    }
};

vector<vector<string>> phoneDirectory
(vector<string>&contactList, string &queryStr)
{
    Trie * t = new Trie();

    for(string word : contactList){
        t->insert(word);
    }
    return t->getSuggestions(queryStr);
    
}