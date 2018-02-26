#include "mastermind.h"
#include <string>
using namespace std;

/*--------------------------------------------------------------
   CONSTRUCTOR
   PARAMETERS: int size is the width of the board; the number of columns of the board.
   POSTCONDITION: presets the game to the starting position = 0, indicated the size(cols) of the board, moves to 0(no move made yet), and pegs to red;
   --------------------------------------------------------------*/
mastermind::mastermind(int size) : MAX_MOVES(10)
{
	cols = size;
	moves = 0;
	for (int i = 0; i < 10; i++)
	{
		pegs[i] = "red";
	}
}

/*--------------------------------------------------------------
   CONSTRUCTOR
   PARAMETERS: int size is the width of the board;
   string initial[] will set the pegs to what ever string initial passes after the first move.
   the number of columns of the board.
   POSTCONDITION: columns should = size. max moves should = 10; pegs[] = initial[] and all letters should be lowercased.
   --------------------------------------------------------------*/
mastermind::mastermind(int size, string initial[]) : MAX_MOVES(10)
{
	cols = size;
  	moves = 0;
	for (int i = 0; i < cols; i++)
	pegs[i] = initial[i];
}

/*--------------------------------------------------------------
   FUNCTION NAME: move
   PARAMETERS:playerMove[] is player input for their guess of x number
   of colors. Is compared with pegs[](the correct color scheme)
   Gold is and int with the number of colors in initial that match peg[]
   silver is and int with the number of colors in initial tha match one
   of the correct colors in pegs, but is in the wrong column.
   POSTCONDITION: Player moves should be compared with pegs.
   if the user does not input the write array of colors that matches
   pegs, then it should return the int 0 as well as pass by value to
   main the number of gold and silver.
   if moves = 10 should return -1 and end game/close file
   if gold = cols should return 1 and end game/close file
   --------------------------------------------------------------*/
int mastermind::move(string playerMove[], int& gold, int& silver)
{
	gold = 0;
	silver = 0;
	for (int i = 0; i < cols; i++)
	{
		if (playerMove[i] == pegs[i])
			{
				gold++;
			}
		else
		{
			for (int n = 0; n < cols; n++)
			{
				if(playerMove[i] == pegs[n])
				{
				  	if(playerMove[i] != playerMove[n])
				  		silver++;
				}
			}
		}
 			/* else nested if statements make sure silver does not
			give 2 when the person puts
			the same color twice even though it appears once on the
			board i.e. correct answer = green yellow orange purple
			user = green green green green. silver = 1, not 4*/
	}
		if (gold == cols)
			return 1; //user wins
		else if (moves == 10)
			return -1; //user loses
		else
			return 0; //user has another turn
}

/*--------------------------------------------------------------
   FUNCTION NAME:getMoveIndex
   PARAMETERS: moves is the number of moves the player has completed
   POSTCONDITION:returns the number of moves the player has completed
   + 1 for their next move
   --------------------------------------------------------------*/
int mastermind::getMoveIndex()
{
	moves = moves + 1;
	return moves;
}


/*--------------------------------------------------------------
   FUNCTION NAME:getNumberOfColumns
   PARAMETERS:Cols is how wide the board will be, or the number of
   color pegs on the board.
   POSTCONDITION: Returns the int cols to be used inside of other
   member functions.
   --------------------------------------------------------------*/
int mastermind::getNumberOfColumns()
{
	return cols;
}
