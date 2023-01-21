add_library(service Service.cpp StockDataService.cpp)

add_subdirectory(../external/date ../external/date)
add_subdirectory(../external/fmtlib ../external/fmtlib)
add_subdirectory(../formatter ../formatter)
add_subdirectory(../external/curlpp ../external/curlpp)


target_include_directories(service PUBLIC  ../external/restbed/distribution/include)

target_link_directories(service PRIVATE ../external/restbed/distribution/library
                                PRIVATE /home/sergiu/LicentaStockMarcket/Project/external/curlpp)

target_link_libraries(service  
                        restbed
                        curlpp
                        fmt::fmt
                        date::date
                        formatter)