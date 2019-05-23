#include <iostream>

int** board = new int*[3];

using namespace std;
//Score
//human = 1
//blank = 0
//computer = -1
void drawBoard(int** board)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] == 0) cout << "_"; 
			if(board[i][j] == 1) cout << "O"; 
			if(board[i][j] == -1) cout << "X"; 
		}

		cout<<endl;
	}
	cout<< endl;
}


int checkWin()
{
	int total = 0;
	for(int j = 0; j < 3; j++) //check rows
	{
		for(int i = 0; i < 3; i++)
			total += board[i][j]; 
		if(total == 3 | total == -3)
			return total/3;
		total = 0;
	}
	for(int i = 0; i < 3; i++) //check columns
	{
		for(int j = 0; j < 3; j++)
			total += board[i][j]; 
		if(total == 3 | total == -3)
			return total/3;
		total = 0;
	}

	for(int i = 0; i < 3;i++ ) //check diagonals
		total += board[i][i];
	if(total == 3 | total == -3)
		return total/3;
	total = 0;
	total+=board[2][0];
	total+=board[1][1];
	total+=board[0][1];

	return 0;
}

void duplicateBoard(int** board, int** board2)
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) board2[i][j] = board[i][j];
}

int minimax(int** board,int player)//algorithm used to check
{
	//Player 1 = human = 1
	//PLayer 2 = bot = -1
	if(checkWin() == 1) return -1;
	if(checkWin() == -1) return 1;

	int move = -1;
	int score = -2;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] == 0)
			{
				int** board2 = new int*[3];
				cout << board2 << endl;
				for(int i = 0; i < 3; ++i)
   			 		board2[i] = new int[3];
   			 	duplicateBoard(board, board2);
   			 	drawBoard(board2);
				if(player == 1) board2[i][j] = 1;
				if(player == -1) board2[i][j] = -1;
				int scoreForMove = minimax(board2,(player*-1));
				delete[] board2;
				if(scoreForMove > score) {
					score = scoreForMove;
					move = i;
				}
			}
		}
	}
	return move;

	if (move == -1) return 0;
	return score;

}

int main()
{
	for(int i = 0; i < 3; ++i)
    board[i] = new int[3];

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) board[i][j] =0;
	while(1)
	{
		int i;
		int j;
		drawBoard(board);
		cout << "It's your turn" << endl;
		cin >> i;
		cin >> j;
		board[i][j] = 1;
		drawBoard(board);
		if(checkWin())
			break;
		cout << "It's bots turn" << endl;
		int x = minimax(board,-1);
		cout << x << endl;
		i = x/3;
		j = x%3;
		board[i][j] = -1;
		drawBoard(board);
		if(checkWin())
			break;
	}
	return 0;
}


