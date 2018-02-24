#include <iostream>
#include <string>
#include <cctype>
#include "mastermind.h"
using namespace std;

int main() //all cin and cout is done in MAIN! //logic done inside of classes
{
	int determineGame, gold, silver;
	determineGame = 0;
	string winningColors[] = {"green", "orange", "purple", "yellow"};
	mastermind myGame(4, winningColors);
	string play[4];

	while(determineGame == 0)
	{
		cout << "Turn: " << myGame.getMoveIndex() << " Enter ";
		cout << myGame.getNumberOfColumns() <<  " Colors: ";

		for(int i = 0; i < 4; i++) //takes and lower cases user input
			{
				cin >> play[i];
				for(int j = 0; j < play[i].length(); j++)
					play[i][j] = tolower(play[i][j]);
			}
		/* Determine game is used to determine if the user won, lost,
		or can keep guessing
		returns -1(lose), 0(if users has not used all 10 turns)
		1 if user wins*/
		determineGame = myGame.move(play, gold, silver);

		cout << "Gold: " << gold << endl;
		cout << "Silver: " << silver << endl;
		cout << endl;

		if (determineGame == 1)
		{
			cout << "you won" << endl;
			return 0;
		}
		else if (determineGame == -1)
		{
			cout << "you lose" << endl;
			return 0;
		}

	}
}
