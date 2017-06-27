#include "button.h"
//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

LButton::LButton() {
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y) {
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* event) {
  //If mouse event happened
      if( event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP )
      {
          //Get mouse position
          int x, y;
          SDL_GetMouseState( &x, &y );
          //Check if mouse is in button
          bool inside = true;

          //Mouse is left of the button
          if( x < mPosition.x )
          {
            inside = false;
          }
          //Mouse is right of the button
          else if( x > mPosition.x + BUTTON_WIDTH )
          {
            inside = false;
          }
          //Mouse above the button
          else if( y < mPosition.y )
          {
            inside = false;
          }
          //Mouse below the button
          else if( y > mPosition.y + BUTTON_HEIGHT )
          {
            inside = false;
          }

          if (!inside){
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
          }

          else {
            //Set mouse over sprite
            switch( event->type )
            {
                case SDL_MOUSEMOTION:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;

                case SDL_MOUSEBUTTONDOWN:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

                case SDL_MOUSEBUTTONUP:
                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
          }
      }
}

void LButton::render(){
  //render the current sprite
  gButtonSpriteSheetTexture.render( mPosition.x, mPosition.y, &gSpriteClips[ mCurrentSprite ] );
}
