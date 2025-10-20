cmake_minimum_required(VERSION 3.14)

project(cupter)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

find_package(PkgConfig REQUIRED)
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)
find_program(GLIB_COMPILE_SCHEMAS NAMES glib-compile-schemas REQUIRED)

# compile resources
file(GLOB_RECURSE RESOURCE_SOURCES src/assets/*.ui src/assets/*.css src/assets/icons/*.svg)
set(GRESOURCE_C io.github.androeat.cupter.resource.c)
set(GRESOURCE_XML src/assets/gio/io.github.androeat.cupter.resource.xml)

add_custom_command(
        OUTPUT ${GRESOURCE_C}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/assets
        COMMAND ${GLIB_COMPILE_RESOURCES}
        ARGS
        --generate-source
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        ../../${GRESOURCE_XML}
        VERBATIM
        MAIN_DEPENDENCY ${GRESOURCE_XML}
        DEPENDS ${RESOURCE_SOURCES}
)

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

add_custom_target(
        project_resources
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)
set_source_files_properties(
        ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        PROPERTIES GENERATED TRUE
)

# compile and push schemas to systemdir (i know thats shitcode but i fix it later)
add_custom_target(schemas
    COMMAND ${CMAKE_SOURCE_DIR}/schemasCompile.sh ${CMAKE_SOURCE_DIR}
)

# copmpile all .cpp and .h files in src
file(GLOB_RECURSE SOURCE src/*.cpp src/*.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE})
add_executable(cupter ${SOURCE} ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C})

add_dependencies(cupter schemas )


# Include Gtkmm 4
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(cupter ${GTKMM_LIBRARIES})
add_definitions(${GTKMM_CFLAGS_OTHER})

# Include LibAdwaita
pkg_check_modules(ADWAITA REQUIRED libadwaita-1)
include_directories(${ADWAITA_INCLUDE_DIRS})
target_link_libraries(cupter ${ADWAITA_LIBRARIES})

# Include CLI11
pkg_check_modules(CLI11 REQUIRED CLI11)
include_directories(${CLI11_INCLUDE_DIRS})
target_link_libraries(cupter ${CLI11_LIBRARIES})

# Include glibmm
pkg_check_modules(GLIBMM REQUIRED glibmm-2.68)
include_directories(${GLIBMM_INCLUDE_DIRS})
target_link_libraries(cupter ${GLIBMM_LIBRARIES})

# Include GIOMM
pkg_check_modules(GIOMM REQUIRED giomm-2.68)
include_directories(${GIOMM_INCLUDE_DIRS})
target_link_libraries(cupter ${GIOMM_LIBRARIES})