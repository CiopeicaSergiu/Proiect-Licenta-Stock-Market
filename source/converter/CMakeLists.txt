
add_library(converter TimeConverter.cpp)

target_include_directories(converter PUBLIC ../../external/boost)

target_link_directories(converter PRIVATE ../../external/boost/stage/lib)

target_link_libraries(converter ${Boost_LIBRARIES})


