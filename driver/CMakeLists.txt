
file(GLOB BWDI_DRIVER_SOURCES "*.cxx")

add_library(BWDIDriver
            SHARED
            ${BWDI_DRIVER_SOURCES})

add_executable(test_server
               "test/server.cxx")
target_link_libraries(test_server rt)

add_executable(test_client
               "test/client.cxx")
target_link_libraries(test_client rt)

add_executable(test_driver
               "test/driver.cxx")
target_link_libraries(test_driver ${POCO_LIBRARIES})
add_test(round_trip "test_driver")