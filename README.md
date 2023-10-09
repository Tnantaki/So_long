# Solong
> This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.
<p align="center">
	<img src="https://github.com/Tnantaki/So_long/blob/master/images/solong1_map.png" />
</p>

---
## 📝Usage
### 1. Requirement
if you run on Linux. Install `x11` by following command.
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
### 2. Compilation
To compile the program, run `make` on **solong** directory.
```bash
$ make
```
### 3. Execution
The program takes 1 argument (map) to execute. run:
```bash
$ ./so_long maps/mos.ber
```
## 🎯Game
- The player’s goal is to collect every collectible present on the map, and then escape by choosing the shortest possible route.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
## 🗺️Map
- The map has to be constructed with 3 components: walls, collectibles, and free space. 
-  The map can be composed of only these 5 characters: 
	- `0` for an empty space,
	- `1` for a wall,
	- `C` for a collectible,
	- `E` for a map exit,
	- `P` for the player’s starting position.
Here is a simple valid map:
<img width="300"  src="https://github.com/Tnantaki/So_long/blob/master/images/simple_map.png" />

- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
## 🎮Key Controls
|Key|Action|
|---|---|
|`ESC`|close the program|
|`W` or `🡡`|move forward|
|`A` or `🡠`|move left|
|`S` or `🡣`|move backward|
|`D` or `🡢`|move  right|

## 📑 Documentation 
* [miniLibx Doc](https://harm-smits.github.io/42docs/libs/minilibx)
