MACRO(ADD_CPPLINT_SUPPORT root)
add_custom_target(cpplint
  run_cpplint.sh ${CMAKE_CURRENT_SOURCE_DIR} ${root}
  VERBATIM)
ENDMACRO(ADD_CPPLINT_SUPPORT)
