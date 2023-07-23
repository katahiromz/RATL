# Independent ReactOS ATL (RATL)

This is an "Active Template Library" clone. Feedback is welcome.

## Requirements

- Win32/C/C++ and CMake

## How to use RATL

### 1. Clone RATL

```txt
git clone https://github.com/katahiromz/RATL
```

Or:

```txt
git submodule add https://github.com/katahiromz/RATL
```

### 2. Add definitions `${RATL_DEFINITIONS}`

```txt
add_definitions(${RATL_DEFINITIONS})
```

Or:

```txt
target_compile_definitions(... PRIVATE ${RATL_DEFINITIONS})
```

### 3. Add include directories `${RATL_INCLUDE_DIRS}`

```txt
include_directories(${RATL_INCLUDE_DIRS})
```

Or:

```txt
target_include_directories(... PRIVATE ${RATL_INCLUDE_DIRS})
```

### 4. Link `${RATL_LIBRARIES}`

```txt
target_link_libraries(... PRIVATE ${RATL_LIBRARIES})
```

### 5. Include RATL's headers

```c
#include <atlbase.h>
#include <atlstr.h>
...
```

### 6. Enjoy RATL programming

Period.

## License

- LGPL 2.1 or later

## Contact Us

- katayama.hirofumi.mz@gmail.com
