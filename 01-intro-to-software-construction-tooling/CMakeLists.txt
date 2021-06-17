CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(area_calculator
    src/main1.cpp
    src/rectangle.cpp
)

ADD_EXECUTABLE(bigger_area_calculator
    src/new_main.cpp
    src/rectangle.cpp
)

ADD_EXECUTABLE(c-echo
    src/main2.cpp
)

ADD_EXECUTABLE(test
    src/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
