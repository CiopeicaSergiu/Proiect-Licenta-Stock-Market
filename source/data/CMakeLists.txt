
add_library(data STATIC Date.cpp StockData.cpp)

target_include_directories(data PUBLIC ../../external/boost
                                PUBLIC ../../external/fmtlib/include
                              ../converter)

target_link_directories(data PRIVATE ../../external/boost/stage/lib
                             ../../external/fmtlib
                             ../../builddir/converter)
                             

target_link_libraries(data PUBLIC ${Boost_LIBRARIES} 
                            fmt
                            converter)


