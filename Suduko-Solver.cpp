bool isValid(vector<vector<char>> &board,int i,int j, char ch){
        int n=board.size();
        int m=board[0].size();
        for(int idx=0;idx<9;idx++){
            if(board[idx][j]==ch)return false;
            if(board[i][idx]==ch)return false;
            if(board[3*(i/3)+idx/3][3*(j/3)+idx%3]==ch)return false;
        }
        return true;
    }
    bool sudukoSolver(vector<vector<char>> &board){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(sudukoSolver(board))return true;
                            else{
                                board[i][j]='.';
                                // return false;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
