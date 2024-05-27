cmake_minimum_required(VERSION 3.5)

project(QT_address LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)



add_library(
  QT_address_lib SHARED
  address_factor.cpp
  addressbook_func.cpp)

target_link_libraries(QT_address_lib ${JSONCPP_LIBRARIES})
target_include_directories(QT_address_lib PUBLIC ${JSONCPP_INCLUDE_DIRS})

add_executable(
  QT_address
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  add_newwindow.h
  add_newwindow.cpp
  add_newwindow.ui
  edit_newwindow.h
  edit_newwindow.cpp
  edit_newwindow.ui)
  
include_directories(QT_address_lib PUBLIC ${JSON_INCLUDE_DIRS})

target_link_libraries(
  QT_address PRIVATE Qt5::Widgets
  QT_address_lib)