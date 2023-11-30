#include <iostream>

void sort(int array[], int size);

int main(){

    int array[] = {2,6,10,4,8,1,3,5,7,9};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array,size);
    for(int ele : array){
        std::cout << ele << " " ;
    }

    return 0;
}

void sort(int array[], int size){
    int temp;
    for(int i = 0; i < size-1 ; i++ ){
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] < array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

            }
        }
    }
}