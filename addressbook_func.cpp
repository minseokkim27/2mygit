#include "addressbook_func.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

AddressBook::AddressBook() {}

std::string AddressBook::addAddress(const Address &newAddress)
{
    vct.push_back(newAddress);
    return "주소가 추가되었습니다.\n";
}

std::string AddressBook::DeleteAddressBook(const std::string &searchName)
{
    for (auto itr = vct.begin(); itr != vct.end(); ++itr)
    {
        if (itr->getName() == searchName)
        {
            vct.erase(itr);
            return searchName + "을(를) 삭제했습니다.\n\n";
        }
    }
    return searchName + "이(가) 주소록에 없습니다.\n\n";
}

std::string AddressBook::SearchAddressBook(const std::string &searchName)
{
    std::string str;
    for (auto itr = vct.begin(); itr != vct.end(); ++itr)
    {
        if (itr->getName() == searchName)
        {
            str += "<발견된 " + searchName + ">\n\n";
            str += "이름: " + itr->getName() + "\n";
            str += "성별: " + itr->getSex() + "\n";
            str += "전화번호: " + itr->getNumber() + "\n";
            str += "주소: " + itr->getAddress() + "\n\n";
            return str;
        }
    }
    return searchName + "이(가) 주소록에 없습니다.\n\n";
}

std::string AddressBook::editAddressBook(const std::string &searchName, const std::string &newName, const std::string &newSex, const std::string &newNumber, const std::string &newAddress)
{
    for (auto itr = vct.begin(); itr != vct.end(); ++itr)
    {
        if (itr->getName() == searchName)
        {
            itr->setName(newName);
            itr->setSex(newSex);
            itr->setNumber(newNumber);
            itr->setAddress(newAddress);
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

    for (const auto &address : vct)
    {
        Json::Value addressJson;
        addressJson["name"] = address.getName();
        addressJson["sex"] = address.getSex();
        addressJson["number"] = address.getNumber();
        addressJson["address"] = address.getAddress();
        addressList.append(addressJson);
    }

    root["address book"] = addressList;

    std::ofstream fileOut(filename);
    if (fileOut.is_open())
    {
        fileOut << root;
        fileOut.close();
        str = "주소록이 " + filename + " 으로 저장되었습니다.\n\n";
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
        std::string jsonStr((std::istreambuf_iterator<char>(fileIn)), std::istreambuf_iterator<char>());
        fileIn.close();

        Json::Value root;
        Json::Reader reader;
        bool parsing = reader.parse(jsonStr, root);

        if (parsing)
        {
            Json::Value addressList = root["address book"];
            for (const auto &address : addressList)
            {
                std::string name = address["name"].asString();
                std::string sex = address["sex"].asString();
                std::string number = address["number"].asString();
                std::string addr = address["address"].asString();

                vct.emplace_back(name, sex, number, addr);

                str += "이름: " + name + "\n";
                str += "성별: " + sex + "\n";
                str += "전화번호: " + number + "\n";
                str += "주소: " + addr + "\n";
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
        str = "파일을 열 수 없습니다.\n\n";
    }

    return str;
}

std::string AddressBook::GetAddressBook()
{
    std::string str;
    str += "<현재 가지고 있는 주소록>\n\n";

    if (vct.empty())
    {
        str += "주소록에 주소가 없습니다.\n";
    }
    else
    {
        for (const auto &address : vct)
        {
            str += "이름: " + address.getName() + "\n";
            str += "성별: " + address.getSex() + "\n";
            str += "전화번호: " + address.getNumber() + "\n";
            str += "주소: " + address.getAddress() + "\n\n";
        }
    }
    return str;
}