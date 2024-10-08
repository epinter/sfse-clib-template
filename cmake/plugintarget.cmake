######## target
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_${CMAKE_CXX_STANDARD})

find_path(CommonLibSFPath "include/REL/Relocation.h"
                PATHS   "${CMAKE_SOURCE_DIR}/extern/CommonLibSF"
                        "${CMAKE_SOURCE_DIR}/external/CommonLibSF" NO_DEFAULT_PATH)

if(EXISTS "${CommonLibSFPath}")
        message("*** CommonLibSF found at ${CommonLibSFPath}")
        set(SFSE_BUILD_TESTS OFF CACHE BOOL "Disable CommonLibSF build tests")
        add_subdirectory("${CMAKE_SOURCE_DIR}/extern/CommonLibSF" CommonLibSF EXCLUDE_FROM_ALL)
else()
        find_package(CommonLibSF REQUIRED)
endif()

if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE /Zi)
        target_link_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:RELEASE>:/DEBUG:FULL;/INCREMENTAL:NO;/OPT:REF,ICF>")
endif()

target_include_directories(${PROJECT_NAME}
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/cmake>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/include>
        $<INSTALL_INTERFACE:src>)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(${PROJECT_NAME} PRIVATE CommonLibSF::CommonLibSF)
target_include_directories(${PROJECT_NAME} PRIVATE CommonLibSF::CommonLibSF)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/PCH.h")
    target_precompile_headers(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/PCH.h")
endif()
