cmake_minimum_required(VERSION 3.16.3)
project(PRICE_API)


add_executable(${PROJECT_NAME} main.cpp source/PriceService.cpp)
find_package( CURL REQUIRED )
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PUBLIC ../Server-c++Linux
                                                  ../../external/restbed/distribution/include
                                                  ../request
                                                  ../converter
                                                  ../../external/curlpp/include
                                                  ../../external/fmtlib/include
                                                  ../formatter
                                                  ../data)
                                           
                                             
                                                #  
                                                # 


target_link_directories(${PROJECT_NAME} PUBLIC ../../builddir/Server-c++Linux
                                               ../../external/restbed/distribution/library
                                               ../../builddir/request
                                               ../../builddir/converter
                                                ../../external/curlpp
                                                ../../external/fmtlib
                                                ../../builddir/formatter
                                                ../../builddir/data)

target_link_libraries(${PROJECT_NAME} PUBLIC service
                                             restbed
                                             requestData
                                             curlpp
                                             curl
                                             fmt
                                             converter
                                             formatter
                                             data)
                                    
                                            
                                            #  
                                            #  )
