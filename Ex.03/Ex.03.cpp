/*Zad 0.3
Utworz wektor liczb calkowitych od -100 do 100.
a) Nastepnie sprawdz czy wszystkie liczby sa dodatnie.
b) Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30.
c) Usun z kontenera 0.
d) Nastepnie sprawdz czy kontener nie zawiera wartosci 0.
e) Sprawdz czy kontener jest posortowany
f) Skopiuj do drugiego wektora wszystkie liczby wieksze od 90 i mniejsze od -90
g) Skopiuj do innego wektora 10 kolejnych liczb zaczynajac od 78*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
// Utworz wektor liczb calkowitych od -100 do 100.
    
    std::vector<int> numbers(200);
    std::iota(numbers.begin(), numbers.end(), -100);
    
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << " " << std::endl;
    }
   
    // a) Nastepnie sprawdz czy wszystkie liczby sa dodatnie.
    
    auto ifPositive = [](int value) -> bool 
    {
        if (value >= 0)
        {
            return true;
        }
        else {
            return false;
        }
    };

    if (std::all_of(numbers.begin(), numbers.end(), ifPositive))
    {
        std::cout << "All numbers are positive." << std::endl;
    }
    else
    {
        std::cout << "Not all numbers are positive." << std::endl;
    }
    
    //b)Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30.
    
    auto divisible = [](int value)
    {
        if (value % 3 && value % 5 && value % 30)
        {
            return true;
        }
        else {
            return false;
        }
    };

    if (std::any_of(numbers.begin(), numbers.end(), divisible))
    {
        std::cout << "Vector has numbers divisible by: 3 & 5 & 30." << std::endl;
    }
    else
    {
        std::cout << "Vector has not numbers divisible by 3 & 5 & 30." << std::endl;
    }

   //c) Usun z kontenera 0.
    
    auto isZero = [](int value)
    {
        if (value == 0)
        {
            return true;
        }
        else {
            return false;
        }
    }
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), isZero), numbers.end());

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << " " << std::endl;
    }

    //d) Nastepnie sprawdz czy kontener nie zawiera wartosci 0.
    
    auto isZero = find(v.cbegin(), v.cend(), 0);
    if (v.cend() == isZero)
    {
        std::cout << "In this vector is zero" << std::endl;
    }
    else
    {
        std::cout << "In this vector is not zero" << std::endl;
    }

  //e) Sprawdz czy kontener jest posortowany.

    auto ifSorted = [](int i)
    {
        if (i < i++)
        {
            return true;
        }
        else {
            return false;
        }
    };

    std::for_each(numbers.begin(), numbers.end(), [](int i)
        {
            if (i < ++i)
            {
                std::cout << "Sorted container." << std::endl;
            }
            else
            {
                std::cout << "Not sorted cointainer." << std::endl;
            }
        });

    //f)Skopiuj do drugiego wektora wszystkie liczby wieksze od 90 i mniejsze od -90.
    
    std::vector<int> newVector;
    auto ifInRange = [](int value)
    {
        return ((value < -90) || (value > 90)); 
    };

    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(newVector), ifInRange); 

    for (auto it = newVector.begin(); it != newVector.end(); ++it) 
    {
        std::cout << *it << std::endl;
    }

    //g)Skopiuj do innego wektora 10 kolejnych liczb zaczynaj¹c od 78
    
    std::vector<int> newVector2;

    auto it = std::find(v.cbegin(), v.cend(), 78);

    std::copy(it, (it + 10), std::back_inserter(newVector2));

    for (auto it = newVector2.begin(); it != newVector2.end(); ++it) 
    {
        std::cout << *it << std::endl;
    }
}
}

