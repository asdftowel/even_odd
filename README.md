[![C/C++ CI](https://github.com/asdftowel/even_odd/actions/workflows/c-cpp.yml/badge.svg?branch=master)](https://github.com/asdftowel/even_odd/actions/workflows/c-cpp.yml)

# even_odd
A program that says whether its argument is a number
and if it is even or odd.
## Build parameters
SRCDIR sets the source directory, use this if you're
not building in-tree.

PGOGEN and PGOUSE set parameters that will be passed
to the compiler when instrumenting and building with
profile data respectively.

PROFEX sets the extension of profile data files,
PFILES lets you specify the filter for profile files
if needed by the compiler.

To build normally:
```bash
make
```

To run unit tests:
```bash
make check
```

To build with PGO:
```bash
make pgo
```

To remove the executable:
```bash
make clean
```