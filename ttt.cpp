#include <iostream>
using namespace std;

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard()
{

  cout << "Tic Tac Toe" << endl;

  cout << "   |   |  " << endl;
  cout << board[1] << "  | " << board[2] << " | " << board[3] << endl;
  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;
  cout << board[4] << "  | " << board[5] << " | " << board[6] << endl;
  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;
  cout << board[7] << "  | " << board[8] << " | " << board[9] << endl;
  cout << "   |   |  " << endl;
}

bool checkWin(char player)
{
  // Check for wins
  if ((board[1] == board[2] && board[2] == board[3]) ||
      (board[4] == board[5] && board[5] == board[6]) ||
      (board[7] == board[8] && board[8] == board[9]) ||
      (board[1] == board[4] && board[4] == board[7]) ||
      (board[2] == board[5] && board[5] == board[8]) ||
      (board[3] == board[6] && board[6] == board[9]) ||
      (board[1] == board[5] && board[5] == board[9]) ||
      (board[3] == board[5] && board[5] == board[7]))
  {
    cout << "Player " << player << " wins!" << endl;
    return true;
  }

  return false;
}

bool hasEmptySpot()
{
  for (int i = 1; i <= 9; ++i)
  {
    if (board[i] != 'X' && board[i] != 'O')
    {
      return true;
    }
  }
  return false;
}
int main()
{
  displayBoard();

  char player1 = 'X';
  char player2 = 'O';
  char currentPlayer = player1;

  int choice;

  do
  {
    // Get the player's move
    cout << "Player " << currentPlayer << ", enter a number: ";
    cin >> choice;

    // Check if the chosen spot is valid
    if (choice < 1 || choice > 9 || board[choice] == 'X' || board[choice] == 'O')
    {
      cout << "Invalid move. Try again." << endl;
      continue;
    }

    board[choice] = currentPlayer;

    displayBoard();
    if (checkWin(currentPlayer))
    {
      break;
    }

    currentPlayer = (currentPlayer == player1) ? player2 : player1;

  } while (hasEmptySpot());

    return 0;
}