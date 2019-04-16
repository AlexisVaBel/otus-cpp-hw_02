cmake_minimum_required(VERSION 3.5)
#without this, got errors due to 98 standard
# why, don`t know
set (CMAKE_CXX_STANDARD 14)


if ($ENV{TRAVIS_BUILD_NUMBER})
 project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
 project(ip_filter  VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)


set(INC_DIRS "io/" "filter")
set(SRC_LIST main.cpp ./io/ip_io.cpp)
set(SRC_LIST_TEST ./tests/test_starter.cpp )

include_directories(${INC_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

add_executable(${PROJECT_NAME}_test ${SRC_LIST_TEST})

#message("   ")
#message(${INC_DIRS})


set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(${PROJECT_NAME}_test PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR} ${INC_DIRS}
)

target_link_libraries(${PROJECT_NAME}_test
    ${Boost_LIBRARIES}
)


install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIDEPS ON)
include(CPack)

enable_testing()
add_test(ip_sort_tests ${PROJECT_NAME}_test)
add_test(ip_sort_test_filter1 ${PROJECT_NAME}_test)
add_test(ip_sort_test_filter46_70 ${PROJECT_NAME}_test)
add_test(ip_sort_test_filter_any46 ${PROJECT_NAME}_test)
