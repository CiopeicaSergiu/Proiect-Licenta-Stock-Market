
add_library(data Date.cpp StockData.cpp)

add_subdirectory(../converter ../converter)

target_include_directories(data PUBLIC ../../external/boost
                                PUBLIC ../../external/fmtlib/include
                              )

target_link_directories(data PRIVATE ../../external/boost/stage/lib
                             ../../external/fmtlib/)

target_link_libraries(data ${Boost_LIBRARIES} 
                            fmt::fmt
                            converter)


