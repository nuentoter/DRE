#pragma once
#include <chrono>
#include <cstdint>
#include <string>
#include <vector>
namespace dre {
using Clock = std::chrono::steady_clock;
struct Hardware { unsigned threads; std::string cpu; std::string flags; std::uint64_t ram_bytes; std::string caches; };
Hardware hardware();
double percentile(std::vector<double> samples, double p);
struct Framebuffer {
 unsigned width, height;
 std::vector<std::uint32_t> pixels;
 Framebuffer(unsigned w, unsigned h);
 void pattern(unsigned phase);
};
}
