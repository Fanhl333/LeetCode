/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAXSIZE 1024
 char **g_ret;
 int g_retSize;
bool IsValid(char *s, int len)
{
    if (s[0] == '\0') {
        return false;
    }
    if(len > 1 && s[0] == '0') {
        return false;
    }

    int tmp = 0;        
    for (int i = 0; i < len; i++) {
        tmp = tmp * 10 + s[i] - '0';
    }
    if (tmp <= 255 && tmp >= 0) {
        return true;
    }
    return false;
    
}
void Dfs(char *s, char *tmpIp, int idx, int index)
{
    if (index == 4) {
        if (s[0] == '\0') {
            tmpIp[idx] = '\0';
            g_ret[g_retSize] = malloc(sizeof(char) * 20);
            if (g_ret[g_retSize] == NULL) {
                return;
            }
            strcpy(g_ret[g_retSize], tmpIp);
            g_retSize++;
            return;
        } else {
            return;
        }
    }
    if (strlen(s) > 12 - index * 3) {
        return;
    }
    if (index > 0) {
        tmpIp[idx++] = '.';
    }
    int tmpIndx;
    for (int len = 1; len <= 3 && len <= strlen(s); len++) {
        if (IsValid(s, len)) {
            tmpIndx = idx;
            for(int i = 0; i < len; i++) {
                tmpIp[tmpIndx] = s[i];
                tmpIndx++;
            }
            Dfs(&s[len], tmpIp, tmpIndx, index + 1);
        }
    }
}

char **restoreIpAddresses(char *s, int *returnSize)
{
    char **ret = (char **)malloc(sizeof(char *) * MAXSIZE);
    if (ret == NULL) {
        return;
    }
    g_ret = ret;
    g_retSize = 0;
    char tmpIp[20] = {0};
    Dfs(s, tmpIp, 0, 0);
    *returnSize = g_retSize;
    return ret;
}
