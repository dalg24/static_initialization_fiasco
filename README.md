# Shared library works as expected
```
cmake -B build-shared -DBUILD_SHARED_LIBS=ON
cmake --build build-shared
./build-shared/MyExe
```
yields
```
Initialize all backends
Apple (hello world!)
Banana (salut!!!)
Kiwi (description goes here)
Orange (description goes here)
-- initialized Apple
-- initialized Banana
-- initialized Kiwi
-- initialized Orange
Initialization done
print info Banana
print info Orange
Finalize all backends
-- finalized Apple
-- finalized Banana
-- finalized Kiwi
-- finalized Orange
Finalization done
```

# Static library does not
```
cmake -B build-static
cmake --build build-static
./build-static/MyExe
```
yields
```
Initialize all backends
Orange (description goes here)
-- initialized Orange
Initialization done
print info Banana
print info Orange
Finalize all backends
-- finalized Orange
Finalization done
```
