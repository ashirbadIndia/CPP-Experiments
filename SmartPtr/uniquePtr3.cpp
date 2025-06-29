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
        void updateMessage(std::string message)
        {
            message_ = message;
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

int main()
{
    std::unique_ptr<UniqueObject> up1(new UniqueObject(1, "Hello One!"));

    std::unique_ptr<UniqueObject> up2(new UniqueObject(2, "Hello Two!"));

    up1.~unique_ptr();

    std::cout<< "exiting!" << std::endl;

    return 0;
}