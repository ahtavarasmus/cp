#include <iostream>

int main(){
    for (long int i = 0; i < 1000000; ++i){
        printf("\033c");
        std::cout << i;
    }
    return 0;
}
