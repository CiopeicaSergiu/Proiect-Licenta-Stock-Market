add_library(SqlExecutor STATIC SqlExecutor.cpp SqlGenerator.cpp) 

target_include_directories(SqlExecutor PUBLIC ../../external/mysql_connector/include/jdbc
                                                  ../../external/fmtlib/include
                                                  ../utils)

target_link_directories(SqlExecutor PUBLIC ../../external/mysql_connector/lib64
                                                ../../external/fmtlib)

target_link_libraries(SqlExecutor libmysqlcppconn.so
                                  fmt)

