add_library(server STATIC StockDataService.cpp)


target_include_directories(server PUBLIC  ../../external/restbed/distribution/include
                                           ../../external/boost
                                           ../SqlExecutor
                                           ../../external/mysql_connector/include/jdbc
                                           ../../external/date/include
                                           ../../external/curlpp/include
                                           ../request
                                           ../service
                                           ../utils)
                                           

target_link_directories(server PUBLIC ../../external/restbed/distribution/library
                                        ../../external/boost/stage/lib
                                        ../../builddir/SqlExecutor
                                        ../../external/mysql_connector/lib64
                                        ../../external/curlpp
                                        ../../builddir/request
                                        ../../builddir/service
                                        ../../builddir/utils)
                                        #../../external/mysql_connector/lib64)

target_link_libraries(server   service
                               restbed
                               formatter
                               requestData
                               converter
                               utils
                               ${Boost_LIBRARIES}
                               SqlExecutor
                               libmysqlcppconn.so
                               curl
                               curlpp)