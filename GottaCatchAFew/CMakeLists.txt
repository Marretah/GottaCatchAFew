# CMake project for GottaCatchAFew
cmake_minimum_required(VERSION 3.10)

# Define the project
project(GottaCatchAFew VERSION 1.0)

# Add source files to the project's executable
add_executable(GottaCatchAFew 
    "GottaCatchAFew.cpp" 
    "GottaCatchAFew.h" 
    "src/Mons.cpp" 
    "src/Mons.h" 
    "Data/Importer.cpp"  # Add Importer.cpp here
    "Data/Importer.h"
    "src/Combat.h" "src/Combat.cpp")

# Specify C++ standard if using a modern version
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET GottaCatchAFew PROPERTY CXX_STANDARD 20)
endif()

# Link the nlohmann_json library
target_link_libraries(GottaCatchAFew PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add tests and install targets if needed.
