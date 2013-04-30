
file(GLOB BW_HACK_SOURCES "*.cxx")

add_library(bwhack
            STATIC
            ${BW_HACK_SOURCES})
