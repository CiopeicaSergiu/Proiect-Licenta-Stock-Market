add_library(service Service.cpp StockDataService.cpp)


target_include_directories(service PUBLIC ../../external/restbed/distribution/include
                                          ../converter
                                          ../formatter
                                          ../external/curlpp/include
                                          ../external/date/include)

target_link_directories(service PRIVATE ../../external/restbed/distribution/library
                                        ./../builddir/converter
                                        ./../builddir/formatter
                                        ./../builddir/data
                                        ../external/curlpp
                                        ../external/date/include)

target_link_libraries(service  restbed
                    ${CMAKE_BINARY_DIR}/formatter/libformatter.a
                    ${CMAKE_BINARY_DIR}/converter/libconverter.a
                    ${CMAKE_BINARY_DIR}/data/libdata.a
                    curlpp
                    date::date)