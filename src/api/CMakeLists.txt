# Set compiler settings
SET(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")

# Find header and source files
FILE(GLOB luxapi_header ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
FILE(GLOB luxapi_source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Set target libraries
ADD_LIBRARY(luxapi SHARED ${luxapi_source})
ADD_LIBRARY(luxapi_static STATIC ${luxapi_source})

# Set output name of static library
SET_TARGET_PROPERTIES(luxapi_static PROPERTIES OUTPUT_NAME luxapi)

# Set version number of both libraries
SET(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}) 
SET_TARGET_PROPERTIES(luxapi luxapi_static PROPERTIES VERSION "${VERSION_STRING}" SOVERSION "${VERSION_MAJOR}")

# Link the library with jsonrpc libs
TARGET_LINK_LIBRARIES(luxapi jsonrpc)
TARGET_LINK_LIBRARIES(luxapi_static jsonrpc)

# Install to appropriate destinations
INSTALL(FILES ${luxapi_header} DESTINATION include/luxapi)

INSTALL(TARGETS luxapi luxapi_static
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
