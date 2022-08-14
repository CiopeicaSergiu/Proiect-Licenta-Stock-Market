
add_library(formatter StockData.cpp DataFormater.cpp parsing.cpp)

target_include_directories(formatter PUBLIC ../../external/boost
                                     PUBLIC ../../external/fmtlib)

target_link_directories(formatter PRIVATE ../../external/boost/stage/lib
                                  PRIVATE ../../external/fmtlib/include)

target_link_libraries(formatter #curlpp 
                                ${Boost_LIBRARIES} 
                                #nlohmann_json::nlohmann_json 
                                fmt::fmt)


