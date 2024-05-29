#ifndef ADDRESSBOOK_FUNC_H
#define ADDRESSBOOK_FUNC_H

#include "address_factor.h"
#include <list>
#include <vector>
#include <map>



const int address_book_size = 10;

class AddressBook {
private:
    Address list[address_book_size];
    // std::vector<Address> m_vecAddress;
    // std::map<std::string, Address> m_vecAddress;
    // std::list<Address> m_listAddress;
    
    int size;

public:
    AddressBook();

    std::string addAddress(const Address &newAddress);
    std::string addAddressBook_Name(const std::string &searchName);
    std::string DeleteAddressBook(const std::string &searchName);
    std::string SearchAddressBook(const std::string& searchName);
    std::string editAddressBook(const std::string &searchName, const std::string &newName, const std::string &newSex, const std::string &newNumber, const std::string &newAddress);
    std::string saveToJson(const std::string &filename);
    std::string loadFromJson(const std::string &filename);
    std::string GetAddressBook();
};

#endif
