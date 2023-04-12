#include <iostream>
#include "data.h"


uintptr_t serialize(Data* ptr)
{
    uintptr_t temp = reinterpret_cast<uintptr_t>(ptr);
    return (temp);
}

Data* deserialize(uintptr_t raw)
{
    Data *dataPtr = reinterpret_cast<Data *>(raw);
    return (dataPtr);
}

int main()
{
    {
        Data data;
        uintptr_t ptrLong = serialize(&data);
        Data *rollBackPtr = deserialize(ptrLong);

        std::cout << &data << std::endl;
        std::cout << ptrLong << std::endl;
        std::cout << rollBackPtr << std::endl;
    }
    // std::cout << "***************************" << std::endl;
    // {
    //     Data data;
    //     uintptr_t ptrInt = static_cast<uintptr_t>(&data);
    //     Data *rollBackPtr = static_cast<Data *>(ptrInt);


    //     std::cout << &data << std::endl;
    //     std::cout << ptrInt << std::endl;
    //     std::cout << rollBackPtr << std::endl;
    // }
}