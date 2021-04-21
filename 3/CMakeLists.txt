cmake_minimum_required(VERSION 3.8)
project(qtExample)



add_executable(Exam3 WIN32 main.cpp)

target_link_libraries(Exam3 Qt5::Widgets)

if(WIN32)
		message("-- CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
		add_custom_command(TARGET Exam3 POST_BUILD COMMAND   ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}/plugins/platforms ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)/platforms)
		add_custom_command(TARGET Exam3 POST_BUILD COMMAND   ${CMAKE_COMMAND} -E copy ${CMAKE_PREFIX_PATH}/bin/Qt5Widgets.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Widgetsd.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Core.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Cored.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Gui.dll ${CMAKE_PREFIX_PATH}/bin/Qt5Guid.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)/)
endif()

#qt5_use_modules(ddsgenui Core Widgets Gui)