# Install script for directory: /home/luxcore/Desktop/LuxAPI/src/lux

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lux" TYPE FILE FILES
    "/home/luxcore/Desktop/LuxAPI/src/lux/LuxWallet.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/WalletTypes.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/LuxException.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lux/jsonrpc" TYPE FILE FILES
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/errors.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/specificationparser.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/specification.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/serverconnector.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/clientconnector.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/procedure.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/client.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/abstractauthenticator.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/rpc.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/server.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/rpcprotocolserver.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/abstractrequesthandler.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/rpcprotocolclient.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/exception.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/specificationwriter.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lux/jsonrpc/connectors" TYPE FILE FILES
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/connectors/httpserver.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/connectors/mongoose.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/connectors/httpclient.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lux/jsonrpc/json" TYPE FILE FILES
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/json.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/config.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/value.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/forwards.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/features.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/reader.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/writer.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/json_batchallocator.h"
    "/home/luxcore/Desktop/LuxAPI/src/lux/jsonrpc/json/autolink.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/luxcore/Desktop/LuxAPI/src/lux/libluxapi.so.1.0"
    "/home/luxcore/Desktop/LuxAPI/src/lux/libluxapi.so."
    "/home/luxcore/Desktop/LuxAPI/src/lux/libluxapi.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so."
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libluxapi.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/luxcore/Desktop/LuxAPI/src/lux/libluxapi.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

