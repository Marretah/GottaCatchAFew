# CMakeList.txt : CMake project for GottaCatchAFew, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(GottaCatchAFew "GottaCatchAFew.cpp" "GottaCatchAFew.h" "src/Mons.cpp" "src/Mons.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET GottaCatchAFew PROPERTY CXX_STANDARD 20)
endif()

# Link the nlohmann_json library
target_link_libraries(GottaCatchAFew PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add tests and install targets if needed.
