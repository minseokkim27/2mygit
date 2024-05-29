#include "addressbook_func.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

AddressBook::AddressBook() : size(0){}

std::string AddressBook::addAddress(const Address &newAddress)
{
    AddressBook m_phonebook;
    std::string str;

    if (size < address_book_size)
    {
        list[size++] = newAddress;
        str = "주소가 추가되었습니다.\n";
    }
    else
    {
        str = "주소록이 가득 찼습니다.\n";
    }
    return str;
}

std::string AddressBook::DeleteAddressBook(const std::string &searchName)
{
    bool found = false;
    std::string str;

    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            for (int j = i; j < size - 1; j++)
            {
                list[j] = list[j + 1];
            }
            size--;
            str = searchName + "을(를) 삭제했습니다.\n\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        str = searchName + "이(가) 주소록에 없습니다.\n\n";
    }

    return str;
}

std::string AddressBook::SearchAddressBook(const std::string &searchName)
{
    bool found = false;
    std::string str;

    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            str += "<발견된 " + searchName + ">\n\n";
            str += "이름: " + list[i].getName() + "\n";
            str += "성별: " + list[i].getSex() + "\n";
            str += "전화번호: " + list[i].getNumber() + "\n";
            str += "주소: " + list[i].getAddress() + "\n\n";
            found = true;
        }
    }

    if (!found)
    {
        str = searchName + "이(가) 주소록에 없습니다.\n\n";
    }

    return str;
}

std::string AddressBook::editAddressBook(const std::string &searchName, const std::string &newName, const std::string &newSex, const std::string &newNumber, const std::string &newAddress)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            list[i].setName(newName);
            list[i].setSex(newSex);
            list[i].setNumber(newNumber);
            list[i].setAddress(newAddress);
            return searchName + "의 정보가 수정되었습니다.\n이름: " + newName + "\n성별: " + newSex + "\n전화번호: " + newNumber + "\n주소: " + newAddress + "\n\n";
        }
    }

    return searchName + "이(가) 주소록에 없습니다.\n\n";
}

std::string AddressBook::saveToJson(const std::string &filename)
{   //json 순서 배열
    Json::Value root;
    Json::Value addressList(Json::arrayValue);
    std::string str;
    for (int i = 0; i < size; i++)
    {
        Json::Value address;
        address["name"] = list[i].getName();
        address["sex"] = list[i].getSex();
        address["number"] = list[i].getNumber();
        address["address"] = list[i].getAddress();
        addressList.append(address);
    }

    root["address book"] = addressList;

    std::ofstream fileOut(filename);
    if (fileOut.is_open())
    {
        fileOut << root;
        fileOut.close();
        str = "주소록이 " + filename + " 으로 build 파일에 저장되었습니다.\n\n";
    }

    else
    {
        str = "파일을 열 수 없습니다.\n\n";
    }

    return str;
}

std::string AddressBook::loadFromJson(const std::string &filename)
{
    std::string str;
    std::ifstream fileIn(filename);
    if (fileIn.is_open())
    {
        std::string jsonStr((std::istreambuf_iterator<char>(fileIn)),
                            std::istreambuf_iterator<char>());
        fileIn.close();

        Json::Value root;
        Json::Reader reader;
        bool parsing = reader.parse(jsonStr, root);

        if (parsing)
        {
            Json::Value addressList = root["address book"];
            for (int i = 0; i < addressList.size(); i++)
            {
                Json::Value address = addressList[i];
                std::string name = address["name"].asString();
                std::string sex = address["sex"].asString();
                std::string number = address["number"].asString();
                std::string addr = address["address"].asString();

                if (size < address_book_size)
                {
                    list[size++] = Address(name, sex, number, addr);

                    str += "이름: " + name + "\n";
                    str += "성별: " + sex + "\n";
                    str += "전화번호: " + number + "\n";
                    str += "주소: " + addr + "\n";
                }
                else
                {
                    str += "주소록이 가득 찼습니다. 추가할 수 없습니다: " + name + "\n";
                }
            }
            str = "주소록이 " + filename + " 파일에서 로드되었습니다.\n\n" + str;
        }
        else
        {
            str = "JSON 파일을 파싱할 수 없습니다.\n\n";
        }
    }
    else
    {
        str = "파일이 없거나 JSON 형식이 아닙니다.\n\n";
    }
    return str;
}

std::string AddressBook::GetAddressBook()
{
    std::string str;
    str += "<현재 가지고 있는 주소록>\n\n";
    if (size == 0)
    {
        str += "주소록에 주소가 없습니다.\n";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            str += "이름: " + list[i].getName() + "\n";
            str += "성별: " + list[i].getSex() + "\n";
            str += "전화번호: " + list[i].getNumber() + "\n";
            str += "주소: " + list[i].getAddress() + "\n\n";
        }
    }
    return str;
}