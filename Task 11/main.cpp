#include <iostream>
#include <cstring>

void sort_array(char** array, size_t array_size) {
    
    for(size_t i = 0 ; i < array_size; i++) {
        
        for(size_t j = i+1; j < array_size; j++) {
            
            if(strcmp(array[i], array[j]) > 0) {
                
                char *buff = array[i];
                array[i] = array[j];
                array[j] = buff;
            }
        }
    }
}

void print_array(char** array, size_t array_size, const char* str) {
    
    std::cout << str << std::endl;
    
    for(size_t i = 0 ; i < array_size; i++)
        std::cout << array[i] << std::endl;
    
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    
    size_t array_size = 0;
    
    std::cout << "Please enter count of arrays: ";
    std::cin >> array_size;
    std::cin.ignore(1, '\n');
    
    char **array = new char *[array_size];
    
    for(size_t i = 0; i < array_size; i++) {
        
        array[i] = new char[256];
        std::cin.getline(array[i], 256);
    }
    
    std::cout << std::endl;
    print_array(array, array_size, "Your array: ");
    sort_array(array, array_size);
    print_array(array, array_size, "Your sorted array: ");
    
    for(int i = 0; i < array_size; i++)
        delete []array[i];
    
    delete []array;
    
    return 0;
}
