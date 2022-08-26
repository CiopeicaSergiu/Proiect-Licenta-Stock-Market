cmake_minimum_required(VERSION 3.16.3)

project(NFA)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(../external/curlpp ../external/curlpp)
add_subdirectory(../external/nlohmann ../external/nlohmann)
add_subdirectory(../external/fmtlib ../external/fmtlib)
add_subdirectory(../external/date ../external/date)
add_subdirectory(formatter)
add_subdirectory(converter)
target_include_directories(${PROJECT_NAME} PUBLIC ../external/curlpp/include
                                           PUBLIC ../external/boost
                                           PUBLIC ../external/nlohmann
                                           PUBLIC ../external/fmtlib
                                           PUBLIC ../external/date)

target_link_directories(${PROJECT_NAME} PRIVATE ../external/curlpp
                                        PRIVATE ../external/boost/stage/lib
                                        PRIVATE ../external/nlohmann/include
                                        PRIVATE ../external/fmtlib/include
                                        PRIVATE ../external/date/include)

target_link_libraries(${PROJECT_NAME} 
                        curlpp 
                        ${Boost_LIBRARIES} 
                        nlohmann_json::nlohmann_json 
                        fmt::fmt 
                        formatter 
                        converter
                        date::date)

