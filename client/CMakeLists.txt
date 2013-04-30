
file(GLOB BWDI_CLIENT_SOURCES "*.cxx")

add_library(BWDI
            SHARED
            ${BWDI_CLIENT_SOURCES})
