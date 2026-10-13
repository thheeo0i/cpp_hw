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

void Dep(int& sum) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    std::cout << "error" << "\n";
  } else {
    sum += k;
  }
}

void Withdraw(int& sum) {
  int k;
  std::cin >> k;
  if (sum < k or k <= 0) {
    std::cout << "error" << "\n";
  } else {
    sum -= k;
  }
}

void Bal(int& sum) {
  std::cout << sum << "\n";
}

void Reset(int& sum) {
  sum = 0;
}

void Half(int& sum) {
  sum = sum / 2;
}

struct Command {
  const char* name;
  void (*func)(int&);
};

Command Cmds[] = {
  {"deposit", Dep},
  {"withdraw", Withdraw},
  {"balance", Bal},
  {"reset", Reset},
  {"half", Half}
};

int main() {
  int sum = 0;
  char cmd[30];

  while (std::cin >> cmd and !StrEqual(cmd, "stop")) {
    bool found = false;

    for (int i = 0; i < 5; ++i) {
      if (StrEqual(cmd, Cmds[i].name)) {
        Cmds[i].func(sum);
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << "error" << "\n";
    }
  }
}