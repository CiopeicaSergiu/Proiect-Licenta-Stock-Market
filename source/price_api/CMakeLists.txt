cmake_minimum_required(VERSION 3.16.3)
project(PRICE_API)


add_executable(${PROJECT_NAME} main.cpp source/PriceService.cpp)
find_package( CURL REQUIRED )
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PUBLIC ../Server-c++Linux
                                                 ../../external/curlpp/include
                                                 ../request
                                                 ../converter
                                                 ../formatter
                                                 ../data
                                                 ../../external/restbed/distribution/include
                                                 ../../external/fmtlib/include)

target_link_directories(${PROJECT_NAME} PUBLIC ../../builddir/Server-c++Linux
                                               ../../external/curlpp
                                               ../../builddir/request
                                               ../../builddir/converter
                                               ../../builddir/formatter
                                               ../../builddir/data
                                               ../../external/restbed/distribution/library
                                               ../../external/fmtlib)

target_link_libraries(${PROJECT_NAME} PUBLIC libservice.a
                                             librequestData.a
                                             CURL::libcurl
                                             curlpp
                                             libconverter.a
                                             libformatter.a
                                             restbed
                                             libfmt.a
                                             libdata.a)
