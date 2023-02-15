add_library(requestData RequestStockData.cpp)

add_subdirectory(../../external/curlpp ../../external/curlpp)
add_subdirectory(../../external/fmtlib ../../external/fmtlib)

target_include_directories(service PUBLIC  ../../external/restbed/distribution/include
                                   PUBLIC  ../../external/fmtlib/include)

target_link_directories(service PRIVATE /home/sergiu/LicentaStockMarcket/Project/external/curlpp
                                PRIVATE ../../external/fmtlib/)

target_link_libraries(requestData fmt::fmt curlpp restbed)
