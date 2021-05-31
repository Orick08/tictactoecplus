#include <iostream>

using namespace std;
class GameBoard
{
private:
  string player1;
  string player2;

  int pointsPlayer1;
  int pointsPlayer2;

  char gameField[3][3];

  void win(char player);

public:
  GameBoard();
  void setField(int row, int column, char value);
  void printBoard();
  void resetField();
  bool checkGameOver();

  string getPlayer1();
  string getPlayer2();
};

GameBoard::GameBoard()
{
  cout << "Name player 1: ";
  cin >> player1;

  cout << "Name player 2: ";
  cin >> player2;

  resetField();
}

void GameBoard::resetField()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      this->gameField[i][j] = '-';
    }
  }
}

bool GameBoard::checkGameOver()
{
  //Check for columns
  int count = 0;
  char comparator;
  for (int i = 0; i < 3; i++)
  {
    count = 0;
    for (int j = 0; j < 3; j++)
    {
      if (gameField[i][j] == '-')
      {
        break;
      }
      if (count == 0)
      {
        comparator = gameField[i][j];
        count++;
      }
      else if (comparator == gameField[i][j])
      {
        count++;
      }
    }
    if (count == 3)
    {
      win(comparator);
      return true;
    }
  }

  //Check rows
  for (int i = 0; i < 3; i++)
  {
    count = 0;
    for (int j = 0; j < 3; j++)
    {
      if (gameField[j][i] == '-')
      {
        break;
      }
      if (count == 0)
      {
        comparator = gameField[j][i];
        count++;
      }
      else if (comparator == gameField[j][i])
      {
        count++;
      }
    }

    if (count == 3)
    {
      win(comparator);
      return true;
    }
  }

  //Check diagonals
  if (gameField[1][1] == '-')
  {
    return false;
  }

  if (gameField[0][0] == gameField[1][1] && gameField[1][1] == gameField[2][2])
  {
    win(gameField[1][1]);
    return true;
  }

  if (gameField[2][0] == gameField[1][1] && gameField[1][1] == gameField[0][2])
  {
    win(gameField[1][1]);
    return true;
  }

  return false;
}

void GameBoard::win(char player)
{
  cout << "Win:";
  if (player == 'X')
  {
    cout << "(X) " << player1 << endl;
    pointsPlayer1++;
  }
  else
  {
    cout << "(O) " << player2 << endl;
    pointsPlayer2++;
  }
}

void GameBoard::setField(int row, int column, char value)
{
  gameField[row][column] = value;
}

void GameBoard::printBoard()
{
  cout << endl;
  cout << "  0 1 2" << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << i;
    for (size_t j = 0; j < 3; j++)
    {
      cout << "|" << gameField[i][j];
    }
    cout << "|" << endl;
  }
  cout << endl;
}

string GameBoard::getPlayer1()
{
  return player1;
}

string GameBoard::getPlayer2()
{
  return player2;
}