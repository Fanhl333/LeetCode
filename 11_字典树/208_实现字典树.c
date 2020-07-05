#define MAX_SIZE 26
typedef struct Trie_ {
    bool isWord;
    struct Trie_ *next[MAX_SIZE];
} Trie;

Trie* createTrieNode()
{
    Trie *ans = malloc(sizeof(Trie));
    if (ans == NULL) {
        return NULL;
    }
    ans->isWord = false;
    for (int i = 0; i < MAX_SIZE; i++) {
        ans->next[i] = NULL;
    }
    return ans;
}
/** Initialize your data structure here. */
Trie* trieCreate() {
    return createTrieNode();
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int wordLen = strlen(word);
    Trie *cur = obj;
    for (int i = 0; i < wordLen; i++) {
        int idx = word[i] - 'a';
        if (cur->next[idx] == NULL) {
            cur->next[idx] = createTrieNode();
        }
        cur = cur->next[idx];
    }
    cur->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int wordLen = strlen(word);
    Trie *cur = obj;
    for (int i = 0; i < wordLen; i++) {
        int idx = word[i] - 'a';
        if (cur->next[idx] != NULL) {
            cur = cur->next[idx];
        } else {
            return false;
        }
    }
    return cur->isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    int wordLen = strlen(prefix);
    Trie *cur = obj;
    for (int i = 0; i < wordLen; i++) {
        int idx = prefix[i] - 'a';
        if (cur->next[idx] != NULL) {
            cur = cur->next[idx];
        } else {
            return false;
        }
    }
    return true; 
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        trieFree(obj->next[i]);
        obj->next[i] = NULL;
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/