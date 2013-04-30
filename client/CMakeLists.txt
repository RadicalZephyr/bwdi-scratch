
file(GLOB BWDI_CLIENT_SOURCES "*.cxx")

add_library(bwdi
            SHARED
            ${BWDI_CLIENT_SOURCES})
