#include "dre/core.hpp"
#include <iostream>
int main(){
 auto h=dre::hardware();
 std::cout<<"CPU: "<<h.cpu<<"\nThreads: "<<h.threads<<"\nRAM bytes: "<<h.ram_bytes<<"\nFlags: "<<h.flags<<"\nCaches: "<<h.caches<<"\n";
 dre::Framebuffer fb(1366,768);
 std::vector<double> times;
 std::uint64_t checksum=0;
 for(unsigned i=0;i<130;++i){
 auto start=dre::Clock::now(); fb.pattern(i);
 auto end=dre::Clock::now();
 for(auto p:fb.pixels) checksum+=p;
 if(i>=10) times.push_back(std::chrono::duration<double,std::milli>(end-start).count());
 }
 std::cout<<"benchmark,width,height,samples,p50_ms,p95_ms,p99_ms,checksum\n";
 std::cout<<"pattern,1366,768,"<<times.size()<<","<<dre::percentile(times,.5)<<","<<dre::percentile(times,.95)<<","<<dre::percentile(times,.99)<<","<<checksum<<"\n";
}
