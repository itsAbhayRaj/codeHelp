class TrieNode {
    public:
     char data;
     TrieNode * children[26];
     bool isTerminal;
     int childCount;
     TrieNode(char data) {
        data = data;
    for(int i =0;i<26;i++){
        children[i] = nullptr;
    }
    isTerminal  = false;
    childCount = 0;
     }
};
class Trie{
    private:
    TrieNode* root;
    void insertUTIL(TrieNode* root,string word){
        if(word.size()==0){
            root->isTerminal = true;
            return ;
        }
        TrieNode* child;
        int index = word[0]-'a';
        if(root->children[index]){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUTIL(child,word.substr(1));
    }
    void lcpUTIL(TrieNode* root,string str,string &res){
        if(root->isTerminal){
            return;
        }
        if(root->childCount==1){
            res+=str[0];
            lcpUTIL(root->children[str[0]-'a'],str.substr(1),res);
        }
        return;
    }
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string word){
        insertUTIL(root,word);
    }
    string lcp(string str){
        string res="";
        lcpUTIL( root, str,res);
        return res;
    }
};
class Solution {
    private:
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie * t = new Trie();
        for(string s : strs){
            t->insert(s);
        }

        return t->lcp(strs[0]);
    }
};