
cmake_minimum_required(VERSION 3.16)

project(OpenCVExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV 4.10.0 EXACT REQUIRED)

add_executable(OpenCVExample
    main.cpp
    MyApplication.cpp
    Binary.cpp
    CameraCalibration.cpp
    Edges.cpp
    Features.cpp
    Geometric.cpp
    Histograms.cpp
    Images.cpp
    Recognition.cpp
    Region.cpp
    Utilities.cpp
    Video.cpp
)

target_include_directories(OpenCVExample PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(OpenCVExample PRIVATE
    ${OpenCV_LIBS}
)
