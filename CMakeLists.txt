
cmake_minimum_required (VERSION 3.14)

project(oop1_ex04)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	add_compile_options (/permissive-)
endif ()

set (SFML_STATIC_LIBRARIES TRUE)

set (SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio

sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

add_executable (oop1_ex04 "")

target_link_libraries (oop1_ex04 sfml-graphics sfml-main)



add_subdirectory (include)
add_subdirectory (src)
#add_subdirectory (resources)