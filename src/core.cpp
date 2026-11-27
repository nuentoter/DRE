#include "dre/core.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <thread>
#include <stdexcept>
#include <unistd.h>
namespace dre {
Hardware hardware() {
 Hardware h{std::thread::hardware_concurrency(),{}, {},0,{}};
 std::ifstream f("/proc/cpuinfo"); std::string s;
 while(std::getline(f,s)) {
  auto p=s.find(':'); if(p==std::string::npos) continue;
  if(h.cpu.empty() && s.starts_with("model name")) h.cpu=s.substr(p+1);
  if(h.flags.empty() && s.starts_with("flags")) h.flags=s.substr(p+1);
 }
 auto pages=sysconf(_SC_PHYS_PAGES), size=sysconf(_SC_PAGESIZE);
 if(pages>0 && size>0) h.ram_bytes=std::uint64_t(pages)*std::uint64_t(size);
 std::error_code ec;
 for(const auto& e:std::filesystem::directory_iterator("/sys/devices/system/cpu/cpu0/cache",ec)) {
  std::string level,type,capacity;
  std::ifstream(e.path()/"level")>>level;
  std::ifstream(e.path()/"type")>>type;
  std::ifstream(e.path()/"size")>>capacity;
  if(!level.empty()) h.caches+="L"+level+" "+type+" "+capacity+"; ";
 }
 return h;
}
double percentile(std::vector<double> s,double p) {
 if(s.empty() || !std::isfinite(p) || p<0 || p>1) throw std::invalid_argument("percentile");
 std::sort(s.begin(),s.end());
 return s[static_cast<std::size_t>(p*(s.size()-1))];
}
Framebuffer::Framebuffer(unsigned w,unsigned h):width(w),height(h) {
 if(!w || !h || w>8192 || h>8192) throw std::invalid_argument("framebuffer dimensions");
 pixels.resize(std::size_t(w)*h);
}
void Framebuffer::pattern(unsigned phase) {
 for(unsigned y=0;y<height;++y) for(unsigned x=0;x<width;++x)
 pixels[std::size_t(y)*width+x]=0xff000000u|(((x+phase)&255u)<<16)|((y&255u)<<8)|((x^y)&255u);
}
}
