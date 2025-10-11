if(NOT DEFINED exe OR NOT DEFINED input OR NOT DEFINED expected)
  message(FATAL_ERROR "missing args")
endif()
execute_process(COMMAND "${exe}"
                INPUT_FILE "${input}"
                OUTPUT_FILE "${CMAKE_BINARY_DIR}/io_actual.txt"
                RESULT_VARIABLE rc)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "program exit code: ${rc}")
endif()
execute_process(COMMAND "${CMAKE_COMMAND}" -E compare_files
                "${CMAKE_BINARY_DIR}/io_actual.txt" "${expected}"
                RESULT_VARIABLE diff_rc)
if(NOT diff_rc EQUAL 0)
  message(FATAL_ERROR "output mismatch")
endif()
