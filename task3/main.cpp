#include <iostream>

bool StrEqual(const char* s1, const char* s2) {
  int i = 0;
  while (s1[i] != '\0' and s2[i] != '\0') {
    if (s1[i] != s2[i]) {
      return false;
    }
    ++i;
  }
  return s1[i] == s2[i];
}

int StrLen(const char* s) {
  int len = 0;
  while (s[len] != '\0') {
    ++len;
  }
  return len;
}

bool Valid(int x, int y) {
  return x >= 0 and x < 10 and y >= 0 and y < 5;
}

bool Clear(char board[5][10]) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      board[i][j] = ' ';
    }
  }
  return true;
}

bool PutCmd(char board[5][10]) {
  int x, y;
  char c;
  std::cin >> x >> y >> c;

  if (Valid(x, y)) {
    return false;
  }
  
  board[y][x] = c;
  return true;
}

bool TextCmd(char board[5][10]) {
  int x, y;
  char word[20];
  std::cin >> x >> y >> word;
  
  int len = StrLen(word);

  if (Valid(x, y) or Valid(x + len - 1, y)) {
    return false;
  }

  for (int i = 0; i < len; ++i) {
    board[y][x + i] = word[i];
  }
  return true;
}

bool Print(char board[5][10]) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << board[i][j];
    }
    std::cout << "\n";
  }
  return true;
}

struct Command {
  const char* name;
  bool (*func)(char board[5][10]);
};

Command Cmds[] = {
  {"clear", Clear},
  {"put", PutCmd},
  {"text", TextCmd},
  {"print", Print}
};

int main() {
  char board[5][10];
  Clear(board);
  
  char cmd[30];

  while (std::cin >> cmd and !StrEqual(cmd, "quit")) {
    bool found = false;

    for (int i = 0; i < 4; ++i) {
      if (StrEqual(cmd, Cmds[i].name)) {
        bool success = Cmds[i].func(board);

        if (!success) {
          std::cout << "error\n";
        }
        
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << "error\n";
    }
  }

  return 0;
}