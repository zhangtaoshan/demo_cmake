# 1. 添加子目录
- add_library

添加库文件，指定库名和源文件。

```cmake
add_library(libdir sources.cpp)
```

- add_subdirectory

添加子目录，子目录里面还可包含 CMakeListst.txt。

```cmake
add_subdirectory(mydir)
```

- target_link_directories

和上述第一个对应，为最后的可执行文件链接库。

```cmake
target_link_directories(demo PUBLIC libdir)
```

- target_include_directories

和上述对应，为最后的链接添加头文件，需要添加编译目录和子目录的头文件。

```cmake
target_include_directories(demo PUBLIC "${PROJECT_INCLUDE_DIR}" "${PROJECT_BINARY_DIR}/mydir")
```
然后，引用对应的头文件后即可在源文件中使用。

# 2. 设置编译选项
- option

设置编译选项，并设置提示信息和默认值。

```cmake
option(USE_OPTION "<help-text>" ON)
```
- 条件语句

配合前述的编译选项，这里通过条件判断可决定包含哪些头文件和链接哪些库等。

```cmake
if(xxx)
  xxxx
elseif(xxx)
  xxxx
else()
  xxxx
endif()
```

- list

添加多个值放入列表中，当有多个头文件、源文件或多个库文件时使用。

```cmake
list(APPEND EXTRA_LIBS libdir)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR/mydir}")
```
将待链接库和待引用头文件添分别添加到列表 EXTRA_LIBS 和 EXTRA_INCLUDES 中。后续，可以通过这两个变量名直接指代对应的库和头文件。

```cmake
target_link_directories(demo PUBLIC ${EXTRA_LIBS})
target_include_directories(demo PUBLIC "${PROJECT_INCLUDE_DIR}" ${EXTRA_INCLUDES})
```
- #cmakedefine

为了能在源文件中引用该编译选项，需在头文件中通过 `config_file` 配合 `#cmakedefine` 命令将编译命令转换为对应的设置值。

```cpp
#cmakedefine USE_OPTION
```

