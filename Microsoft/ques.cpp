void solution(int N, vector<int> &R, vector<int> &C)  {
    vector<vector<int>> board(N+2, vector<int> (N+2,  0));
    for(int i = 0; i<R.size(); i++) {
        board[R[i]+1][C[i]+1] = 9;
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(board[i][j] != 9) {
                cnt = 0;
                for(int x = -1; x <= 1; x++) {
                    for(int y = -1; y <= 1; y++) {
                        if(board[i+x][j+y] == 9) cnt++;
                    }
                }
                board[i][j] = cnt;
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j< = N; j++) {
            if(board[i][j] = = 9) {
                cout << "B";
            }
            else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
    return;
}
