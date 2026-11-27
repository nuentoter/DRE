#include "dre/core.hpp"
#include <SDL.h>
#include <iostream>
int main(){
 if(SDL_Init(SDL_INIT_VIDEO)!=0){std::cerr<<SDL_GetError();return 1;}
 auto* w=SDL_CreateWindow("DRE Genesis - CPU framebuffer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1366,768,0);
 if(!w){std::cerr<<SDL_GetError();SDL_Quit();return 1;}
 dre::Framebuffer fb(1366,768);
 auto* src=SDL_CreateRGBSurfaceWithFormatFrom(fb.pixels.data(),1366,768,32,1366*4,SDL_PIXELFORMAT_ARGB8888);
 if(!src){std::cerr<<SDL_GetError();SDL_DestroyWindow(w);SDL_Quit();return 1;}
 bool running=true; unsigned phase=0; int status=0;
 while(running){
 SDL_Event e; while(SDL_PollEvent(&e)) if(e.type==SDL_QUIT || (e.type==SDL_KEYDOWN && e.key.keysym.sym==SDLK_ESCAPE)) running=false;
 if(!running) break;
 fb.pattern(phase++);
 auto* dst=SDL_GetWindowSurface(w);
 if(!dst || SDL_BlitSurface(src,nullptr,dst,nullptr)!=0 || SDL_UpdateWindowSurface(w)!=0){std::cerr<<SDL_GetError();status=1;break;}
 SDL_Delay(16);
 }
 SDL_FreeSurface(src);SDL_DestroyWindow(w);SDL_Quit();return status;
}
