set_property(TARGET precice PROPERTY PUBLIC_HEADER
  ${CMAKE_CURRENT_LIST_DIR}/include/precice/SolverInterfaceC.h
  APPEND)

target_sources(preciceCore PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include/precice/SolverInterfaceC.h
  ${CMAKE_CURRENT_LIST_DIR}/src/SolverInterfaceC.cpp
  )

target_include_directories(preciceCore PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
  )

target_include_directories(precice PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
  )
