cmake_minimum_required(VERSION 3.16.3)

project(NFA)

add_subdirectory(converter)
add_subdirectory(data)
add_subdirectory(formatter)
add_subdirectory(request)
add_subdirectory(service)
add_subdirectory(Server-c++Linux)
add_subdirectory(SqlExecutor)
add_subdirectory(utils)


#add_subdirectory(tests)

add_executable(${PROJECT_NAME} restbedTest.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../external/restbed/distribution/include
                                                  ./Server-c++Linux)

target_link_directories(${PROJECT_NAME} PRIVATE ../external/restbed/distribution/library
                                                ../builddir/Server-c++Linux)

target_link_libraries(${PROJECT_NAME} 
                        server)

