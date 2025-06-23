#include <iostream>
#include "hello.h"
#include "algorithm.h"
void test01();
void test2();
int main(int, char**){

    test2();
    
}

void test2 () {
    LRUCache lru(1);
    lru.put(2, 1);
    std::cout << lru.get(2) << std::endl; // returns
    lru.put(3, 2); // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -
    std::cout << lru.get(3) << std::endl; // returns
}

void test01(){
        LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // returns
    lru.put(3, 3); // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -
    lru.put(4, 4); // evicts key 1
    std::cout << lru.get(1) << std::endl; // returns -
    std::cout << lru.get(3) << std::endl; // returns 3
    std::cout << lru.get(4) << std::endl; //
}

class A {
    std::vector<int> aa = std::vector<int>(10, 10);
};
