cmake_minimum_required(VERSION 3.9)
set(TARGET edgelog)
project(${TARGET})

set(LIB_FOLDER ${CMAKE_SOURCE_DIR}/lib)
set(LIB_BIN_FOLDER ${LIB_FOLDER}/bin)
set(LIB_LOG4CPP_FOLDER ${LIB_FOLDER}/include)
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include)

find_library(LOG4CPP NAMES liblog4cpp.a PATHS ${LIB_BIN_FOLDER})

add_executable (${TARGET} ./src/main.cpp ./src/JournalAppender.cpp)
#add_library(edgelog SHARED ./src/main.cpp)
target_link_libraries (${TARGET} PUBLIC -L${LOG4CPP})
target_include_directories (${TARGET} PUBLIC
        ${LIB_LOG4CPP_FOLDER}
        ${HEADER_FILES}
        /src
        )
set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN;$ORIGIN/${LIB_LOG4CPP_FOLDER};$ORIGIN/${LIB_BIN_FOLDER}")