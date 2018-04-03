cmake_minimum_required(VERSION 3.7.2)
set(TARGET clog)
project(${TARGET})

set(LIB_FOLDER ${CMAKE_SOURCE_DIR}/lib)
set(LIB_BIN_FOLDER ${LIB_FOLDER}/bin)
set(LIB_LOG4CPP_FOLDER ${LIB_FOLDER}/include)
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBSYSTEMD REQUIRED libsystemd)


find_library(LOG4CPP NAMES liblog4cpp.a PATHS ${LIB_BIN_FOLDER})

add_executable (${TARGET} ./src/main.cpp ./src/JournalAppender.cpp)
#add_library(edgelog SHARED ./src/main.cpp)
target_compile_options(${TARGET} PUBLIC ${LIBSYSTEMD_CFLAGS_OTHER})
target_link_libraries (${TARGET}
        PUBLIC "-Wl,-whole-archive" ${LOG4CPP} "-Wl,-no-whole-archive"
        ${LIBSYSTEMD_LIBRARIES}
        -lpthread)
target_include_directories (${TARGET} PUBLIC
        ${LIB_LOG4CPP_FOLDER}
        ${HEADER_FILES}
        ${LIBSYSTEMD_INCLUDE_DIR}
        ${LOG4CPP_SOURCE_INC_DIR}
        /src
        )

set_target_properties(${TARGET} PROPERTIES INSTALL_RPATH "$ORIGIN;$ORIGIN/${LIB_LOG4CPP_FOLDER};$ORIGIN/${LIB_BIN_FOLDER}")


MACRO(PROCESSOR_MACRO)
    IF(UNIX AND NOT WIN32)
        FIND_PROGRAM(CMAKE_UNAME uname /bin /usr/bin /usr/local/bin )
        IF(CMAKE_UNAME)
            EXEC_PROGRAM(uname ARGS -m OUTPUT_VARIABLE CMAKE_SYSTEM_PROCESSOR)
            SET(CMAKE_SYSTEM_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR} CACHE INTERNAL
                    "processor type (i386 and x86_64)")
            IF(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
                ADD_DEFINITIONS(-fPIC)
            ENDIF(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        ENDIF(CMAKE_UNAME)
    ENDIF(UNIX AND NOT WIN32)
ENDMACRO(PROCESSOR_MACRO)

PROCESSOR_MACRO()
