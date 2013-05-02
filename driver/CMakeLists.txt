
file(GLOB BWDI_DRIVER_SOURCES "*.cxx")

add_library(BWDIDriver
            SHARED
            ${BWDI_DRIVER_SOURCES})

add_executable(test_server
               "test/server.cxx")
target_link_libraries(test_server rt)