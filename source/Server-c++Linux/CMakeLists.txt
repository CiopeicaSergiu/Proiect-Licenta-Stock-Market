add_library(service Service.cpp StockDataService.cpp)

add_subdirectory(../../external/date ../../external/date)
add_subdirectory(../formatter ../formatter)
add_subdirectory(../request ../request)


target_include_directories(service PUBLIC  ../../external/restbed/distribution/include)

target_link_directories(service PRIVATE ../../external/restbed/distribution/library)

target_link_libraries(service  
                        restbed
                        fmt::fmt
                        date::date
                        formatter
                        requestData
                        converter)