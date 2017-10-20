# Tower Trouble

![alt text](https://github.com/swamulism/tower_trouble/blob/master/other/TowerTLogo1.png "Tower Trouble")

- Match 3* Tower Defense
- Language: c++
- Graphics Library: SDL2, OpenGL, SDL2-ttf
- Platform: Computer (Windows, Mac, Linux)
- Additional Dependencies: MySQL, MySQL C++ connector

(to play game compile with makefile)

## Controls
- Q: enter and exit tower placement mode
- W/A/S/D: move tower placement cursor
- ENTER: place tower
- N/M: start a new wave
- SPACE: pause
- ESC: quit game

_Warning: do not block path to exit, game will crash!_

\* Match 3 not included in Alpha

## Requirements

start up local server with SQL and then do ``source .../path-to/tower-trouble/db/init.sql``

Mac:

```
brew install sdl2
brew install sdl2_ttf
brew install freeglut
```

Ubuntu:
```
sudo apt install libsdl2-dev
sudo apt install libsdl2-ttf-dev
sudo apt install freeglut3-dev
```
