cmake_minimum_required(VERSION 3.12)


set(
        PROJECT_NAME_VALUE
        TP_OpenGL
)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)
file(
        COPY
        assets
        DESTINATION
        ${CMAKE_BINARY_DIR}
)


set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
        src/entities/Game.cpp src/entities/Game.h src/entities/Skybox.cpp src/entities/Skybox.h src/entities/Tank.cpp src/entities/Tank.h src/entities/Gamepad.cpp src/entities/Gamepad.h src/entities/Bullet.cpp src/entities/Bullet.h src/utils/Path.cpp src/utils/Path.h src/utils/MyTexture.cpp src/utils/MyTexture.h)
if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lopengl32
            -lglu32
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lGL
            -lGLU
    )
endif ()