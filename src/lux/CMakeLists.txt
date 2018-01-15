file(GLOB_RECURSE lux_source *.c*)
file(GLOB lux_header *.h)

file(GLOB jsonrpc_header jsonrpc/*.h)
file(GLOB connector_header jsonrpc/connectors/*.h)
file(GLOB jsoncpp_header jsonrpc/json/*.h)

# Set target 'lux' to be shared library
add_library(luxapi SHARED ${lux_source})

# Set target 'luxStatic' to be static library
add_library(luxapi_static STATIC ${lux_source})

# Set properties of both targets
set_target_properties(luxapi_static PROPERTIES OUTPUT_NAME luxapi)

set(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}) 
set_target_properties(luxapi luxapi_static PROPERTIES VERSION "${VERSION_STRING}" SOVERSION "${VERSION_MAJOR}")


target_link_libraries(luxapi ${CURL_LIBRARIES})
target_link_libraries(luxapi_static ${CURL_LIBRARIES})

install(FILES ${lux_header} DESTINATION include/lux) 
install(FILES ${jsonrpc_header} DESTINATION include/lux/jsonrpc) 
install(FILES ${connector_header} DESTINATION include/lux/jsonrpc/connectors)
install(FILES ${jsoncpp_header} DESTINATION include/lux/jsonrpc/json) 

install(TARGETS luxapi luxapi_static LIBRARY DESTINATION lib
                      ARCHIVE DESTINATION lib
                      RUNTIME DESTINATION bin)

