add_subdirectory(Catch2)
# These tests can use the Catch2-provided main
add_executable(SqlExecutorTest SqlExecutorTest.cpp ../Server-c++Linux/Utils.cpp)
target_include_directories(SqlExecutorTest PRIVATE ../SqlExecutor
                                                   ../../external/mysql_connector/include/jdbc
                                                   ../../external/fmtlib/include
                                                   ../../external/boost
                                                   ../../external/restbed/distribution/include)

target_link_directories(SqlExecutorTest PUBLIC ../../builddir/SqlExecutor
                                               ../../external/mysql_connector/lib64
                                               ../../external/fmtlib
                                               ../../external/boost/stage/lib
                                               ../../external/restbed/distribution/library)
                                               

target_link_libraries(SqlExecutorTest PRIVATE Catch2::Catch2WithMain
                                              fmt::fmt
                                              ${Boost_LIBRARIES}
                                              restbed
                                              SqlExecutor
                                              libmysqlcppconn.so)