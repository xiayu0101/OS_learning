add_executable(stack-probe stack-probe.c)
target_link_libraries(stack-probe pthread)
add_executable(mem-ordering mem-ordering.c)
target_link_libraries(mem-ordering pthread)