cmake_minimum_required (VERSION 3.6)

project(balaev_a_a)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#Путь до папки с библиотеками, если не установлены переменные среды
#set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/msvc2019_64/")
#set(CMAKE_INSTALL_PREFIX "D:/coursework/checkResult/")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable (
coursework 
	"BoughtCollection.cpp"  
	"BoughtCollection.h" 
	"changeinformation.cpp"  
	"changeinformation.h" 
	"client.cpp" 
	"client.h" 
	"graphics.cpp" 
	"graphics.h" 
	"Investment.cpp" 
	"Investment.h"    
	"mainwindow.h" 
	"mainwindow.cpp" 
	"main.cpp" 
	"myinvestment.cpp" 
	"myinvestment.h"
	"PaperCollection.cpp"
	"PaperCollection.h"
	"qcustomplot.cpp"
	"qcustomplot.h"
	"SecurityPaper.cpp"
	"SecurityPaper.h"
	"User.cpp"
	"User.h"
	"utils.cpp"
	"utils.h"
)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Sql PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Sql PrintSupport REQUIRED)

target_link_libraries(coursework PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::PrintSupport)
install(TARGETS coursework DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Sql> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::PrintSupport> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::QSQLiteDriverPlugin> DESTINATION bin/sqldrivers)
install(FILES $<TARGET_FILE:Qt5::QWindowsIntegrationPlugin> DESTINATION bin/platforms)
install(FILES $<TARGET_FILE:Qt5::QWindowsDirect2DIntegrationPlugin> DESTINATION bin/platforms)