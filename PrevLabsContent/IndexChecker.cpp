#include <stdexcept>

void CheckIndex(int size, int index){
    if (size == 0){
        throw std::out_of_range("Error: Array is empty.");
    }
    if (index < 0 || index >= size){
        throw std::out_of_range("Error: Index is out of range.");
    }
}