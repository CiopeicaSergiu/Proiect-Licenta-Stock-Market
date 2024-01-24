add_library(utils STATIC Serialize.cpp Utils.cpp PriceGenerator.cpp)


target_include_directories(utils PUBLIC  ../../external/boost
                                         ../../external/restbed/distribution/include)
                                           

target_link_directories(utils PUBLIC ../../external/boost/stage/lib
                                     ../../external/restbed/distribution/library)

target_link_libraries(utils  restbed ${Boost_LIBRARIES})