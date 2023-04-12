#include "Span.hpp"
#include <vector>

int main()
{
    std::cout << "******** Tests 1********" << std::endl;
    {
        Span span(5);
    
        span.addNumber(5);
        try
        {
            span.longestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            span.longestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(4);
        span.addNumber(3);

        try
        {
            span.addNumber(19);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
    }
    std::cout << "******** Tests 2********" << std::endl;
    {
        Span span(4);
        
        span.addNumber(INT_MAX);
        span.addNumber(INT_MIN);
        span.addNumber(1);
        span.addNumber(2);

        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
    }
    std::cout << "******** Tests 3********" << std::endl;
    {
        std::srand(time(NULL));
        Span span(10000);

        for (int i = 0; i < 10000; i++)
            span.addNumber(std::rand());
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
    }
    std::cout << "******** Tests 4********" << std::endl;
    {
        Span span(10);
        int myint[] = {1, 4, 6, 7};
        std::deque<int> deq(myint, myint + sizeof(myint) / sizeof(int));
        span.addNumberRange(deq);
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
    }
    std::cout << "******** Tests 5********" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return (0);
}