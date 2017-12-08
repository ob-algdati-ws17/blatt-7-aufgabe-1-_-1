file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(TestTree ${SRCS} ../AVLTree.h ../AVLTree.cpp)

target_link_libraries(TestTree
        gtest
        gmock
        )

include_directories("..")

install(TARGETS TestTree DESTINATION bin)