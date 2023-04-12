#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(time(NULL));
    int randInt = std::rand() % 3;
    if (randInt == 0)
    {
        A *newA = new A;
        return (newA);
    }
    else if (randInt == 1)
    {
        B *newB = new B;
        return (newB);
    }
    else
    {
        C *newC = new C;
        return (newC);
    }
}

void identify(Base* p)
{
    A *aPtr = NULL;
    B *bPtr = NULL;
    C *cPtr = NULL;

    aPtr = dynamic_cast<A *>(p);
    if (aPtr != NULL)
    {
        std::cout << "A" << std::endl;
    }
    bPtr = dynamic_cast<B *>(p);
    if (bPtr != NULL)
    {
        std::cout << "B" << std::endl;
    }
    cPtr = dynamic_cast<C *>(p);
    if (cPtr != NULL)
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
}