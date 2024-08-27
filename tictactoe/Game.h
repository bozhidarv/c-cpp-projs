#pragma once

class Game {
private:
  char board[3][3];
  char sign;

public:
  Game();

  char getSign();
  void changeSign();

  void drawBoard();
  void playTurn(int pos);
  bool checkWin();
  bool checkDraw();
};
