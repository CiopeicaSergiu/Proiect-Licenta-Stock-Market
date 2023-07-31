add_subdirectory(Catch2)
# These tests can use the Catch2-provided main
add_executable(SqlExecutorTest SqlExecutorTest.cpp)
target_include_directories(SqlExecutorTest PRIVATE ../SqlExecutor
                                                   ../../external/mysql_connector/include/jdbc
                                                   ../../external/fmtlib/include)
target_link_directories(SqlExecutorTest PUBLIC ../../builddir/SqlExecutor
                                               ../../external/mysql_connector/lib64
                                               ../../external/fmtlib)
                                               

target_link_libraries(SqlExecutorTest PRIVATE Catch2::Catch2WithMain
                                              libSqlExecutor.a
                                              libmysqlcppconn.so
                                              fmt::fmt)