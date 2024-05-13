cmake_minimum_required(VERSION 3.10)

project(BlackholeRaytracer
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILES ${FILES}
	src/stb.cpp

	src/types/vec.cpp
	src/types/point.cpp
	src/types/ray.cpp
	src/types/color.cpp
	src/types/image.cpp

	src/main.cpp
)

add_executable(raytracer ${FILES})
target_include_directories(raytracer PRIVATE include/)
