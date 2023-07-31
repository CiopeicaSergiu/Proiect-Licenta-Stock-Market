cmake_minimum_required(VERSION 3.16.3)

project(NFA)

add_executable(${PROJECT_NAME} restbedTest.cpp)

# add_subdirectory(../external/curlpp ../external/curlpp)
add_subdirectory(Server-c++Linux)
add_subdirectory(SqlExecutor)
add_subdirectory(tests)

target_include_directories(${PROJECT_NAME} PUBLIC ../external/restbed/distribution/include)

target_link_directories(${PROJECT_NAME} PRIVATE ../external/restbed/distribution/library)

target_link_libraries(${PROJECT_NAME} 
                        #data
                        restbed
                        service
                        curlpp)

