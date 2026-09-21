# TinyGL

## A tiny graphics library for learning, fun and my portfolio if its posible.

TinyGL is a tiny graphics library written in C++ using OpenGL. The idea is to provide a simple and easy-to-use API for rendering 2D and 3D graphics.

### Getting Started
To get started with TinyGL, clone the repository and build the project using CMake.

```cmd
git clone https://github.com/Hernibyte/TinyGL.git
cd TinyGL
cmake --preset vs2026-debug
```

You can then open the generated solution in Visual Studio and build the project.
I left .bat files in the 'cmake-fastbuild' directory for convenience but is only one command, be happy.
In the near future I want check support for fetch_content and other CMake features that you can use to fast build and test your projects.

For now it's only support windows with msvc compiler but I hope to add support for other platforms with clang compiler and Ninja in the future.

I hope you find TinyGL useful and enjoy learning graphics programming.
All feedback are welcome!

### Dependencies
- glfw
- glad
- glm
- spdlog
