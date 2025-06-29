#include <bits/stdc++.h>

class SharedObject
{
    private:
        int16_t id_;
        std::string message_;
    public:
        SharedObject(int16_t id, std::string message):
            id_(id), message_(message)
        {
            std::cout << "creating object with id: " << id_ << std::endl;
        }
        void printMessage()
        {
            std::cout << "id: " << id_ << " message: "<< message_ << std::endl;
        }
        ~SharedObject()
        {
            std::cout << "deleting object with id: " << id_ << std::endl;;
        }
};

void operation1()
{
    std::shared_ptr<SharedObject> sp(new SharedObject(2, "hello Two!"));
}

void operation2(std::shared_ptr<SharedObject> &sp)
{
    std::shared_ptr<SharedObject> tmp(new SharedObject(3, "hello Three!"));
    sp = tmp; // ownership transferred to sp;
    std::cout << sp.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<SharedObject> sp1(new SharedObject(1, "hello One!"));

    std::shared_ptr<SharedObject> sp2 = sp1;

    std::shared_ptr<SharedObject> sp3;

    operation1();

    operation2(sp3);


    
    sp1->printMessage();

    sp2->printMessage();

    sp3->printMessage();

    std::shared_ptr<SharedObject> spz1(new SharedObject(2, "hello Two!"));

    std::shared_ptr<SharedObject> spz2 = spz1;

    std::shared_ptr<SharedObject> spz3 = spz1;

    std::cout<< "count: " << spz3.use_count() << std::endl;

    spz1.~shared_ptr();

    std::cout<< "count: " << spz3.use_count() << std::endl;

    spz2.~shared_ptr();

    std::cout<< "count: " << spz3.use_count() << std::endl;

    spz3.~shared_ptr();

    std::cout<< "exiting!" << std::endl;

    return 0;
}