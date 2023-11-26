add_library(c_object  c_object.c c_object.h)
add_executable(base_test main.cpp)
target_link_libraries(base_test c_object)
