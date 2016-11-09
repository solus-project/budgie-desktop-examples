#!/bin/bash
clang-format -i $(find c_project -name '*.[ch]')

# Check we have no typos.
which misspell 2>/dev/null >/dev/null
if [[ $? -eq 0 ]]; then
    misspell -error `find c_project -name '*.c' -or -name '*.h'`
fi
