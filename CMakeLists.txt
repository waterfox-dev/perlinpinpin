cmake_minimum_required(VERSION 3.16)

project(perlinpinpin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(perlinpinpin
    src/main.cpp
)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs)

    set(DOXYGEN_PROJECT_NAME "Perlinpinpin")
    set(DOXYGEN_RECURSIVE YES)

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_USE_PDFLATEX YES)

    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_DOT_IMAGE_FORMAT svg)

    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_EXTRACT_ALL YES)

    doxygen_add_docs(doc-perlinpinpin
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        COMMENT "Generating API documentation with Doxygen"
    )

else()
    message(WARNING "Doxygen is not installed. Documentation will not be generated.")
endif()