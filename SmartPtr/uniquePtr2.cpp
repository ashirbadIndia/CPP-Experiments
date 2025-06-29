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

std::unique_ptr<UniqueObject> operation(int16_t id, std::string message)
{
    std::unique_ptr<UniqueObject> up(new UniqueObject(id, message));
    up->updateMessage("Namaste One!");
    up->printMessage();
    return up;
}

int main()
{
    std::unique_ptr<UniqueObject> up1 = operation(1, "Hello One!");
    
    up1->printMessage();

    return 0;
}