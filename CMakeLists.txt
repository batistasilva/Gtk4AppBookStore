cmake_minimum_required(VERSION 3.16)

project(Gtk4AppBookStore LANGUAGES C)

#To enable handle action inside glade file
#Should be setted in target_link_libraries
set (CMAKE_CXX_FLAGS "-fexceptions -export-dynamic")

# Add the util/ folder to include path
include_directories(${CMAKE_SOURCE_DIR}/util)

# Add the src/ folder to include path
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the dao/ folder to include path
include_directories(${CMAKE_SOURCE_DIR}/dao)

find_package(PkgConfig REQUIRED)

pkg_check_modules(MARIADB REQUIRED IMPORTED_TARGET "mysqlclient")

pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

add_executable(Gtk4AppBookStore main.c
    util/mysql_utils.h
    util/mysql_utils.c
    util/util.h
    util/util.c
    gui/gtkaddtolist.xml
    dao/my.cnf
    src/bookstore.h
    src/bookstore.c
    gui/css/style.css
    dao/bookstore_dao.c
    dao/bookstore_dao.h

)

# Include and link MySQL client
target_include_directories(Gtk4AppBookStore PRIVATE ${MYSQL_INCLUDE_DIRS})

target_link_libraries(Gtk4AppBookStore PRIVATE
    ${GTK4_LIBRARIES}
    ${CMAKE_CXX_FLAGS}
    PUBLIC mariadb
)

