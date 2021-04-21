cmake_minimum_required(VERSION 3.8)
project(qtExample)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


if(WIN32)
		set(CMAKE_PREFIX_PATH C:/Qt/Qt5.14.2/5.14.2/msvc2015_64)
ELSEIF(UNIX)
		set(CMAKE_PREFIX_PATH /home/john/Qt5.14.2/5.14.2/gcc_64)
endif()

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
#add_subdirectory(5)


#qt5_use_modules(ddsgenui Core Widgets Gui)