// Understanding how destructors gets called

#include <bits/stdc++.h>

class SomeObject
{
    private:
        int16_t id_;
        std::string message_;
        static uint16_t g;
    public:
        SomeObject(std::string message): message_(message)
        {
            id_ = ++SomeObject::g;

            std::cout << "SomeObject:: creating object with id: " << id_ << " message: "<< message_ << std::endl;
        }
        void printAddr()
        {
            std::cout << "SomeObject:: address of object with id: " << id_ << " is "<< this << std::endl;
        }
        ~SomeObject()
        {
            std::cout << "SomeObject:: deleting object with id: " << id_ << std::endl;;
        }
};

class OtherObject
{
    private:
        int16_t id_;
        std::string message_;
        static uint16_t g;
    public:
        OtherObject(std::string message): message_(message)
        {
            id_ = ++OtherObject::g;

            std::cout << "OtherObject:: creating object with id: " << id_ << " message: "<< message_ << std::endl;
        }

        OtherObject(OtherObject& o)
        {
            id_ = ++OtherObject::g;

            message_ = o.message_;

            std::cout << "OtherObject:: creating object (copy contstructor) with id: " << id_ << " message: "<< message_ << std::endl;
        }

        OtherObject(OtherObject&& o)
        {
            id_ = std::move(o.id_);

            message_ = std::move(o.message_);

            std::cout << "OtherObject:: creating object (move contstructor) with id: " << id_ << " message: "<< message_ << std::endl;
        }

        void printAddr()
        {
            std::cout << "OtherObject:: address of object with id: " << id_ << " is "<< this << std::endl;
        }
        ~OtherObject()
        {
            std::cout << "OtherObject:: deleting object with id: " << id_ << std::endl;;
        }
};

uint16_t SomeObject::g = 0;
uint16_t OtherObject::g = 0;

int main()
{

    SomeObject p1("Hello One!");

    SomeObject p2 = p1;

    SomeObject p3 = std::move(p1);

    p1.printAddr();
    p2.printAddr();
    p3.printAddr();

    std::string s1 = "Hello Two!";
    std::string s2 = s1;
    std::cout<< "s1: "<< s1 << std::endl;
    std::cout<< "s2: "<< s2 << std::endl;
    std::string s3 = move(s1);
    std::cout<< "after move" << std::endl;
    std::cout<< "s1: "<< s1 << std::endl;
    std::cout<< "s2: "<< s2 << std::endl;
    std::cout<< "s3: "<< s3 << std::endl;

    OtherObject o1("Hello One!");

    OtherObject o2 = o1;

    OtherObject o3 = std::move(o1);

    o1.printAddr();
    o2.printAddr();
    o3.printAddr();

    return 0;
}