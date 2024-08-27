#include "Game.h"
#include <iostream>

Game::Game() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      this->board[i][j] = static_cast<char>(48 + (i * 3 + j + 1));
    }
  }
  this->sign = 'X';
}

char Game::getSign() { return this->sign; }

void Game::changeSign() { this->sign = (this->sign == 'X') ? 'o' : 'X'; }

void Game::drawBoard() {
  std::cout << "\x1B[2J\x1B[H";
  for (int i = 0; i < 3; i++) {
    std::cout << "-------------" << std::endl;
    std::cout << "|";
    std::cout << " " << this->board[i][0] << " | " << this->board[i][1] << " | "
              << this->board[i][2] << " ";
    std::cout << "|";
    std::cout << std::endl;
  }
  std::cout << "-------------" << std::endl;
}

void Game::playTurn(int pos) {
  int row = (pos - 1) / 3;
  int col = (pos - 1) % 3;
  if (this->board[row][col] == 'X' || this->board[row][col] == 'o') {
    std::cout << "Invalid move!" << std::endl;
    return;
  }
  this->board[row][col] = this->sign;
}

bool Game::checkWin() {
  char currSign;

  if (this->board[0][0] == this->board[1][1] &&
      this->board[0][0] == this->board[2][2]) {
    return true;
  }

  if (this->board[0][2] == this->board[1][1] &&
      this->board[0][2] == this->board[2][0]) {
    return true;
  }

  for (int i = 0; i < 3; i++) {
    currSign = this->board[i][0];
    for (int j = 1; j < 3; j++) {
      if (currSign != this->board[i][j]) {
        break;
      }
      if (j == 2) {
        return true;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    currSign = this->board[0][i];
    for (int j = 1; j < 3; j++) {
      if (currSign != this->board[j][i]) {
        continue;
      }
      if (j == 2) {
        return true;
      }
    }
  }

  return false;
}

bool Game::checkDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (this->board[i][j] != 'o' || this->board[i][j] != 'x') {
        return true;
      }
    }
  }

  return false;
}
