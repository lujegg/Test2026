#include <iostream>
using namespace std;
//=======
void printArray(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " "<<endl;
  }
}
//=======
int main() {
  const int size = 10;
  int arr[size];
  cout<< "Enter" << size << " integers: " <<endl;
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  printArray(arr, size);
  return 0;
}