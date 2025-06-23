cmake_minimum_required(VERSION 3.10.0)
project(kz_vvv VERSION 0.1.0 LANGUAGES C CXX)



include(CTest)
enable_testing()
file(GLOB SOURCES1 "src/**/*.cpp")
file(GLOB SOURCES2 "src/*.cpp")
#配置头文件目录
include_directories(C:/myWareHouse/dev/cpp/cmake_install/include 
        C:/myWareHouse/dev/cpp/include 
        ./include)
add_executable(kz_vvv main.cpp ${SOURCES1} ${SOURCES2})
# add_executable(kz_vvv  main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
