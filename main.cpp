#include <iostream>
#include "hello.h"
#include "kz_algorithm.h"

#include "kmp.h"
void test01();
void test2();

template <typename Iter, typename Func>
void processElements(Iter begin, Iter end, Func processor)
{
    for (auto it = begin; it != end; ++it)
    {
        processor(*it); // 调用传入的函数对象处理当前元素
    }
}

int main(int, char **)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // Lambda作为处理器：打印元素的平方
    processElements(nums.begin(), nums.end(),
                    [](int x)
                    { std::cout << x * x << " "; } // 输出：1 4 9 16 25
    );

    // Lambda修改元素：所有元素+10
    processElements(nums.begin(), nums.end(),
                    [](int &x)
                    { x += 10; } // 修改原始数据
    );
    std::cout << std::endl;
    processElements(nums.begin(), nums.end(),
                    [](int x)
                    { std::cout << x * x << " "; } // 输出：1 4 9 16 25
    );
}

void test2()
{
    LRUCache lru(1);
    lru.put(2, 1);
    std::cout << lru.get(2) << std::endl; // returns
    lru.put(3, 2);                        // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -
    std::cout << lru.get(3) << std::endl; // returns
}

void test01()
{
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // returns
    lru.put(3, 3);                        // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -
    lru.put(4, 4);                        // evicts key 1
    std::cout << lru.get(1) << std::endl; // returns -
    std::cout << lru.get(3) << std::endl; // returns 3
    std::cout << lru.get(4) << std::endl; //
}

class A
{
    std::vector<int> aa = std::vector<int>(10, 10);
};
