add_library(nsga2_test nsga2Test.cpp)
target_include_directories(nsga2_test PUBLIC ./include)

target_link_libraries(nsga2_test PUBLIC pagmo)