message(STATUS "Executing ./src CMakeLists.txt...")

add_executable(main "./main.cpp")

add_subdirectory(algorithms)

target_link_libraries(main nsga2_test)
