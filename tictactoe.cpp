#include <iostream>

using namespace std;
int board[3][3];
//Score
//human = 1
//blank = 0
//computer = -1
void drawBoard()
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

void minimax(int Player) //algorithm used to check
{
	int i;
	if(Player == 0) i = 0;
	if(Player == 1) i = 1;


}

bool checkWin()
{
	int total = 0;
	for(int j = 0; j < 3; j++) //check rows
	{
		for(int i = 0; i < 3; i++)
			total += board[i][j]; 
		if(total == 3 | total == -3)
			return true;
		total = 0;
	}
	for(int i = 0; i < 3; i++) //check columns
	{
		for(int j = 0; j < 3; j++)
			total += board[i][j]; 
		if(total == 3 | total == -3)
			return true;
		total = 0;
	}

	for(int i = 0; i < 3;i++ ) //check diagonals
		total += board[i][i];
	if(total == 3 | total == -3)
		return true;
	total = 0;
	total+=board[2][0];
	total+=board[1][1];
	total+=board[0][1];

	return false;
}

int main()
{
	bool win = false;
	while(!win)
	{
		int i;
		int j;
		drawBoard();
		cout << "It's your turn" << endl;
		cin >> i;
		cin >> j;
		board[i][j] = 1;
		drawBoard();
		cout << "It's bots turn" << endl;
		cin >> i;
		cin >> j;
		board[i][j] = -1;
		drawBoard();
	}
	return 0;
}


