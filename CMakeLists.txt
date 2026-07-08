cmake_minimum_required(VERSION 3.16)

project(auto_driving_sim_evaluation VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SRC_LIST
    src/main.cpp
    src/Vehicle.cpp
    src/Logger.cpp
    src/LeadVehicle.cpp
    src/Controller.cpp
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#输出的文件放在根目录下的bin里
add_executable(simulator
    ${SRC_LIST}
)#根据提供的cpp文件编译出目标程序

target_include_directories(simulator PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)#指定头文件的路径，target_include_directories()为固定写法，simulator为输出程序名与上面的add_executable中的simulator一致 
 #PRIVATE 为权限只给当前target自己用，${PROJECT_SOURCE_DIR}为固定函数表示当前项目的根目录，与后面的/include合起来就是头文件地址
