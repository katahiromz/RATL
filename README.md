# ![](img/RATL-32x32.png) Independent ReactOS ATL (RATL)

This is an "Active Template Library (ATL)" clone from [ReactOS](https://reactos.org/).

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
- Copyright 2009 Andrew Hill (ash77@reactos.org)
- Copyright 2013-2023 Katayama Hirofumi MZ (katayama.hirofumi.mz@gmail.com)
- Copyright 2015-2023 Mark Jansen (mark.jansen@reactos.org)
- Copyright Benedikt Freisen
- And more!

## How to use RATL in your project

1. `git submodule add https://github.com/katahiromz/RATL`
2. Add the following code into your `CMakeLists.txt`:

```txt
add_subdirectory(RATL)
get_directory_property(RATL_DEFINITIONS DIRECTORY RATL DEFINITION RATL_DEFINITIONS)
get_directory_property(RATL_INCLUDE_DIRS DIRECTORY RATL DEFINITION RATL_INCLUDE_DIRS)
get_directory_property(RATL_LIBRARIES DIRECTORY RATL DEFINITION RATL_LIBRARIES)
```

3. Use `RATL_DEFINITIONS`, `RATL_INCLUDE_DIRS`, and `RATL_LIBRARIES` in your `CMakeLists.txt`.

See samples/.

Tested on RosBE (ReactOS Build Environment) and Visual Studio 2019.

## Notes

- `CComQIPtr<type>` is not supported due to GCC compatibility. Use `CComQIIDPtr<I_ID(type)>` instead.

## License

- LGPL 2.1 or later
