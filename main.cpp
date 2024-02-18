// Oscar Cortes A00825972
// Natalia Salgado A01571008
// 18 de Febrero de 2024

// Sort de mayor a menor, solo se ingresa N y N cantidad de doubles

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
private:
  int size;
  vector<double> *nums;

  // Complejidad: O(n)
  void merge(vector<double> &nums, vector<double> &left,
             vector<double> &right) {
    int i = 0, j = 0, k = 0;
    int size_left = left.size();
    int size_right = right.size();
    while (i < size_left && j < size_right) {
      if (left[i] >= right[j]) { // si es mayor se agrega al vector ordenado
        nums[k] = left[i];
        i++; // se incrementa para revisar siguiente valor
      } else {
        nums[k] = right[j];
        j++;
      }
      k++; // se incrementa k para insertar siguiente valor en el indice
           // siguiente
    }

    while (i < size_left) { // si ya no quedan elementos en la mitad derecha
      nums[k] =
          left[i]; // se van agregando del vector izq porque ya estan ordenados
      i++;
      k++;
    }
    while (j < size_right) { // si ya no quedan elementos en la mitad izquierda
      nums[k] = right[j];
      j++;
      k++;
    }
  }

  // Complejidad: O(n log n)
  void mergeSort(vector<double> &nums) {
    int size = nums.size();
    if (size > 1) {       // si el vector tiene mas de un elemento
      int mid = size / 2; // se calcula la nueva mitad
      vector<double> left(mid);
      vector<double> right(size - mid);
      for (int i = 0; i < mid; i++) { // se copian los valores al vector izq
        left[i] = nums[i];
      }
      for (int i = mid; i < size;
           i++) { // se copian los valores al vector derecho
        right[i - mid] = nums[i];
      }
      mergeSort(left); // se llama la funcion para ambas mitades
      mergeSort(right);
      merge(nums, left, right); // se unen despues del ordenamiento
    }
  }

  // Complejidad: O(n)
  void printNums(vector<double> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " "; // para desplegar todos los elementos del vector
    }
    cout << endl;
  }

public:
  // Complejidad: O(n log n)
  void MergeSortAlgorithm(int size, vector<double> &nums) {
    printNums(nums);
    cout << "Terminado" << endl;
    mergeSort(nums); // se llama la funcion merge sort
    printNums(nums);
  }
};

int main() {
  // PRUEBA 1: VECTOR VACIO
  cout << endl;
  cout << "PRUEBA 1: VECTOR VACIO" << endl;
  MergeSort m1;
  vector<double> nums1;
  int size1 = nums1.size();
  m1.MergeSortAlgorithm(size1, nums1);
  cout << endl;

  // PRUEBA 2: ORDENADO DE FORMA ASCENDENTE
  cout << "PRUEBA 2: ORDENADO DE FORMA ASCENDENTE" << endl;
  MergeSort m2;
  vector<double> nums2;
  for (int i = 0; i < 6; i++) {
    nums2.push_back(i);
  }
  int size2 = nums2.size();
  m2.MergeSortAlgorithm(size2, nums2);
  cout << endl;

  // PRUEBA 3: ORDENADO DE FORMA DESCENDENTE
  cout << "PRUEBA 3: ORDENADO DE FORMA DESCENDENTE" << endl;
  MergeSort m3;
  vector<double> nums3;
  for (int i = 7; i > 0; i--) {
    nums3.push_back(i);
  }
  int size3 = nums3.size();
  m3.MergeSortAlgorithm(size3, nums3);
  cout << endl;

  // PRUEBA 4: ALEATORIOS
  cout << "PRUEBA 4: ALEATORIOS" << endl;
  MergeSort m4;
  vector<double> nums4;
  for (int i = 0; i < 6; i++) {
    nums4.push_back(rand() % 10);
  }
  int size4 = nums4.size();
  m4.MergeSortAlgorithm(size4, nums4);
  cout << endl;

  // PRUEBA DEL USUARIO
  cout << "PRUEBA DEL USUARIO" << endl;
  MergeSort m5;
  vector<double> nums5;
  cout << "Ingresa el tamanio de tu arreglo: ";
  int size5;
  cin >> size5;
  for (int i = 0; i < size5; i++) {
    cout << "Ingresa un numero: "; // se piden los numeros
    double num;
    cin >> num;
    nums5.push_back(num); // se agregan al vector
  }
  m5.MergeSortAlgorithm(size5, nums5);
  cout << endl;

  return 0;
}
