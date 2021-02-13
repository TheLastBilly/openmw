#include <signal.h>

#include <SDL.h>
#include <SDL_video.h>

bool initSDL()
{
#ifndef __HAIKU__
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
    SDL_SetMainReady();
    // Required for determining screen resolution and such on the Graphics tab
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return false;
    }
    signal(SIGINT, SIG_DFL); // We don't want to use the SDL event loop in the launcher,
    // so reset SIGINT which SDL wants to redirect to an SDL_Quit event.
#endif
    return true;
}

void quitSDL()
{
#ifndef __HAIKU__
    // Disconnect from SDL processes
    SDL_Quit();
#endif
}
