add_library(requestData STATIC RequestStockData.cpp RequestToPriceApi.cpp)

find_package(CURL REQUIRED)

target_include_directories(requestData PUBLIC  ../../external/fmtlib/include
                                   PUBLIC  ../../external/curlpp/include)

target_link_directories(requestData PRIVATE ../../external/curlpp
                                PRIVATE ../../external/fmtlib)

target_link_libraries(requestData libfmt.a curl libcurlpp.a)
