# CMakeLists files in this project can
# refer to the root source directory of the project as ${MCL_CPP_SOURCE_DIR} and
# to the root binary directory of the project as ${MCL_CPP_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

project (perception_dev)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11")
endif()

# Linking statically to boost. If your project requires Dynamic linking, change here
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT $ENV{BOOST_ROOT} )
FIND_PACKAGE(Boost 1.62.0 COMPONENTS system thread date_time chrono graph unit_test_framework)
if(Boost_FOUND)
	SET(PERCEPTION_DEV_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
	add_definitions(-DBOOST_LIB_DIAGNOSTIC)
	MESSAGE(STATUS "Found Boost_Libraries=" ${Boost_LIBRARIES})
endif()

## EIGEN
FIND_PACKAGE(Eigen3)
SET(PERCEPTION_DEV_INCLUDE_DIRS ${PERCEPTION_DEV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
SET(PERCEPTION_DEV_LIBS ${PERCEPTION_DEV_LIBS} ${Boost_LIBRARIES})

#FIND_PACKAGE(pcl REQUIRED)
if (pcl_FOUND)
  SET(PERCEPTION_DEV_INCLUDE_DIRS ${PERCEPTION_DEV_INCLUDE_DIRS}  ${PCL_INCLUDE_DIRS})
  SET(PERCEPTION_DEV_LIBS ${PERCEPTION_DEV_LIBS} ${PCL_LIBRARIES})
endif()

FIND_PACKAGE(OpenCV REQUIRED)
If(Opencv_FOUND)
  SET(PERCEPTION_DEV_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS})
  SET(PERCEPTION_DEV_LIBS ${OpenCV_LIBS})
endif()

INCLUDE_DIRECTORIES(${PERCEPTION_DEV_INCLUDE_DIRS})

ADD_SUBDIRECTORY(cvlib)
ADD_SUBDIRECTORY(test)
