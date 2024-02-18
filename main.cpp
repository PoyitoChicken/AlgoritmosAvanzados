#include <iostream>
#include <vector>
using namespace std;

// Sort de mayor a menor, solo se ingresa N y N cantidad de doubles

class MergeSort{
    private:
        int size;
        vector<double> *nums;

        void merge(vector<double> &nums, vector<double> &left, vector<double> &right){
            int i = 0, j = 0, k = 0;
            int size_left = left.size();
            int size_right = right.size();
            while(i < size_left && j < size_right){
                if(left[i] >= right[j]){ // si es mayor se agrega al vector ordenado
                    nums[k] = left[i];
                    i++; // se incrementa para revisar siguiente valor
                }else{
                    nums[k] = right[j]; 
                    j++;
                }
                k++; // se incrementa k para insertar siguiente valor en el indice siguiente
            }
            
            while(i < size_left){ // si ya no quedan elementos en la mitad derecha
                nums[k] = left[i]; // se van agregando del vector izq porque ya estan ordenados
                i++;
                k++;
            }
            while(j < size_right){ // si ya no quedan elementos en la mitad izquierda
                nums[k] = right[j];
                j++;
                k++;
            }
        }

        void merge_sort(vector<double> &nums) {
            int size = nums.size();
            if (size > 1) { // si el vector tiene mas de un elemento
                int mid = size /2; // se calcula la nueva mitad
                vector<double> left(mid);
                vector<double> right(size - mid);
                for (int i = 0; i < mid; i++) { // se copian los valores al vector izq
                    left[i] = nums[i];
                }
                for (int i = mid; i < size; i++) { // se copian los valores al vector derecho
                    right[i - mid] = nums[i];
                }
                merge_sort(left); // se llama la funcion para ambas mitades
                merge_sort(right);
                merge(nums, left, right); // se unen despues del ordenamiento
            }
        }

        void print_nums(vector<double> &nums){ 
            for(int i = 0; i < nums.size(); i++){
                cout << nums[i] << " "; // para desplegar todos los elementos del vector
            }
            cout << endl;
        }

    public:
        void MergeSortAlgorithm(int size, vector<double> &nums){
            for (int i = 0; i < size; i++) {
                cout  << "Enter a number: "; // se piden los numeros
                double num;
                cin >> num;
                nums.push_back(num); // se agregan al vector
            }
            cout << "Terminado" << endl;
            merge_sort(nums); // se llama la funcion merge sort
            print_nums(nums);
        }
};


int main(){
    vector<double> nums;
    MergeSort m;
    cout << "Ingresa el tamanio de tu arreglo: ";
    int size;
    cin >> size;
    m.MergeSortAlgorithm(size,nums);
    return 0;
}
