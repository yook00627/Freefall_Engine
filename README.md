<img src="ballfalling.png" width="30%">

## Freefall Engine

### Contents

* [Description](https://github.com/yook00627/engine_project#description)
* [Files in This Repository](https://github.com/yook00627/engine_project#files-in-this-repository)
* [Usage](https://github.com/yook00627/engine_project#usage)
* [Technologies](https://github.com/yook00627/engine_project#technologies-used)
* [Authors](https://github.com/yook00627/engine_project#authors)
---

### Description
	
	A 2D game engine that emulates physics. All dependencies and libraries are stored in the Dependencies folder.

### Warning
	The game currently is not framerate locked so the game speed may run diffrently on diffrent systems.


### Files in This Repository

| File                   | File Hierarchy                                       | Description
|------------------------|------------------------------------------------------|--------------------------------------|
|main.cpp | [main.cpp](the_engine/the_engine/main.cpp)  |  Main file  |
| input.cpp  | [input.cpp](the_engine/the_engine/src/input/input.cpp)  |  Inputs class file |
| input.h | [input.h](the_engine/the_engine/src/input/input.h)  | Header for input class file |
| fun.cpp | [fun.cpp](the_engine/the_engine/src/movement/fun.cpp) | Placeholder for header file  |
| fun.h  | [fun.h](the_engine/the_engine/src/movement/fun.h) | Header file for the secret level |
| collision.cpp | [collision.cpp](the_engine/the_engine/src/physics/collision.cpp) | Collision file |
| impulse.cpp | [impulse.cpp](the_engine/the_engine/src/physics/impulse.cpp) | impulse file| 
| physics.cpp | [physics.cpp](the_engine/the_engine/src/physics/physics.cpp) | basics physics file |
| physics.h | [physics.h](the_engine/the_engine/src/physics/physics.h) | header for the physics class |
| circle.cpp | [circle.cpp](the_engine/the_engine/src/shapes/circle.cpp) | Circle class file |
| line.cpp | [line.cpp](the_engine/the_engine/src/shapes/line.cpp) | Line class file |
| rectangle.cpp | [rectangle.cpp](the_engine/the_engine/src/shapes/rectangle.cpp) | Rectangle class file |
| shapes.cpp | [shapes.cpp](the_engine/the_engine/src/shapes/shapes.cpp) | Placeholder file to move all shapes to |
| shapes.h | [shapes.h](the_engine/the_engine/src/shapes/shapes.h) | Header file for all shapes classes |
| triangle.cpp | [trangle.cpp](the_engine/the_engine/src/shapes/triangle.cpp) | Triangle class file |
| text.frag | [text.frag](the_engine/the_engine/src/window/shader/text.frag) | Fragmentation Shader |
| text.vs| [text.vs](the_engine/the_engine/src/window/shader/text.vs) | Vector shader |
| arial.ttf | [arial.ttf](the_engine/the_engine/src/window/arial.ttf) | Font file for text |
| printer.h | [printer.h](the_engine/the_engine/src/window/printer.h) | Header for functions to print game text |
| shader.cpp | [shader.cpp](the_engine/the_engine/src/window/shader.cpp) | Shader class file |
| shader.h | [shader.h](the_engine/the_engine/src/window/shader.h) | Header for shader class file |
| text.cpp | [text.cpp](the_engine/the_engine/src/window/text.cpp) | Shader manipulator to print text and import font |
| text.h  | [text.h](the_engine/the_engine/src/window/text.h) | Header for text file |
| window.cpp | [window.cpp](the_engine/the_engine/src/window/window.cpp) | File for window class |
| window.h  | [window.h](the_engine/the_engine/src/window/window.h) | Header for the window class |

### Usage

For a quick demo of what our engine is capable of, you can play a demo of the engine, run the exe file within this github.

Within the engine, there is a window class that must be instantiated in order to create a window to display the game in. This object requires the namespaces: engine, graphics, and input. The window constructor takes in three arguements: the name of the window, the width, and the height in that order. Within the window object are the programs: closed(), update(), clear(), and windowSizeToggle().

The closed function is a bool that returns true when the window closes and starts the termination function for the program. The update function updates the window and redraws all assets in the window. The clear function clears the window. The windowSizeToggle function switches the window from windowed mode to full screen mode. The general structure of the game state loop with window instantiation is:

```
Window window(Name, 600, 800);

while (!window.closed())
{
	window.clear();
	...
	window.update();
}
```

From printer.h:

To print the press enter screen, use the print_enter function with the inputs of fontsize and the x and y coordinates of where the text should be placed.
To print the number of tries, the print_tries funciton can be used with the inputs of fontsize, the x and y coordinates for where to print the letters, and the number of tries that should be displayed.
To print the level, use the print_level function with the inputs of the fontsize, and the x and y coordinates of where to place them. 

```
print_enter(10, 0.5f, 0.0f);
```
Inputs for the game is handled from the input namespace by instantiating a KeyboardMouse object. Within the namespace are several functions such as key_pressed. This function is a bool that either returns either false or the bool result of the p_keys function with the keycode as the input.  



There are a couple basic shape objects that can be made: Circle, Line, Rectangle, and Triangle. Each shape inherit a BaseShape class that currently contains a physics class called vectors. This physics class contains the position of the shape relative to its midpoint and its velocity and acceleration vector information translated as x and y components. For example, creating a circle object while triggering the default contructor can be done by doing:

```
Circle circle ();
Line line ();
```

To access the physics components, you simply call the object and go throught its vectors class for the component you need.

```
circle.vectors.accel.x;
line.vectors.pos.y;
```

Collision detection is its own class and is currently enabled for line and Circle ojects. The collision object must be instantiated with the circle and line objects and contains a collision checking program called lineCircle that takes in the Circle and Line objects needed to be tested for collision. 

```
Collision test (circle, line);
test.lineCircle(circle, line);
```

The collision detection program is of type bool so it returns either a true or false. If the detection returns a true result, you can resolve the collision with the moving object's resolve_collision function nested within the vectors class. This function takes in the circle object, line object, and collision object tied together. If the circle is the only moving object then you can simple do:

```
circle.resolve_collision(circle, line, test);
```

otherwise, call the line's resolve_collision function to its vectors updated as well.

After the collision has been resolved, you must run every object's update_position function nested within the vectors object. This will update the shape's position based on its current velocity and acceleration vectors. After the position has been updated, call the update function in the window object to redraw where the shapes are.


---

### Technologies Used
* Language: C++, OpenGL
* Operating System: Windows
* CPU supported: Intel I7
---

### Authors

Kevin Yook - [Linkedin](https://www.linkedin.com/in/kevin-yook-82306b98/)

Mitali Sengupta - [Linkedin](https://www.linkedin.com/in/mitali-s-auger/)

Andrew Suh - [Linkedin](https://www.linkedin.com/in/andrew-jung-min-suh/)
