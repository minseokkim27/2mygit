cmake_minimum_required(VERSION 3.5)

project(test_3 LANGUAGES CXX)

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
  test_3_lib SHARED
  address_factor.cpp
  addressbook_func.cpp)
target_link_libraries(test_3_lib ${JSONCPP_LIBRARIES})
target_include_directories(test_3_lib PUBLIC ${JSONCPP_INCLUDE_DIRS})

add_executable(
  test_3
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui)
include_directories(test_3_lib PUBLIC ${JSON_INCLUDE_DIRS})

target_link_libraries(
  test_3 PRIVATE Qt5::Widgets
  test_3_lib)