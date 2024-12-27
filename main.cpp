#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <pthread.h>
#include <random>
#include <vector>

#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;

// Макросы
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

#define START_TIMER auto start = chrono::high_resolution_clock::now()
#define END_TIMER                                                              \
  cerr << "Время: "                                                            \
       << chrono::duration_cast<chrono::milliseconds>(                         \
              chrono::high_resolution_clock::now() - start)                    \
              .count()                                                         \
       << "ms" << endl;

// Генерация случайных чисел
int getRandomNumber(int low, int high) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(low, high);
  return dis(gen);
}

// Генерация случайного массива
vector<int> generateRandomArray(int size, int low, int high) {
  vector<int> arr(size);
  for (int &num : arr) {
    num = getRandomNumber(low, high);
  }
  return arr;
}

// Пример алгоритма
int myAlgorithm(const vector<int> &arr) {
  int sum = 0;
  for (int x : arr)
    sum += x;
  return sum;
}

// Эталонное решение
int naiveAlgorithm(const vector<int> &arr) {
  return accumulate(arr.begin(), arr.end(), 0);
}

// Сравнение решений
void testAlgorithm() {
  for (int i = 0; i < 100; i++) { // 100 тестов
    vector<int> input = generateRandomArray(10, 1, 1000);

    int myResult = myAlgorithm(input);
    int naiveResult = naiveAlgorithm(input);

    if (myResult != naiveResult) {
      cerr << "Ошибка на тесте!" << endl;
      printVector(input);
      cerr << "Ваш результат: " << myResult << endl;
      cerr << "Эталонный результат: " << naiveResult << endl;
      exit(1);
    }
  }
  cerr << "Все тесты пройдены!" << endl;
}

int main() {
  START_TIMER;

  testAlgorithm(); // Проверяем алгоритм

  END_TIMER;
  return 0;
}
