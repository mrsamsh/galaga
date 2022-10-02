# Galaga
from orignal coder:

Galaga is a Japanese shoot 'em up arcade game developed and published by Namco Japan and by Midway in North America in 1981.
It is the sequel to 1979's Galaxian.

The objective of Galaga is to score as many points as possible by destroying insect-like enemies.
The player controls a starfighter that can move left and right along the bottom of the playfield.

Enemies swarm in groups in a formation near the top of the screen, and then begin flying down toward the player, firing bullets at and attempting to crash into them.

In later stages, some enemies even break from an entering group in a frantic attempt to crash into the player. The game ends when the player's last fighter is lost by colliding with an enemy, being hit by an enemy shot, or being captured.

I Decided to remake MSX version as i'm learning games programming with SDL & Open GL.

<strong>What I did to the code</strong>

The game didn't work as it uses old OpenGL. Now it runs on mac (at least). Text in the game wasn't showing properly, as SDL_Surface has padding for pixels in each row. I solved this by using glPixelStorei. Also the program depended on Glu and System OpenGL libraries, I substituted that with local GLAD files.

<strong> Required Libraries </strong>
 - SDL2
 - SDL2_image
 - SDL2_mixer
 - SDL2_TTF
 - ~~OpenGL~~ (now completely uses glad instead)
 - ~~Glew~~   (no longer needed)
 - ~~Glu~~    (no longer needed)


 <strong> Build instructions </strong>

	mkdir build
	cd build
	cmake -S ..
	cmake --build .

 <strong> To run the game: </strong>

`./galaga`

