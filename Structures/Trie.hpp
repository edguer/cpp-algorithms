#include <bits/stdc++.h>

#ifndef TRIE
#define TRIE

using namespace std;

class TrieNode
{
public:
    TrieNode(char val, bool end_word)
    {
        value = val;
        word_end = end_word;
        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }
    }
    char GetValue()
    {
        return value;
    }
    void SetValue(char val)
    {
        value = val;
    }
    bool GetWordEnd()
    {
        return word_end;
    }
    void SetWordEnd(bool end_word)
    {
        word_end = end_word;
    }
    TrieNode *GetChild(int index)
    {
        return children[index];
    }
    void SetChild(int index, TrieNode *node)
    {
        children[index] = node;
    }

private:
    char value;
    bool word_end;
    TrieNode *children[27];
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode(' ', false);
    }
    void AddWord(char *word, int len)
    {
        TrieNode *node = root;
        for (int i = 0; i < len; i++)
        {
            char letter = word[i];
            int letter_index = letter - 'a';
            bool word_end = (i == len - 1);

            TrieNode *child_node = node->GetChild(letter_index);
            if (child_node == NULL)
            {
                TrieNode *new_node = new TrieNode(letter, word_end);
                node->SetChild(letter_index, new_node);
                node = new_node;
            }
            else
            {
                node = child_node;
                if (word_end)
                {
                    node->SetWordEnd(true);
                }
            }
        }
    }
    bool Search(char *word, int len)
    {
        bool found = false;

        TrieNode *node = root;
        for (int i = 0; i < len; i++)
        {
            char letter = word[i];
            int letter_index = letter - 'a';
            bool word_end = (i == len - 1);

            TrieNode *child_node = node->GetChild(letter_index);
            if (child_node == NULL)
            {
                break;
            }
            else
            {
                node = child_node;
                if (word_end && node->GetWordEnd())
                {
                    found = true;
                }
            }
        }

        return found;
    }
    void Print()
    {
        TrieNode *node = root->GetChild(0);
        int level = 0;
        for (int i = 0; i < 27; i++)
        {
            TrieNode *child_node = node->GetChild(i);
            if (child_node != NULL)
            {
                cout << "level " << level << " position " << i << " value empty " << child_node->GetValue() << endl;
            }
        }
    }

private:
    TrieNode *root;
};

#endif