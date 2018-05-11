#include<bits/stdc++.h>
using namespace std;

struct Move
{
	int x,y;
};

char player ='o', opp='x';

char board[3][3];

bool ismoveleft(char board[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]=='_')
			{
				return true;
			}
		}
	}
	return false;
}


int evaluate(char b[][3])
{
	for(int row=0;row<3;row++)
	{
		if(b[row][0] == b[row][1] && b[row][1]==b[row][2])
		{
			if(b[row][0] == player)
			{
				return 10;
			}
			else if(b[row][0] == opp)
			{
				return -10;
			}
		}
	}

	for(int col=0;col<3;col++)
	{
		if(b[0][col]==b[1][col] && b[1][col]==b[2][col])
		{
			if(b[0][col] == player)
			{
				return	10;
			}
			else if(b[0][col] == opp)
			{
				return -10;
			}

		}
	}

	if(b[0][0] == b[1][1] && b[1][1]==b[2][2])
	{
		if(b[0][0]==player)
		{
			return 10;
		}
		else if(b[0][0]==opp)
		{
			return -10;
		}
	}

	if(b[0][2] == b[1][1] && b[1][1]==b[2][0])
	{
		if(b[0][2] == player)
		{
			return 10;
		}
		else if(b[0][2] == opp)
		{
			return -10;
		}
	}

	return 0;
}

int minimax(char board[][3], int depth, bool isMax)
{
	int score = evaluate(board);

	if(score == 10)
	{
		return score;
	}

	if(score == -10)
	{
		return score;
	}

	if(ismoveleft(board) == false)
	{
		return 0;
	}

	if(isMax)
	{
		int best = -1000;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j] == '_')
				{
					board[i][j] = player;

					best = max(best, minimax(board, depth+1, !isMax));

					board[i][j] = '_';
				}
			}
		}

		return best;
	}

	else
	{
		int best = 1000;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j] == '_')
				{
					board[i][j] = opp;

					best = min(best, minimax(board, depth+1, !isMax));

					board[i][j]='_';
				}
			}
		}

		return best;
	}
}

Move findbestmove(char board[][3])
{
	int bestval = -1000;
	Move bestmove;
	bestmove.x = -1;
	bestmove.y = -1;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			//printf("for i=%d, j=%d\n",i,j);
			if(board[i][j] == '_')
			{
				board[i][j] = player;

				int moveval = minimax(board, 0, false);

				//printf("moveval: %d for i=%d, j=%d\n",moveval,i,j);

				board[i][j] = '_';

				if(moveval > bestval)
				{
					bestmove.x = i;
					bestmove.y = j;
					bestval = moveval;
				}
			}
		}
	}

	printf("the value of the best move is : %d\n",bestval);

	return bestmove;
}

int main()
{
	// char board[3][3] = 
	// {
	// 	{'x','o','x'},
	// 	{'o','o','x'},
	// 	{'_','_','_'}
	// };

	char board[3][3] = 
	{
		{'_','_','_'},
		{'_','_','_'},
		{'_','_','_'}
	};

	int flag=0;

	while(evaluate(board) != 10 || evaluate(board)!=-10)
	{
		if(flag == 1)
		{
			printf("Computer's move:\n");
			Move bestmove = findbestmove(board);
			board[bestmove.x][bestmove.y] = player;
			flag=0;
			printf("the optimal move is:\n");
			printf("row: %d col:%d\n",bestmove.x,bestmove.y);
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf("%c",board[i][j]);
				}
				printf("\n");
			}

			if(evaluate(board) == 10 || evaluate(board) == -10)
			{

				printf("Computer wins!!!!... you loose sucker ..!..\n");
				break;
			}
			if(!ismoveleft(board))
			{
				cout<<"Draw!!"<<endl;
				break;
			}
		}
		else if(flag == 0)
		{
			printf("Player's Move:\n");
			string s;
			for(int i=0;i<3;i++)
			{
				// for(int j=0;j<3;j++)
				// {
				// 	scanf("%c",&board[i][j]);
				// }
				//printf("\n");
				// scanf("%[^\n]s",s);
				cin>>s;
				for(int j=0;j<3;j++)
				{
					board[i][j]=s[j];
				}
			}

			if(evaluate(board) == 10 || evaluate(board) == -10)
			{
				printf("Player wins choco!!\n");
				break;
			}
			if(!ismoveleft(board))
			{
				cout<<"Draw!!"<<endl;
				break;
			}

			flag=1;

		}
	}

	return 0;
}