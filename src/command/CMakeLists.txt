add_executable(xlcol main.c)
target_include_directories(xlcol PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(xlcol xlcollib)
# add_custom_command(TARGET xlcol POST_BUILD COMMAND copy )