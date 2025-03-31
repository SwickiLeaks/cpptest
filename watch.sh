cmake -S . -B build -G Ninja
# find src include CMakeLists.txt -type f | entr -r cmake --build build && ./build/cpptest
find src include include/interviewDB/* CMakeLists.txt -type f | entr -r bash -c "
    echo '🔄 Rebuilding...'
    if cmake --build build; then
        echo '🚀 Running...'
        clear
        ./build/cpptest
    else
        echo '❌ Build failed. Fix errors and try again.'
    fi
"