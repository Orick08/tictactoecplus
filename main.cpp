#include "gameboard.hpp"
#include <stdlib.h>

int row, column;

void borrarPantalla();

int main()
{
  GameBoard game;
  int turn = 0;

  game.printBoard();

  while (true)
  {
    cout << "Turn of " << game.getPlayer1() << endl;
    scanf("%d", &row);
    scanf("%d", &column);

    game.setField(row, column, 'X');
    borrarPantalla();
    game.printBoard();

    turn++;
    if (turn >= 9)
    {
      turn = 0;
      cout << "Game draw" << endl;
      system("PAUSE");

      game.resetField();
      borrarPantalla();
      game.printBoard();
    }

    if (game.checkGameOver())
    {
      cout << endl;
      system("PAUSE");
      borrarPantalla();
      game.resetField();
      game.printBoard();
      turn = 0;
    }

    cout << "Turn of " << game.getPlayer2() << endl;
    scanf("%d", &row);
    scanf("%d", &column);

    game.setField(row, column, 'O');
    borrarPantalla();
    game.printBoard();
    turn++;
    if (turn >= 9)
    {
      turn = 0;
      cout << "Game draw" << endl;
      system("PAUSE");

      game.resetField();
      borrarPantalla();
      game.printBoard();
    }
    if (game.checkGameOver())
    {
      cout << endl;
      system("PAUSE");
      borrarPantalla();
      game.resetField();
      game.printBoard();
      turn = 0;
    }
  }

  return 0;
}

void borrarPantalla()
{
  cout << flush;
  system("CLS");
}