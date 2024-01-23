
add_library(formatter STATIC DataFormater.cpp parsing.cpp)

target_include_directories(formatter PUBLIC ../../external/boost
                                     PUBLIC ../../external/fmtlib/include
                                     PUBLIC ../data)

target_link_directories(formatter PUBLIC ../../external/boost/stage/lib
PUBLIC ../../external/fmtlib
PUBLIC ../../builddir
PUBLIC ../../buiddir/data)

target_link_libraries(formatter #curlpp 
                                ${Boost_LIBRARIES} 
                                #nlohmann_json::nlohmann_json 
                                fmt
                                data)


