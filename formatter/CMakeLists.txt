
add_library(formatter DataFormater.cpp parsing.cpp)

add_subdirectory(../data ../data)
target_include_directories(formatter PUBLIC ../external/boost
                                     PUBLIC ../external/fmtlib/include
                                     PUBLIC ../data)

target_link_directories(formatter PRIVATE ../external/boost/stage/lib
                                  PRIVATE ../external/fmtlib
                                  PRIVATE ../builddir)

target_link_libraries(formatter #curlpp 
                                ${Boost_LIBRARIES} 
                                #nlohmann_json::nlohmann_json 
                                fmt::fmt
                                data)


