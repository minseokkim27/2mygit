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
    std::string addAddressBook_Name(const std::string &searchName);
    void deleteAddress(const std::string& searchName);
    std::string DeleteAddressBook(const std::string &searchName);
    void searchAddress(const std::string& searchName);
    std::string SearchAddressBook(const std::string& searchName);
    void editAddress(const std::string& searchName);
    std::string editAddressBook(const std::string &searchName, const std::string &newName, const std::string &newSex, const std::string &newNumber, const std::string &newAddress);
    void saveToJson(const std::string& filename);
    void loadFromJson(const std::string& filename);
    void printAddressBook();
    std::string GetAddressBook();
};

#endif
