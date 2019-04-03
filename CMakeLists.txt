cmake_minimum_required(VERSION 3.2)


project(02.cpp14)




add_executable(${PROJECT_NAME} main.cpp)





set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wpedantic -Wextra")


#set(SRC_LIST main.cpp)

#target_link_libraries (${PROJECT_NAME} ${PROJECT_NAME}_lib)

#install (TARGETS helloworld RUNTIME DESTINATION bin)

#set(CPACK_GENERATOR DEB)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

#set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
#include(CPack)


