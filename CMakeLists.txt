cmake_minimum_required(VERSION 3.15)
project(TacticTanks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES 
    src/main.cpp
    src/Camera.cpp
    src/Color.cpp
    src/Cube.cpp
    src/Cuboid.cpp
    src/Cylinder.cpp
    src/FirstPersonCamera.cpp
    src/Game.cpp
    src/HUD.cpp
    src/Model.cpp
    src/ModelLoader.cpp
    src/Player.cpp
    src/Scene.cpp
    src/Solid.cpp
    src/Sphere.cpp
    src/SScreenScene.cpp
    src/Teapot.cpp
    src/Text.cpp
    src/ThirdPersonCamera.cpp
    src/Torus.cpp
    src/Triangle.cpp
    src/Vector3D.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include
${GLEW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    GLEW:GLEW
    glfw
)   

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()