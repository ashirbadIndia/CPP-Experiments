// Understanding how destructors gets called

#include <bits/stdc++.h>

class SomeObject
{
    private:
        int16_t id_;
        std::string message_;
    public:
        SomeObject(int16_t id, std::string message):
                    id_(id), message_(message)
        {
            std::cout << "creating object with id: " << id_ << " message: "<< message_ << std::endl;
        }
        ~SomeObject()
        {
            std::cout << "deleting object with id: " << id_ << std::endl;;
        }
};

SomeObject* operationTwo(int16_t id, std::string message)
{
    SomeObject *up = new SomeObject(id, message);
    return up;
}

SomeObject operationThree(int16_t id, std::string message)
{
    SomeObject Obj4(5, "hello Five!");
    SomeObject Obj(id, message);

    std::cout << "returning from operationThree() " << std::endl;

    return Obj;
}

int main()
{
    SomeObject* p1 = new SomeObject(1, "hello One!");

    SomeObject* p2 = operationTwo(2, "hello Two!");

    SomeObject p3 = operationThree(3, "hello Three!");

    SomeObject p4(4, "Hello Four!");

    std::cout << "returning from main() " << std::endl;

    return 0;
}