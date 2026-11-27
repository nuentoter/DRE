# Genesis implementation

The initial framebuffer pattern is a diagnostic, not a 3D renderer. Benchmark measures pattern generation only, excluding checksum and presentation. Ten warmup iterations precede 120 measured iterations. Percentiles use floor-index order statistics. CPU flags are reported, not used to dispatch SIMD yet. Cache data describes CPU0, not aggregate capacity.

Build: `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release` then `cmake --build build` and `ctest --test-dir build --output-on-failure`. Run `./build/dre_bench` or `./build/dre_lab`. Headless builds use `-DDRE_DISPLAY=OFF`.

Next: independent arithmetic and memory kernels, reference rasterizer, deterministic scene replay and image comparison. No performance claims or license selection yet.
