get_filename_component(tarName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
aux_source_directory(./src SRC)
file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
add_library(${tarName} SHARED ${SRC} ${CURRENT_HEADERS})

target_link_libraries(${tarName} sdk-common)