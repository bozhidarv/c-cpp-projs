#include "Game.h"
#include <iostream>

int main(const int argc, const char *argv[]) {
  Game game;

  do {
    game.drawBoard();
    int pos;
    std::cout << game.getSign() << " enter position: ";
    std::cin >> pos;
    game.playTurn(pos);

    if (game.checkWin()) {
      game.drawBoard();
      std::cout << game.getSign() << " has won!" << std::endl;
      break;
    }

    if (game.checkWin()) {
      game.drawBoard();
      std::cout << "Draw!" << std::endl;
      break;
    }

    game.changeSign();

  } while (true);

  return 0;
}
