
file(GLOB BW_HACK_SOURCES "*.cxx")

add_library(BWHack
            STATIC
            ${BW_HACK_SOURCES})
