#include <iostream>

using namespace std
class game
{
	int board[3][3] = {0};

	int main()
	{
		drawBoard();
	}

	void drawBoard()
	{
		
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout << board[i][j];
			}
	}
}

