# DRE-001B — Genesis validation and computational microscope

1. Inspect repository and git status; preserve existing changes. Record hardware, OS, compiler, build configuration.
2. Build Release and Debug headless, run CTest, build SDL2 laboratory if available, smoke-test display when possible. Fix defects and add regression tests. Inspect CI configuration.
3. Implement a reusable benchmark harness with deterministic seeds, configurable iterations and workload sizes, warmup, checksums, correctness checks, median/p95/p99 and CSV or JSON export. Record setup separately; do not time I/O.
4. Implement independent paired experiments:
   - GEN-001 scalar arithmetic: add/multiply/divide and dependency-chain vs throughput.
   - GEN-002 float vs fixed point: equivalent bounded workloads, explicit error/overflow analysis.
   - GEN-003 sequential vs randomized memory access: same data and access counts, multiple working-set sizes.
   - GEN-004 branch vs branchless: identical results, predictable and unpredictable inputs; inspect compiler output if practical.
   - GEN-005 scalar vs SIMD: portable scalar and SSE2 where supported, runtime dispatch as needed, tail correctness.
   - GEN-006 AoS vs SoA: identical operations and data, cache-sized and larger workloads.
   - GEN-007 full vs incremental computation: identical final state, controlled dirty fractions.
   - GEN-008 recompute vs memoize: varying reuse rates, include lookup/invalidation costs.
5. Add tests and document methodology, actual results, limitations and next questions. Never infer graphics performance from microbenchmarks alone.
6. Update README build/run instructions and roadmap with verified status. Commit coherent changes locally; do not push without user request.

Acceptance: reproducible build and tests, machine-readable benchmark output, correctness checks, measured local results or explicit blockers. Keep scope incremental: prioritize harness and GEN-001–003 before remaining experiments. If time is limited, finish a tested subset and document remaining work.
