file(GLOB lux_tests_src *.cpp)

# Set library path
INCLUDE_DIRECTORIES(/usr/local/include/lux)

# Create new target
add_executable(luxapi_tests ${lux_tests_src})
target_link_libraries(luxapi_tests luxapi boost_system boost_filesystem boost_unit_test_framework)


