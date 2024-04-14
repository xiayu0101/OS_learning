add_executable(sum sum.c)
set(CMAKE_CXX_FLAGS -ggdb -Wall -fsanitize=thread)
target_link_libraries(sum pthread)