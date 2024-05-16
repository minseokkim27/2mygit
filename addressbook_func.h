#ifndef ADDRESSBOOK_FUNC_H
#define ADDRESSBOOK_FUNC_H

#include "address_factor.h"

const int address_book_size = 10;

class AddressBook {
private:
    Address list[address_book_size];
    int size;

public:
    AddressBook();

    void addAddress(const Address& newAddress);
    void deleteAddress(const std::string& searchName);
    void searchAddress(const std::string& searchName);
    void fixAddress(const std::string& searchName);
    void saveToJson(const std::string& filename);
    void loadFromJson(const std::string& filename);
    void printAddressBook();
    std::string GetAddressBook();
    std::string SearchAddressBook(const std::string& searchName);
};

#endif
