add_library(service STATIC Service.cpp)

target_include_directories(service PUBLIC  ../../external/restbed/distribution/include)
                                           

target_link_directories(service PUBLIC ../../external/restbed/distribution/library)
                                        #../../external/mysql_connector/lib64)

target_link_libraries(service  restbed)