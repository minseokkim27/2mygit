#include "addressbook_func.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

AddressBook::AddressBook() : size(0){}

void AddressBook::addAddress(const Address &newAddress)
{
    if (size < address_book_size)
    {
        list[size++] = newAddress;
        std::cout << "주소가 추가되었습니다." << std::endl << std::endl;
    }
    else
    {
        std::cout << "주소록이 가득 찼습니다." << std::endl << std::endl;
    }
}

void AddressBook::deleteAddress(const std::string &searchName)
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            for (int j = i; j < size - 1; j++)
            {
                list[j] = list[j + 1];
            }
            size--;
            std::cout << searchName << "을(를) 삭제했습니다." << std::endl
                      << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << searchName << "이(가) 주소록에 없습니다." << std::endl << std::endl;
    }
}

void AddressBook::searchAddress(const std::string &searchName)
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            std::cout << "<발견된 " << searchName << ">" << std::endl;
            std::cout << "이름: " << list[i].getName() << std::endl;
            std::cout << "성별: " << list[i].getSex() << std::endl;
            std::cout << "전화번호: " << list[i].getNumber() << std::endl;
            std::cout << "주소: " << list[i].getAddress() << std::endl << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << searchName << "이(가) 주소록에 없습니다." << std::endl << std::endl;
    }
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

void AddressBook::fixAddress(const std::string &searchName)
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (list[i].getName() == searchName)
        {
            int choice;

            std::cout << "<수정하실 내용을 선택하세요>" << std::endl;
            std::cout << "1. 이름" << std::endl;
            std::cout << "2. 성별" << std::endl;
            std::cout << "3. 전화번호" << std::endl;
            std::cout << "4. 주소" << std::endl << std::endl;
            std::cin >> choice;
            found = true;

            switch (choice)
            {
                case 1:
                {
                    std::cout << "<이름을 수정합니다>" << std::endl;
                    std::cout << "새롭게 사용할 이름: ";
                    std::string newName;
                    std::cin >> newName;
                    list[i].setName(newName);
                    std::cout << newName << "(으)로 수정완료 되었습니다" << std::endl;
                    std::cout << "<<변경된 주소록>>" << std::endl << std::endl;
                    std::cout << "이름: " << list[i].getName() << std::endl;
                    std::cout << "성별: " << list[i].getSex() << std::endl;
                    std::cout << "전화번호: " << list[i].getNumber() << std::endl;
                    std::cout << "주소: " << list[i].getAddress() << std::endl << std::endl;
                break;
                }

                case 2:
                {
                    std::cout << "<성별을 수정합니다>" << std::endl;
                    std::cout << "새롭게 사용할 성별: ";
                    std::string newSex;
                    std::cin >> newSex;
                    list[i].setSex(newSex);
                    std::cout << newSex << "(으)로 수정완료 되었습니다" << std::endl;
                    std::cout << "<<변경된 주소록>>" << std::endl << std::endl;
                    std::cout << "이름: " << list[i].getName() << std::endl;
                    std::cout << "성별: " << list[i].getSex() << std::endl;
                    std::cout << "전화번호: " << list[i].getNumber() << std::endl;
                    std::cout << "주소: " << list[i].getAddress() << std::endl << std::endl;
                break;
                }

                case 3:
                {
                    std::cout << "<전화번호을 수정합니다>" << std::endl;
                    std::cout << "새롭게 사용할 전화번호: ";
                    std::string newNumber;
                    std::cin >> newNumber;
                    list[i].setNumber(newNumber);
                    std::cout << newNumber << "(으)로 수정완료 되었습니다" << std::endl;
                    std::cout << "<<변경된 주소록>>" << std::endl << std::endl;
                    std::cout << "이름: " << list[i].getName() << std::endl;
                    std::cout << "성별: " << list[i].getSex() << std::endl;
                    std::cout << "전화번호: " << list[i].getNumber() << std::endl;
                    std::cout << "주소: " << list[i].getAddress() << std::endl << std::endl;
                break;
                }

                case 4:
                {
                    std::cout << "<주소을 수정합니다>" << std::endl;
                    std::cout << "새롭게 사용할 주소: ";
                    std::string newAddress;
                    std::cin >> newAddress;
                    list[i].setAddress(newAddress);
                    std::cout << newAddress << "(으)로 수정완료 되었습니다" << std::endl;
                    std::cout << "<<변경된 주소록>>" << std::endl << std::endl;
                    std::cout << "이름: " << list[i].getName() << std::endl;
                    std::cout << "성별: " << list[i].getSex() << std::endl;
                    std::cout << "전화번호: " << list[i].getNumber() << std::endl;
                    std::cout << "주소: " << list[i].getAddress() << std::endl << std::endl;
                break;
                }

                default:
                    std::cout << "올바른 번호를 입력해주세요" << std::endl;
                break;
            }
        }
    }

    if (!found)
    {
        std::cout << searchName << "이(가) 주소록에 없습니다." << std::endl << std::endl;
    }
}

void AddressBook::saveToJson(const std::string &filename)
{
    Json::Value root;
    Json::Value addressList(Json::arrayValue);

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
        std::cout << "주소록이 " << filename << " 파일로 저장되었습니다." << std::endl << std::endl;
    }

    else
    {
        std::cout << "파일을 열 수 없습니다." << std::endl << std::endl;
    }
}

void AddressBook::loadFromJson(const std::string &filename)
{
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
                list[size++] = Address(name, sex, number, addr);
            }
            std::cout << "주소록이 " << filename << " 파일에서 로드되었습니다." << std::endl << std::endl;
        }
        else
        {
            std::cout << "JSON 파일을 파싱할 수 없습니다." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << "파일이 없거나 JSON 형식이 아닙니다." << std::endl << std::endl;
    }
}

void AddressBook::printAddressBook()
{

    std::cout << "<현재 가지고 있는 주소록>" << std::endl << std::endl;
    if (size == 0)
    {
        std::cout << "주소록에 주소가 없습니다." << std::endl << std::endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "이름: " << list[i].getName() << std::endl;
            std::cout << "성별: " << list[i].getSex() << std::endl;
            std::cout << "전화번호: " << list[i].getNumber() << std::endl;
            std::cout << "주소: " << list[i].getAddress() << std::endl;
        }
    }
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