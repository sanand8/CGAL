# This is the CMake script for compiling a CGAL application.

project (GraphicsView_Demo)

cmake_minimum_required(VERSION 2.8.11)
if(POLICY CMP0053)
  cmake_policy(SET CMP0053 OLD)
endif()
if(POLICY CMP0043)
  cmake_policy(SET CMP0043 OLD)
endif()

find_package(CGAL COMPONENTS Qt5)

include(${CGAL_USE_FILE})

find_package(Qt5 QUIET COMPONENTS Xml Script OpenGL Svg)

if ( CGAL_FOUND AND CGAL_Qt5_FOUND AND Qt5_FOUND )

  add_definitions(-DQT_NO_KEYWORDS)

  add_executable  ( CGAL_2 CGAL_2.cpp  ${CGAL_Qt5_RESOURCE_FILES} ${CGAL_Qt5_MOC_FILES})

  qt5_use_modules(CGAL_2 Xml Script OpenGL Svg)

  add_to_cached_list( CGAL_EXECUTABLE_TARGETS CGAL_2 )

  # Link with Qt libraries
  target_link_libraries( CGAL_2 ${QT_LIBRARIES} )
  # Link with CGAL
  target_link_libraries( CGAL_2 ${CGAL_LIBRARIES}  ${CGAL_3RD_PARTY_LIBRARIES})

else()

  message(STATUS "NOTICE: This demo requires CGAL and Qt5, and will not be compiled.")

endif()
