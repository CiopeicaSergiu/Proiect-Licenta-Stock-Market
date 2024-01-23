add_library(service STATIC Service.cpp StockDataService.cpp Utils.cpp Serialize.cpp)


target_include_directories(service PUBLIC  ../../external/restbed/distribution/include
                                           ../../external/boost
                                           ../SqlExecutor
                                           ../../external/mysql_connector/include/jdbc
                                           ../../external/date/include
                                           ../../external/curlpp/include
                                           ../request)
                                           

target_link_directories(service PUBLIC ../../external/restbed/distribution/library
                                        ../../external/boost/stage/lib
                                        ../../builddir/SqlExecutor
                                        ../../external/mysql_connector/lib64
                                        ../../external/curlpp
                                        ../../builddir/request)
                                        #../../external/mysql_connector/lib64)

target_link_libraries(service  restbed
                               formatter
                               requestData
                               converter
                               ${Boost_LIBRARIES}
                               SqlExecutor
                               curl
                               curlpp)