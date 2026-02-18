cmake_minimum_required(VERSION 3.19.0)
project(pagmo-NSGA2-test CXX C)
message(STATUS "Executing top-level CMakeLists.txt...")

set(CMAKE_CXX_STANDARD 20)

#########################################################################################
# EIGEN 3
execute_process(
        COMMAND cmake -S . -B ./build/ -G ${CMAKE_GENERATOR}
        -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/Eigen3
)
message(STATUS "> Eigen3 has been configured.")
#########################################################################################

#########################################################################################
# PAGMO

message(AUTHOR_WARNING "Make sure that you've installed Boost and Intel TBB before using the Pagmo library.")
message(AUTHOR_WARNING "Both Boost and Intel TBB must be in your env PATH variable (e.g. C:\\Program Files (x86)\\Intel\\oneAPI\\tbb\\2022.2\\bin) or else pagmo.dll won't load.'")

set(PAGMO_WITH_EIGEN3 ON)
add_subdirectory(./external/pagmo)

# This needs to be added or Pagmo won't compile with newest MSVC (14.44)
if(MSVC)
    target_compile_definitions(pagmo PRIVATE _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS)
    target_compile_options(pagmo PRIVATE /W2 /EHsc)
endif()
#########################################################################################

# So the EXE find this dll
set_target_properties(pagmo
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
)

add_subdirectory(src)

# Pagmo deps:
# Boost (must be in env path)
# Intel TBB (must be in evn path)
# Eigen3