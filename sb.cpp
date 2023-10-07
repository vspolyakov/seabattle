// SeaBattle. Классический морской бой. Консольная игра для двух игроков.
// Vitaliy Polyakov (c), polyakov.vs@mail.ru, 2023-2024.
//
// Программа разрабатывалась с целью изучения язка программирования C++.
// Debian GNU/Linux 12 (boolworm) x86_64. Kernel 6.1.0-13-amd64.
// Vim 9.0.1499, g++ (Debian 12.2.0-14) 12.2.0.

#include <iostream>

#include <string>

int mainMenu();
std::string ltrim(std::string str);
std::string rtrim(std::string str);
std::string trim(std::string str);

int main() {
  // Очистка экрана (консоли).
  system("clear");

  std::cout << "SeaBattle. Классический морской бой." << '\n';
  std::cout << "Консольная игра для двух игроков." << '\n';
  std::cout << "Vitaliy Polyakov, polyakov.vs@mail.ru, 2023-2024." << '\n';

  int itemIndex = -1;
  bool flag = true;
  while (flag) {
    itemIndex = mainMenu();

    if (itemIndex == 1) {
      std::cout << "Начало новой игры...\n";
    } else if (itemIndex == 2) {
      std::cout << "Показать правила игры...\n";
    } else if (itemIndex == 0) {
      std::cout << "Завершение игры...\n";
      flag = false;
    }
  }
  std::cout << "Игра завершена.\n";
  return 0;
}

int mainMenu() {
  std::cout << "ГЛАВНОЕ МЕНЮ:\n";
  std::cout << "[1] - начало новой игры\n";
  std::cout << "[2] - показать правила игры\n";
  std::cout << "[0] - завершить игру\n";

  std::string tmp_str = "";
  bool valueIsCorrect = false;
  int tmp_int = -1;

  std::cout << "Выберите пункт меню [0..2] и нажмите [ENTER]: ";
  while (!valueIsCorrect) {
    getline(std::cin, tmp_str);
    tmp_str = trim(tmp_str);

    try {
      tmp_int = stoi(tmp_str);
    } catch (...) {
        // Skip.
    }

    if ((tmp_int >= 0) && (tmp_int <= 2)) {
      valueIsCorrect = true;
    } else {
      std::cout << "Неверное значение. Повторите ввод:  ";
    }
  }
  return tmp_int;
}

std::string ltrim(std::string str) {
  // thispointer.com/how-to-trim-a-string-in-c/#method-1-c-standard-functions
  const std::string whiteSpaces = " \t\n\r\f\v";
  // Удалить начальные пробелы.
  size_t first_non_space = str.find_first_not_of(whiteSpaces);
  str.erase(0, first_non_space);
  return str;
}

std::string rtrim(std::string str) {
  // thispointer.com/how-to-trim-a-string-in-c/#method-1-c-standard-functions
  const std::string whiteSpaces = " \t\n\r\f\v";
  // Удалить конечные пробелы.
  size_t last_non_space = str.find_last_not_of(whiteSpaces);
  str.erase(last_non_space + 1);
  return str;
}

std::string trim(std::string str) {
  // thispointer.com/how-to-trim-a-string-in-c/#method-1-c-standard-functions
  // Удалить начальные и конечные пробелы.
  return ltrim(rtrim(str));
}
