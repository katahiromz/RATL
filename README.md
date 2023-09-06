# ![](img/RATL-32x32.png) Independent ReactOS ATL (RATL)

This is an "Active Template Library" clone from [ReactOS](https://reactos.org/).

<p align=center>
  <a href="https://reactos.org/">
    <img alt="ReactOS" src="img/reactos-225x54.png">
  </a>
</p>

<p align=center>
  <a href="https://reactos.org/donate/">
    <img alt="Donate" src="https://img.shields.io/badge/%24-donate-E44E4A.svg">
  </a>
  <a href="https://twitter.com/reactos">
    <img alt="Follow on Twitter" src="https://img.shields.io/twitter/follow/reactos.svg?style=social&label=Follow%20%40reactos">
  </a>
</p>

## Contributors

- Copyright ReactOS Development Team
- Copyright 2005 Jacek Caban
- Copyright 2009 Andrew Hill <ash77@reactos.org>
- Copyright 2013-2023 Katayama Hirofumi MZ (katayama.hirofumi.mz@gmail.com)
- Copyright 2015-2023 Mark Jansen (mark.jansen@reactos.org)
- Copyright Benedikt Freisen
- And more!

## How to use RATL

### 1. Clone RATL

```txt
git clone https://github.com/katahiromz/RATL
```

Or:

```txt
git submodule add https://github.com/katahiromz/RATL
```

### 2. Add subdirectory if it is CMake submodule

```txt
add_subdirectory(RATL)
```

### 3. Add definitions `${RATL_DEFINITIONS}`

```txt
add_definitions(${RATL_DEFINITIONS})
```

Or:

```txt
target_compile_definitions(... PRIVATE ${RATL_DEFINITIONS})
```

### 4. Add include directories `${RATL_INCLUDE_DIRS}`

```txt
include_directories(${RATL_INCLUDE_DIRS})
```

Or:

```txt
target_include_directories(... PRIVATE ${RATL_INCLUDE_DIRS})
```

### 5. Link `${RATL_LIBRARIES}`

```txt
target_link_libraries(... PRIVATE ${RATL_LIBRARIES})
```

### 6. Include RATL's headers

```c
#include <atlbase.h>
#include <atlstr.h>
...
```

### 7. Enjoy RATL programming

Period.

Tested on RosBE, Visual Studio 2015, and Visual Studio 2019.

## License

- LGPL 2.1 or later
