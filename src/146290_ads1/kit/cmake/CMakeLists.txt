cmake_minimum_required(VERSION 3.20)
project(c_labkit C)
enable_testing()
set(LAB_DIR "" CACHE PATH "")
if(NOT LAB_DIR)
  message(FATAL_ERROR "LAB_DIR not set")
endif()

add_library(common_headers INTERFACE)
target_include_directories(common_headers INTERFACE "${LAB_DIR}/include")

file(GLOB EXES LIST_DIRECTORIES true RELATIVE "${LAB_DIR}/src" "${LAB_DIR}/src/*")
message(STATUS "LAB_DIR=${LAB_DIR}")
message(STATUS "EXES=${EXES}")

foreach(E ${EXES})
  if(IS_DIRECTORY "${LAB_DIR}/src/${E}")
    file(GLOB EX_SRCS CONFIGURE_DEPENDS "${LAB_DIR}/src/${E}/*.c")
    if(EX_SRCS)
      message(STATUS "EXE ${E} SRCS=${EX_SRCS}")
      add_executable(${E} ${EX_SRCS})
      target_link_libraries(${E} PRIVATE common_headers)
      add_custom_target(run_${E} COMMAND $<TARGET_FILE:${E}> USES_TERMINAL)
      file(GLOB CASES LIST_DIRECTORIES true RELATIVE "${LAB_DIR}/tests/${E}" "${LAB_DIR}/tests/${E}/*")
      foreach(CASE ${CASES})
        if(IS_DIRECTORY "${LAB_DIR}/tests/${E}/${CASE}")
          set(IN  "${LAB_DIR}/tests/${E}/${CASE}/i.txt")
          set(OUT "${LAB_DIR}/tests/${E}/${CASE}/o.txt")
          if(EXISTS "${IN}" AND EXISTS "${OUT}")
            message(STATUS "TEST ${E}_${CASE}")
            add_test(NAME ${E}_${CASE}
                     COMMAND ${CMAKE_COMMAND}
                             -Dexe=$<TARGET_FILE:${E}>
                             -Dinput=${IN}
                             -Dexpected=${OUT}
                             -P ${CMAKE_CURRENT_LIST_DIR}/RunIO.cmake)
          endif()
        endif()
      endforeach()
    endif()
  endif()
endforeach()