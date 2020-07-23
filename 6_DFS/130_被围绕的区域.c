int g_direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(char** board, int boardSize, int* boardColSize, int x, int y)
{
    if (x < 0 || x >= boardSize || y < 0 || y >= *boardColSize) {
        return false;
    }
    if (board[x][y] == 'O') {
        return true;
    }
    return false;

}
void helper(char** board, int boardSize, int* boardColSize, int x, int y)
{
    board[x][y] = '#';
    for (int i = 0; i < 4; i++) {
        int dx = x + g_direction[i][0];
        int dy = y + g_direction[i][1];
        if (isValid(board, boardSize, boardColSize, dx, dy)) {
            helper(board, boardSize, boardColSize, dx, dy);
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            bool isEdge = i == 0 || i == boardSize - 1 || j == 0 || j == *boardColSize - 1;
            if (isEdge && board[i][j] == 'O') {
                helper(board, boardSize, boardColSize, i, j);
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}
