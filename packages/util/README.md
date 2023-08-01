# Utility library

A collection of utility classes and functionality that can be useful in certain situations (or was just an interesting idea to make)

| File | Description |
| - | - |
| [debug](util/include/util/debug.hpp) | A selection of functionality (primarily logging) only availble in debug build (using the NDEBUG macro) |
| [filewatcher](util/include/util/filewatcher.hpp) | A lazy file watching class that checks if a file was modified every 500 milliseconds (based on write time) |
| [raii](util/include/util/raii.hpp) | Classes that use their lifespan to manage temporary changes to objects |
| [types](util/include/util/types.hpp) | Template utilities for collections of types |
| [values](util/include/util/values.hpp) | Template functionality for compile time values |
