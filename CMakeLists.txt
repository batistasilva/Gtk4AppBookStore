cmake_minimum_required(VERSION 3.16)

project(Gtk4AppBookStore LANGUAGES C)

#To enable handle action inside glade file
#Should be setted in target_link_libraries
set (CMAKE_CXX_FLAGS "-fexceptions -export-dynamic")

# Add the util-app/ folder to include path
# include_directories(${CMAKE_SOURCE_DIR}/util-app)

# Add the util-db/ folder to include path
include_directories(${CMAKE_SOURCE_DIR}/util-db)

# Add the src/ folder to include path
# include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the dao/ folder to include path
# include_directories(${CMAKE_SOURCE_DIR}/dao)

find_package(PkgConfig REQUIRED)

pkg_check_modules(MARIADB REQUIRED IMPORTED_TARGET "mysqlclient")

pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

add_executable(Gtk4AppBookStore main.c
    util-db/mysql_utils.h
    util-db/mysql_utils.c
    util-db/util.h
    util-db/util.c
    gui/gtkaddtolist.xml
    dao/my.cnf

    src/bookstore.h
    src/bookstore.c
    util-app/alert_handler.h
    util-app/alert_handler.c

    gui/css/style.css
    dao/bookstore_dao.c
    dao/bookstore_dao.h
    util-app/book-struct-util.h
    util-dbg/show-msg.c util-dbg/error_log.h util-dbg/show-msg.h
    src/menu-app.h
    src/menu-app.c
    gui/screenshot/bookstore-screenshot-2.png
    gui/screenshot/bookstore-screenshot-1.png

)

# Include and link MySQL client
# target_include_directories(Gtk4AppBookStore PRIVATE ${MYSQL_INCLUDE_DIRS})

# Include directories for headers
target_include_directories(Gtk4AppBookStore PRIVATE ${MYSQL_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/util-app
    ${PROJECT_SOURCE_DIR}/dao
)



target_link_libraries(Gtk4AppBookStore PRIVATE
    ${GTK4_LIBRARIES}
    ${CMAKE_CXX_FLAGS}
    PUBLIC mariadb
)

