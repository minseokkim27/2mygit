#include "address_factor.h"

Address::Address(const std::string& name, const std::string& sex, const std::string& number, const std::string& address)
                :name(name), sex(sex), number(number), address(address) {}

Address::Address() : name(""), sex(""), number(""), address("") {}

std::string Address::getName() const {return name;}
void Address::setName(const std::string& newName) {name=newName;}

std::string Address::getSex() const {return sex;}
void Address::setSex(const std::string& newSex) {sex=newSex;}

std::string Address::getNumber() const {return number;}
void Address::setNumber(const std::string& newNumber) {number=newNumber;}

std::string Address::getAddress() const {return address;}
void Address::setAddress(const std::string& newAddress) {address=newAddress;}