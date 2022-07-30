/*Zad 0.2
Stwórz wektor 100 kolejnych liczb ca³kowitych z zakresu od 1 do 100
a) Wypisz wszystkie liczby (for_each + unary function)
b) Wypisz wszystkie liczby mniejsze od 0 (for_each + funktor)
c) Nastepnie policz ile jest liczb wiekszych niz 4 (count_if + predykat)
d) Zrob to samo dla a, b i c, ale wykorzystaj lambdê
e) W zaleznosci od zmiennej lokalnej dzielnik wypisz wszystkie liczby podzielne przez
niego (for_each + lambda
f) Zlicz sume wszystkich liczb parzystych i zapisz ja do zmiennej lokalnej int sum;*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


void print(const int num)
{
    std::cout << num << "+";
}

class PrintLessThan //funktor-przyklad, ktory parametryzujemy
{
private:
    int _range;
public:
    PrintLessThan(int range) : _range(range) {} //c-tor parametrowy + lista
    void operator()(int value)
    {
        if (value < _range)
        {
            std::cout << value << std::endl;
        }
    }
};

bool ifBiggerThan4(const int i)
{
    return i > 4;
}

int main()
{
    //CREATING VECTOR

    //std::vector<int> integers; 
    //integers.reserve(100);
    //for (int i = 1; i <= 100; ++i)
    //{
    //    integers.push_back(i);
    //}

    std::vector<int> integers(100); // c-tor 4 z cppreference; tworzy 100-elementowy wektor skladajacy sie z samych 0; DZIALA W PARZE Z IOTA! 
    //bez linijki nizej - wektor sklada sie i wyswitla 100 elementow 0wych;
    std::iota(integers.begin(), integers.end(), 1); //wypelnia wektor wartosciami 1-100; MUSI ITEROWAC PO WYPELNIONYM WEKTROZE!

//a) Wypisz wszystkie liczby(for_each + unary function)

    std::for_each(integers.begin(), integers.end(), print);
    std::cout << std::endl;

    //reverse print // wykorzystanie lambdy jako funckja wypisania 
    std::for_each(integers.rbegin(), integers.rend(), [](const int i) {std::cout << i << "-"; });
    std::cout << std::endl;

    //wykorzystanie for loop do wyswietlenia w consoli
    //for (int i = 0; i < integers.size(); ++i)
    //{
    //    std::cout << integers.at(i) << " ";
    //}

//b) Wypisz wszystkie liczby mniejsze od 50 (for_each + funktor)

    std::for_each(integers.begin(), integers.end(), [](const int i) {if (i < 50) { std::cout << i << " "; }; }); //for_each + lambda
    std::cout << std::endl;
    std::for_each(integers.begin(), integers.end(), PrintLessThan(50)); //for_each + funktor
    std::cout << std::endl;

    //c) Nastêpnie policz ile jest liczb wiêkszych ni¿ 4 (count_if + predykat)

    int biggerThan4 = std::count_if(integers.begin(), integers.end(), ifBiggerThan4); //przypisanie do zmiennej, zeby bylo latwiej zrobic print na consoli
    std::cout << "Amount of the numbers bigger than 4 = " << biggerThan4 << std::endl;

    int biggerThan4Lambda = std::count_if(integers.begin(), integers.end(), [](const int i) {return i > 4; });
    std::cout << "Amount of the numbers bigger than 4 = " << biggerThan4Lambda << std::endl;

    //e) W zale¿noœci od zmiennej lokalnej dzielnik wypisz wszystkie liczby podzielne przez niego(for_each + lambda(uzyc capture_list))
    int divisor = 5;
    auto divByDivisor = [divisor](int i)
    {
        if (i % divisor == 0)
        {
            std::cout << i << " *5* ";
        }
    };
    // lambda moze prztjmowac wiecej niz 1 parameter, ALE for_each() dziala tylko na unary, wiec przejmujemy dzielnik powyzej w capture list

    std::for_each(integers.begin(), integers.end(), divByDivisor);
    std::cout << std::endl;

    //f) Zlicz sumê wszystkich liczb parzystych i zapisz j¹ do zmiennej lokalnej int sum;

    int sum = 0;
    std::for_each(integers.begin(), integers.end(), [&sum](int i)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
        });
    std::cout << " Sum of all even numbers in our vector = " << sum << std::endl;

}