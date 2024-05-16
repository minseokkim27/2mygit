#ifndef ADDRESS_FACTOR_H
#define ADDRESS_FACTOR_H

#include <string>

class Address
{
    private:
        std::string name;
        std::string sex;
        std::string number;
        std::string address;

    public:
        Address(const std::string& name, const std::string& sex, const std::string& number, const std::string& address);
        Address();

        std::string getName() const;
        void setName(const std::string& newName);

        std::string getSex() const;
        void setSex(const std::string& newSex);

        std::string getNumber() const;
        void setNumber(const std::string& newNumber);

        std::string getAddress() const;
        void setAddress(const std::string& newAddress);
};

#endif
