#include <iostream>
#include <vector>
//Sort de mayor a menor, solo se ingresa N y N cantidad de doubles
//g++ -o main.exe main.cpp
using namespace std;
class MergeSort{
    private:
        int size;
        vector<double> *nums;
        void merge(vector<double> &nums, vector<double> &left, vector<double> &right){
            int i = 0, j = 0, k = 0;
            int size_left = left.size();
            int size_right = right.size();
            while(i < size_left && j < size_right){
                if(left[i] >= right[j]){
                    nums[k] = left[i];
                    i++;
                }else{
                    nums[k] = right[j];
                    j++;
                }
                k++;
            }
            while(i < size_left){
                nums[k] = left[i];
                i++;
                k++;
            }
            while(j < size_right){
                nums[k] = right[j];
                j++;
                k++;
            }
        }
        void merge_sort(vector<double> &nums) {
            int size = nums.size();
            if (size > 1) {
                int mid = size /2;
                vector<double> left(mid);
                vector<double> right(size - mid);
                for (int i = 0; i < mid; i++) {
                    left[i] = nums[i];
                }
                for (int i = mid; i < size; i++) {
                    right[i - mid] = nums[i];
                }
                merge_sort(left);
                merge_sort(right);
                merge(nums, left, right);
            }
        }
        void print_nums(vector<double> &nums){
            for(int i = 0; i < nums.size(); i++){
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    public:
        void MergeSortAlgorithm(int size, vector<double> &nums){
            for (int i = 0; i < size; i++) {
                cout  << "Enter a number: ";
                double num;
                cin >> num;
                nums.push_back(num);
            }
            cout << "ended" << endl;
            merge_sort(nums);
            print_nums(nums);
        }
};


int main(){
    vector<double> nums;
    MergeSort m;
    cout << "How big do you want the array to be?" << endl;
    int size;
    cin >> size;
    m.MergeSortAlgorithm(size,nums);
    return 0;
}