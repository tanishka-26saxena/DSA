 //A trie (derived from retrieval) is a multiway tree data structure
 //used for storing strings over an alphabet. It is used to store a large amount of strings.

 //trie mai hmesha ek terminal node bhi bnayi jati haii jsme end node ko store krte hai ....ye searching ke time help krta haii
 //agar ye terminal node nhi bnayenge to ek anomaly mai phas skte hai
 //example : hmne TIME store kraya nodes mai aur hme search krna hai TIM to agar terminal node nhi hoga to TIM search krne 
 //par bhi true btayega ...jo ki galat hoga

 //THIS CODE IS NOT WORKING ON VS CODE .....TRY IT ON ANY OTHER COMPILER


 //time complexity for insertion in trie -> O(l)
 //time complexity for searching in trie -> O(l)

 
#include<iostream>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        //assuming words will be in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //RECURSION
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

   bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } 
        else {
            return false; // word not present
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
/*
*/
};
int main() 
{
    Trie* t = new Trie();

    t->insertWord("abcd");
   //cout << "present or not? " << t->searchWord("abcd") << endl;
    cout<<"hey";
    return 0;
}