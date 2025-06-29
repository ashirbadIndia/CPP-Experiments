#include <bits/stdc++.h>

class UniqueObject
{
    private:
        int16_t id_;
        std::string message_;
    public:
        UniqueObject(int16_t id, std::string message):
            id_(id), message_(message)
        {
            std::cout << "creating object with id: " << id_ << std::endl;
        }
        void printMessage()
        {
            std::cout << "id: " << id_ << " message: "<< message_ << std::endl;
        }
        ~UniqueObject()
        {
            std::cout << "deleting object with id: " << id_ << std::endl;;
        }
};

void operationOne()
{
    std::unique_ptr<UniqueObject> up(new UniqueObject(3, "hello received!"));
    up->printMessage();
}

std::unique_ptr<UniqueObject> operationTwo(int16_t id, std::string message)
{
    std::unique_ptr<UniqueObject> up(new UniqueObject(id, message));
    up->printMessage();
    return up;
}

int main()
{
    std::unique_ptr<UniqueObject> up1(new UniqueObject(1, "hello One!"));

    std::unique_ptr<UniqueObject> up2 = operationTwo(2, "hello Two!");

    operationOne();
    
    up1->printMessage();

    up2->printMessage();

    return 0;
}