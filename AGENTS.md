# DRE agent instructions

DRE (Differential Reality Engine) is a CPU-native graphics research platform. Motto: Compute what changes. Preserve what remains.

Read CONSTITUTION.md, ROADMAP.md, docs/research/GENESIS.md and current code before editing. Preserve user changes. Never assume a conventional graphics pipeline is mandatory. Conventional implementations are scientific controls. Do not claim novelty without prior-art research or performance without measurements.

## Engineering
- C++20, Linux x86-64, CMake/Ninja, SDL2 software display. Headless builds must work without SDL2.
- Target older x86-64 CPUs, 4 GB system RAM and 1366x768. 30 FPS is a goal, not a guarantee. Detect actual CPU features; do not globally require AVX or newer instructions. Keep scalar fallback.
- Prefer data-oriented, cache-conscious layouts, explicit ownership, bounded allocations and interchangeable kernels. No mandatory GPU, JIT, Zig or external dependencies at this stage.
- Correctness first. Avoid undefined behavior, signed overflow, unsafe aliasing and data races. Keep experimental code separate until validated.
- Do not discard reusable state without justification; do not reuse invalid state. Measure bookkeeping costs.
- Keep commits focused. Do not force-push, rewrite history, change license, or publish secrets. Do not push automatically unless explicitly requested.

## Research protocol
Every experiment records ID, hypothesis, prior-art caveat, control, candidate, deterministic workload, hardware/compiler/build flags, warmup, repeated samples, median/p95/p99, memory footprint, correctness/error, limitations and conclusion. Compare equivalent work and quality. Prevent dead-code elimination; separate setup and validation from timing. Report unavailable hardware counters as unavailable. Never fabricate results. Negative results are valuable.

## Validation
Configure Release and Debug/headless builds, build and run CTest. Run sanitizers when supported. Check SDL2 software path when available. Use deterministic test fixtures. Document exact commands, failures and untested paths. Update roadmap only for verified work. Keep performance reports machine-specific.

## Current priority
DRE-001B: validate Genesis, repair defects, establish computational microscope (GEN-001 through GEN-008). Do not start full 3D rendering, Fold, runtime code generation or game integration until the foundation is verified. See docs/research/NEXT.md.
