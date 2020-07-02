#define MAX_SIZE 26
typedef struct Trie_ {
    bool isWord;
    struct Trie *children[MAX_SIZE];
} Trie;

Trie *CreateNode()
{
    Trie *ans = malloc(sizeof(Trie));
    if (ans == NULL) {
        return NULL;
    }
    ans->isWord = false;
    for (int i = 0; i < MAX_SIZE; i++) {
        ans->children[i] = NULL;
    }
    return ans;
}

void AddWord2Trie(Trie *root, char *w)
{
    int wLen = strlen(w);
    Trie *cur = root;
    for (int i = 0; i < wLen; i++) {
        int tmp = w[i] - 'a';
        if (cur->children[tmp] == NULL) {
            Trie *node = CreateNode();
            cur->children[tmp] = node;
        } 
        cur = cur->children[tmp];
    }
    cur->isWord = true;
}

/* 遍历释放树上涉及到的所有内存 */
void FreeTrie(Trie *tree)
{
    if (tree == NULL) {
        return;
    }

    Trie *tempNode;
    int loop;

    for (loop = 0; loop < MAX_SIZE; loop++) {
        FreeTrie(tree->children[loop]);
        tree->children[loop] = NULL;
    }

    free(tree);
    return;
}

char * replaceWords(char ** dict, int dictSize, char * sentence){
    if (dict == NULL || dictSize == 0) {
        return sentence;
    }
    int sentenceLen = strlen(sentence);
    int ansIdx = 0;
    char *ans = malloc(sizeof(char) * (2 + sentenceLen));
    if (ans == NULL) {
        return NULL;
    }

    Trie *root = CreateNode();
    for (int i = 0; i < dictSize; i++) {
        AddWord2Trie(root, dict[i]);
    }

    int ll = 0, rr = 0;
    while (rr <= sentenceLen) {
        if (sentence[rr] != ' ' && rr != sentenceLen) {
            rr++;
            continue;
        }
        Trie *cur = root;
        for (int i = ll; i < rr; i++) {
            if (cur != NULL) {
                if (cur->isWord == true) {
                    break;
                }
                int idx = sentence[i] - 'a';
                cur = cur->children[idx];
            }
            ans[ansIdx++] = sentence[i];
        }
        // 空格赋值
        ans[ansIdx++] = sentence[rr++];
        ll = rr;
    }
    ans[ansIdx] = '\0';
    FreeTrie(root);
    return ans;
}