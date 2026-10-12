/*
  Below is the example code from lecture demonstrating an abstract base class.

  Modify this code to use a std::unique_ptr<DisplayABC> that owns a
  Scientist. You may use std::make_unique<Scientist> or construct the
  unique pointer directly from new Scientist. Keep the print calls.
  Do not manually delete the object; the smart pointer owns its lifetime.
*/
#include <iostream>
#include <string>
#include <memory>

class DisplayABC
{
    public:
        // Pure virtual function
        virtual void display() const = 0;

        virtual ~DisplayABC() { } 
};

class Employee : public DisplayABC
{
    private:
        int id_;
        std::string name_;

    public:
        Employee()
            : id_(0), name_("???")
        {}

        Employee(int id, std::string name)
            : id_(id), name_(name)
        { }

        int id() const { return id_; }

        std::string name() const { return name_; }

        virtual void display() const
        {
            std::cout << "[" << id_ << "] " << name_ << std::endl;
        }

        virtual ~Employee()
        { }
};


class Scientist: public Employee
{
    private:
        std::string field_;

    public:
        Scientist(int id, std::string name, std::string field)
            : Employee(id, name), field_(field)
        { }

        std::string field() const { return field_; }

        virtual void display() const
        {
            std::cout << "[" << id() << "] "
                      << name() << " ("
                      << field() << ")" << std::endl;
        }

        virtual ~Scientist()
        {
            std::cout << "Destructing scientist: " << name() << std::endl;
        }
};


void print(const DisplayABC & d)
{
    d.display();
}


int main(void)
{
    Employee bill(1, "Bill");
  
    DisplayABC * pemily = new Scientist(2, "Emily", "chemistry"); // TODO: replace

    print(bill);
    print(*pemily);
  
    delete pemily; // TODO: remove
}
