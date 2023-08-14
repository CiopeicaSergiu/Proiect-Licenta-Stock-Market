add_library(service STATIC Service.cpp StockDataService.cpp Utils.cpp Serialize.cpp)

add_subdirectory(../../external/date ../../external/date)
add_subdirectory(../formatter ../formatter)
add_subdirectory(../request ../request)


target_include_directories(service PUBLIC  ../../external/restbed/distribution/include
                                           ../../external/boost
                                           ../SqlExecutor
                                           ../../external/mysql_connector/include/jdbc)
                                           

target_link_directories(service PUBLIC ../../external/restbed/distribution/library
                                        ../../external/boost/stage/lib
                                        ../../builddir/SqlExecutor
                                        ../../external/mysql_connector/lib64)
                                        #../../external/mysql_connector/lib64)

target_link_libraries(service  restbed
                               fmt::fmt
                               date::date
                               formatter
                               requestData
                               converter
                               ${Boost_LIBRARIES}
                               SqlExecutor
                               )