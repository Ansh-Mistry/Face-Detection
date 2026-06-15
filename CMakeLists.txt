cmake_minimum_required(VERSION 3.15)
project(FaceDetection)

# Find your OpenCV installation
# 1. Force CMake to point to the exact folder containing OpenCVConfig.cmake
set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib" CACHE PATH "" FORCE)

# 2. Force OpenCV to accept your newer Visual Studio 2026 compiler
set(OpenCV_RUNTIME "vc16" CACHE STRING "" FORCE)

# 3. Now run the search
find_package(OpenCV REQUIRED)
# Tell CMake to build an executable from your C++ file
add_executable(FaceDetect main.cpp)

# Link the OpenCV libraries to your application
target_link_libraries(FaceDetect ${OpenCV_LIBS})