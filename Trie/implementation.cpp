#include <iostream>
using namespace std;

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
    bool searchUTIL(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0]-'a';
        if (root->children[index])
        {
            return searchUTIL(root->children[index], word.substr(1));
        }
            return false;
        
        
    }
    void removeUTIL(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = false;
            return ;
        }
        int index = word[0]-'a';
        if (root->children[index] == NULL) {
            return;
        }
        removeUTIL(root->children[index],word.substr(1));

    }
    TrieNode *root;
public:
    
    Trie()
    {
        root = new TrieNode('\0');
    }
    
    void insert(string word)
    {
        insertUTIL(root, word);
    }
    bool search(string word)
    {
        return searchUTIL(root, word);
    }
    void removeWord(string word){
        removeUTIL(root,word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd");
    cout<<t->search("abcd")<<endl;
    t->insert("anhj");
    cout<<t->search("hello")<<endl;
    cout<<t->search("anhj")<<endl;
    t->insert("hello");
    cout<<t->search("hell")<<endl;
    t->insert("helli");
    cout<<t->search("helli")<<endl;
    cout<<t->search("hello")<<endl;
    cout<<"Deletions"<<endl;
    t->removeWord("anhj");
    cout<<t->search("anhj")<<endl;
    cout<<t->search("abcd")<<endl;
    t->removeWord("abcd");
    t->removeWord("hell");
    cout<<t->search("hello")<<endl;
    t->insert("hell");
    t->insert("abcd");
    t->insert("an");
        cout<<t->search("hell")<<endl;
    cout<<t->search("abcd")<<endl;
    cout<<t->search("an")<<endl;

}