#include <iostream>
#include "Vector2.h"

int main(int argc, char* argv[]) 
{
    std::cout << Vector2(2, 3) + Vector2(8, 7) << std::endl;
    std::cout << -Vector2(1, 1) << std::endl;

    Vector2 vec1 = Vector2(12, 16);
    Vector2 vec2 = Vector2(7, 9);
    std::cout << Vector2::Dot(vec1, vec2) << std::endl;

    vec1 = vec2;
    std::cout << vec1 << std::endl;

    //Please build your interactive calculator, using the
    //Vector2 class, here.
    bool test = true;
    std::cout << sizeof(test);

    return 0;
}