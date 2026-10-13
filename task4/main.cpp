/*
  Задача: распределение сырого пакета данных в структуру
  здания.

  int*** создает трехмерный массив (на каждом этаже 
  комната, в каждой комнате датчик). Можем обращаться
  к данным удобнее: building[floor][room][sensor].
  Без него пришлось бы хранить данные в одномерном 
  массиве, что усложнило бы написание и чтение кода
  
  void* нужен для получения данных из сети неизвестно
  какого типа. Без него мы бы смогли принимать только
  один тип данных
  
  Программа берет данные (void*), интерпретирует как
  целые числа и распределяет по трехмерному массиву 
  (int***) и выводит структуру здания
  */

#include <iostream>

int main() {
  const int floors = 2;
  const int rooms = 2;
  const int sensors = 3;

  int data[] = {5, 4, 7, 13, 5, 6, 3, 3, 9, 2, 14, 8};
  
  void* buffer = data;

  int*** building = new int**[floors];
  for (int i = 0; i < floors; ++i) {
    building[i] = new int*[rooms];
    for (int j = 0; j < rooms; ++j) {
      building[i][j] = new int[sensors];
    }
  }

  int* data_ptr = static_cast<int*>(buffer);
  
  int offset = 0;
  for (int i = 0; i < floors; ++i) {
    for (int j = 0; j < rooms; ++j) {
      for (int k = 0; k < sensors; ++k) {
        building[i][j][k] = data_ptr[offset];
        ++offset;
      }
    }
  }

  for (int i = 0; i < floors; ++i) {
    std::cout << "Floor " << i << ":\n";
    for (int j = 0; j < rooms; ++j) {
      std::cout << "  Room " << j << " sensors: ";
      for (int k = 0; k < sensors; ++k) {
        std::cout << building[i][j][k] << " ";
      }
      std::cout << "\n";
    }
  }

  for (int i = 0; i < floors; ++i) {
    for (int j = 0; j < rooms; ++j) {
      delete[] building[i][j];
    }
    delete[] building[i];
  }
  delete[] building;

  return 0;
}