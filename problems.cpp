#include<iostream>

int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long j;
        std::cin >> j;
        if (j%2 == 1 and j > 1){
            std::cout << "YES\n";
        }
        else if (j%2 == 0){
            while(j % 2 != 1){
                j /= 2;
            }
            if (j == 1){
                std::cout << "NO\n";
            }
            else{
                std::cout << "YES\n" ;
            }
        }
        else{
            std::cout << "NO\n";
        }
    }
}