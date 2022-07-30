/*Napisz zwykla funkcje oraz lambde (przypisz ja do zmiennej) Nastepnie je wywolaj:
a) funkcja wypisujaca “Hello World”
b) Funkcja dodajaca dwie liczby do siebie (i zwracajaca ja)*/

#include <iostream>

void hello()
{
    std::cout << "Hello World!" << std::endl;
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    hello();

    auto sayHello = []() {std::cout << "Hello World!" << std::endl; };
    sayHello();

    std::cout << sum(6,7) << std::endl;

    auto addNumbers = [](int c, int d) {return c + d; };

    std::cout << addNumbers(50, 60);
    
}

