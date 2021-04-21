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

add_executable(Exam3 WIN32 main.cpp)

target_link_libraries(Exam3 Qt5::Widgets)

if(WIN32)
		message("-- CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
		add_custom_command(TARGET Exam3 POST_BUILD COMMAND   ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}/plugins/platforms ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)/platforms)
		add_custom_command(TARGET Exam3 POST_BUILD COMMAND   ${CMAKE_COMMAND} -E copy ${CMAKE_PREFIX_PATH}/bin/Qt5Widgets.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Widgetsd.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Core.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Cored.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Gui.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Guid.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)/)
endif()

#qt5_use_modules(ddsgenui Core Widgets Gui)