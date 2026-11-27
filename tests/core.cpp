#include "dre/core.hpp"
#include <stdexcept>
int main(){
 dre::Framebuffer fb(4,3);
 fb.pattern(0);
 if(fb.pixels.size()!=12 || fb.pixels[0]!=0xff000000u || fb.pixels[1]!=0xff010001u) return 1;
 if(dre::percentile({3,1,2},.5)!=2) return 2;
 try {dre::Framebuffer bad(0,1);return 3;} catch(const std::invalid_argument&){}
 return 0;
}
