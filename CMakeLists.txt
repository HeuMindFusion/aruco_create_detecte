cmake_minimum_required(VERSION 3.5)

project(aruco_marke_tool)

set(CMAKE_CXX_STANDARD 14)

set(WINDOWS TRUE CACHE INTERNAL "")
set(PLATFORM_PREFIX "win64" CACHE INTERNAL "")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (CMAKE_HOST_WIN32)
    set(HOME_DIR $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE INTERNAL "")
else()
    set(HOME_DIR $ENV{HOME} CACHE INTERNAL "")
endif()
if ("TEST$ENV{MAKE_DEPS_WORKING_DIR}" STREQUAL "TEST")
    set(MAKE_DEPS_WORKING_DIR ${HOME_DIR}/makedeps)
else()    
    set(MAKE_DEPS_WORKING_DIR $ENV{MAKE_DEPS_WORKING_DIR})	
endif()

if (NOT ROOT_DIR_DEFINED)
    add_definitions(-DROOT_DIR="${PROJECT_SOURCE_DIR}")
    set(ROOT_DIR_DEFINED ON)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


find_package(OpenCV 4.0 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})


find_package(Boost REQUIRED)
find_package(PCL REQUIRED)
find_package(Eigen3 REQUIRED)


find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
add_definitions(${PCL_DEFINITIONS})
link_directories(${PCL_LIBRARY_DIRS})

include_directories(${OpenCV_INCLUDE_DIRS})


include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR})


if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 OLD)
	cmake_policy(SET CMP0015 OLD)
endif(COMMAND cmake_policy)

set (CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})


message("${PLANE_DETRC_SRC}")




set(detect_markers_src
    detect_markers.cpp
   )
   
   
 file(GLOB ARUCO_OPENCL_SRC_FILES 
            ./aruco_src/*.cpp 
            ./aruco_src/*.hpp 
            ./aruco_src/opencv2/aruco/* 
            ./aruco_src/opencv2/*)

add_executable(detect_markers ${detect_markers_src} ${ARUCO_OPENCL_SRC_FILES})
target_link_libraries(detect_markers
    ${OpenCV_LIBRARIES}
    )

target_compile_options(detect_markers
    PRIVATE -O3 -std=c++11
    )



########################################


file(GLOB ARUCO_OPENCL_SRC_FILES 
        ./aruco_src/*.cpp 
        ./aruco_src/*.hpp 
        ./aruco_src/opencv2/aruco/* 
        ./aruco_src/opencv2/*)

add_executable(create_maker create_maker.cpp ${ARUCO_OPENCL_SRC_FILES})
target_link_libraries(create_maker
${OpenCV_LIBRARIES}
)

target_compile_options(create_maker
PRIVATE -O3 -std=c++11
)

