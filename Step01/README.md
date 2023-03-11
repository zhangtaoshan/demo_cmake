# 1. 基于 CMake 构建最基本的项目
- cmake_minimum_required

设置所需的最低 CMake 版本，如果版本低于此则报错。

```cmake
cmake_minimum_required(VERSION 3.10)
```

- project

设置项目的相关信息。

```cmake
project(demo VERSION 0.1)
```

- add_executable

基于源文件生成可执行文件。

```cmake
add_executable(demo sources.cpp)
```

# 2. 设置编译的 C++ 版本
可通过 `set` 指令设置项目使用的 C++ 版本。

```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

# 3. 使用 CMake 定义的变量
- config_file

拷贝文件，并修改其中内容。

```cmake
config_file(input.hpp output.hpp)
```

上述通过 `project` 设置项目版本，这里可以通过 `@<project-name>_VERSION_MAJOR@` 和 `@<project-name>_VERSION_MINOR@` 分别与前述的主次版本号对应。

```cpp
# input.hpp
#define demo_VERSION_MAJOR @demo_VERSION_MAJOR@
#define demo_VERSION_MINOR @demo_VERSION_MINOR@
```

配合 `config_file` 命令，output.hpp 为生成值。

```cpp
# output.hpp
#define demo_VERSION_MAJOR 0
#define demo_VERSION_MINOR 1
```

然后可以在源文件中引用以获得项目版本号。

- target_include_directories

为生成的目标文件添加头文件。

```cmake
target_include_directories(demo PUBLIC ${PROJECT_BINARY_DIR})
```

其中，`PROJECT_BINARY_DIR`、`PROJECT_SOURCE_DIR` 和 `<project-name>_BINARY_DIR` 是 CMake 的预定义变量，一般指代工程顶层目录。

