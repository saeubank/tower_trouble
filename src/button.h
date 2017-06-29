#include <SDL.h>
#include "ltexture.h"

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class LButton
{
    public:
        //Initializes internal variables
        LButton();

        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        bool handleEvent( SDL_Event* event );

        //Shows button sprite
        void render(LTexture sprite_sheet, SDL_Rect sprites[]);

    private:
        //Top left position
        SDL_Point mPosition;

        //Currently used global sprite
        LButtonSprite mCurrentSprite;
};
