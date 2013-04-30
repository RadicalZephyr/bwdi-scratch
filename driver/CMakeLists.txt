
file(GLOB BWDI_DRIVER_SOURCES "*.cxx")

add_library(BWDIDriver
            SHARED
            ${BWDI_DRIVER_SOURCES})
