#include <iostream>

struct MinMax {
  int min;
  int max;
};

double Average(const int* arr, int n) {
  if (n <= 0) {
    return 0.0;
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
  }
  double avg = static_cast<double>(sum) / n;
  if (avg < 0 && avg > -0.05) {
    avg = 0.0;
  }
  return avg;
}

MinMax FindMinMax(const int* arr, int n) {
  if (n <= 0) {
    return {0, 0};
  }

  MinMax temp = {arr[0], arr[0]};

  for (int i = 1; i < n; ++i) {
    if (arr[i] < temp.min) {
      temp.min = arr[i];
    } else if (arr[i] > temp.max) {
      temp.max = arr[i];
    }
  }

  return temp;
}

int DaysBelowZero(const int* arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      ++count;
    }
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  double average_temp = Average(arr, n);
  MinMax min_max = FindMinMax(arr, n);
  int frosty = DaysBelowZero(arr, n);

  std::cout.setf(std::ios::fixed);  
  std::cout.precision(1);           
  std::cout << average_temp << "\n";
  std::cout << min_max.min << " " << min_max.max << "\n";
  std::cout << frosty << "\n";

  delete[] arr;
  return 0;
}
