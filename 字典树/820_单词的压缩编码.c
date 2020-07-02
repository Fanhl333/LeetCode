#define ALPHABET_SIZE 26

typedef struct Trie {
    bool hasChildren;
    struct Trie* children[ALPHABET_SIZE];
}Trie;

Trie* createTrie()
{
    Trie* res = (Trie*)malloc(sizeof(Trie));
    res->hasChildren = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        res->children[i] = NULL;
    }

    return res;
}

void insertWord(Trie* trie, char* word)
{
    int length = strlen(word);
    char oneChar;

    for (int i = length - 1; i >= 0; i--) {
        oneChar = word[i];
        if (trie->children[oneChar - 'a'] == NULL) {
            trie->children[oneChar - 'a'] = createTrie();
            trie->hasChildren = true;
        }
        trie = trie->children[oneChar - 'a'];
    }
}

void freeTrie(Trie* trie)
{
    if (trie == NULL) {
        return;
    }
    Trie* ptr = trie;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(ptr->children[i]);
        ptr->children[i] = NULL;
    }
	free(trie);
}

int g_counts;
void dfs(Trie* trie, int level)
{
    if (trie == NULL) {
        return;
    }

    // visit.
    if (!trie->hasChildren) {
        g_counts += (level + 1);
        return;
    }

    // loop all children.
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->children[i] != NULL) {
            dfs(trie->children[i], level + 1);
        }
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if ((words == NULL) || (wordsSize <= 0)) {
        return 0;
    }

    Trie* trie = createTrie();

    // create Trie
    for (int i = 0; i < wordsSize; i++) {
        insertWord(trie, words[i]);
    }

    // count words.
    g_counts = 0;
    dfs(trie, 0);
    freeTrie(trie);

    return g_counts;
}