bool dfs(char *s, int idx, char **wordDict, int wordDictSize, bool *flag)
{
    int sLen = strlen(s);
    if (sLen == idx) {
        return true;
    }
    if (!flag[idx]) {
        return false;
    }
    for (int i = 0; i < wordDictSize; i++) {
        int subWordDictLen = strlen(wordDict[i]);
        if (idx + subWordDictLen > sLen) {
            continue;
        }
        char *tmp = s + idx;
        if (strncmp(tmp, wordDict[i], subWordDictLen) != 0) {
            continue;
        }
        if (dfs(s, idx + subWordDictLen, wordDict, wordDictSize, flag)) {
            return true;
        }
    }
    flag[idx] = false;
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int sLen = strlen(s);
    bool *flag = malloc(sizeof(bool) * sLen);
    for (int i = 0; i < sLen; i++) {
        flag[i] = true;
    }
    return dfs(s, 0, wordDict, wordDictSize, flag);
}
