#include <iostream>

int* board = new int[9]; //create an array based off a 9x9 board

using namespace std;
//Score
//human = -1
//blank = 0
//computer = 1
void drawBoard(int* board) //draws the board based on player
{
	for(int i = 0; i < 9; i++)
	{
		if(board[i] == 0) cout << "_"; 
		if(board[i] == 1) cout << "O"; 
		if(board[i] == -1) cout << "X";

		if((i+1) % 3 == 0) cout << endl;
	}
	cout<< endl;
}

int checkWin(int* board) //check victory of board 
{
	int total = 0;
	for(int i = 0; i < 3; i++) //check columns
	{
		total =	board[i] + board[i+3] + board[i+6];
		if(total == 3 | total == -3) return total/3;
	}
	total = 0;
	for(int i = 0; i < 7; i+=3) //check rows
	{
		total =	board[i] + board[i+1] + board[i+2];
		if(total == 3 | total == -3) return total/3;
	}
	total = 0;
	//check left diagonal
	total+=board[2];
	total+=board[4];
	total+=board[6];
	if(total == 3 | total == -3) return total/3;
	//check right diagonal
	total = 0;
	total+=board[0];
	total+=board[4];
	total+=board[8];
	//check tie
	if(total == 3 | total == -3) return total/3;
	int move = -1;
	for(int i = 0; i < 9; ++i) 
		if(board[i] == 0) move = 1;
	if(move == -1) return 0;
	
	return -2;
}

void duplicateBoard(int* board, int* board2) //memcopy the arrays
{
	for(int i = 0; i < 9; i++) board2[i] = board[i];
}

int minimax(int* board,int player)//algorithm used to check
{
	//Player 1 = human = -1
	//PLayer 2 = bot = 1
	if(checkWin(board) == 0) 
		return 0;
	if(checkWin(board) == 1)
		return 1;
	if(checkWin(board) == -1) 
		return -1;
	
	int scoreForMove;
	if(player == 1)
	{
		scoreForMove = INT_MIN;
		for(int i = 0; i < 9; ++i)
		{
			int* board2 = new int[9]; //create new board to test on it
			duplicateBoard(board, board2);
			if(board2[i] == 0)
			{
				board2[i] = 1;
				scoreForMove = max(scoreForMove,minimax(board2,(player*-1)));
			}
			delete[] board2;
		}
	}
	if(player == -1)
	{
		scoreForMove = INT_MAX;
		for(int i = 0; i < 9; ++i)
		{
			int* board2 = new int[9]; //create new board to test on it
			duplicateBoard(board, board2);
			if(board2[i] == 0)
			{
				board2[i] = -1;
				scoreForMove = min(scoreForMove,minimax(board2,(player*-1)));
			}
			delete[] board2; //delete board
		}
	}

	return scoreForMove;
}

int chooseBestMove(int* board)
{
	int bestMoveScore = INT_MIN;
	int bestMove = -1;
	for(int i = 0; i < 9;i++)
	{
		int* board2 = new int[9]; //create new board to test on it
		duplicateBoard(board, board2);
		if(board2[i] == 0) 
		{
			board2[i] = 1;
			int newScore = minimax(board2,-1);
			if(newScore > bestMoveScore)
			{
				bestMoveScore = newScore;
				bestMove = i;
				cout << bestMove << endl;
			}
		}
		delete[] board2;
	}
	cout << "this is the best move " << bestMove << endl;
	return bestMove;
}

int main()
{
	for(int i = 0; i < 9; i++) board[i]=0;
	while(1)
	{
		int i;
		drawBoard(board);
		cout << "It's your turn" << endl;
		cin >> i;
		cout << endl;
		board[i] = -1;
		if(checkWin(board) == 1 || checkWin(board) == -1 || checkWin(board) == 0)
			break;
		cout << "It's bots turn" << endl;
		int x = chooseBestMove(board);
		board[x] = 1;
		drawBoard(board);
		if(checkWin(board) == 1 || checkWin(board) == -1 || checkWin(board) == 0)
			break;
	}
	if(checkWin(board) == -1)
	{
		cout << "Human victory";
	}
	else if(checkWin(board) == 1)
	{
		cout << "Robot victory";
	}
	else
	{
		cout << "tie";
	}
	return 0;
}