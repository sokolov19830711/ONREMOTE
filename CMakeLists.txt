cmake_minimum_required(VERSION 3.0.0)

project(ONREMOTE+ VERSION 0.1)

find_package(Qt5 COMPONENTS Widgets SerialPort Qml Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME} WIN32 "appIcon.rc" "qml.qrc" "src/main.cpp"	
									"src/DataManager.cpp" "src/SerialPortManager.cpp" "src/AccountManager.cpp")
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::SerialPort Qt5::Qml Qt5::Quick)