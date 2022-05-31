# ses-engine
A casual homemade engine just for fun.

You will need GLFW to run this engine: sudo apt install libglfw3-dev<br />
<br />
Doc: to add a class which has a start, draw and update, it needs to inherit from 'Component'. You also need to instantiate the class in the same file, then include the file in 'scripts.hpp', and register the instance in 'UpdateList.hpp'.<br />
Note: in the small example I made (which you can see just by executing the engine) you can move with W, A, S, D.
<br />
If you want to add a sprite you need to look into 'SpriteList.hpp'.
<br />
Component: the base class from which every base object derives. In fact, this 'engine' is based off an 'ECS' like style. <br />
&nbsp;&nbsp;&nbsp;Methods: <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-StartAll(): calls every base object's 'Start' function. <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-DrawAll(): calls every base object's 'Draw' function. <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-UpdateAll(): calls every base object's 'Update' function. Takes in delta time as its argument. <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-RegisterUpdate(): is needed to register the instance of the object inherited from 'Component', to call its relative update, draw and start functions. Takes in a Component* as its argument. <br />
    <br />
File: class needed to manage file I/O. <br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-File()[Constructor]: it requests the file path and the file mode (the mode whom which the file gets opened, it's an enum) as args.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Append(): used to append text to a file. Takes in an infinite amount of arguments of any type.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Write(): used to overwrite the file with some text. Takes in an infinite amount of arguments of any type.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Set() function and its relative overloads: used to change file path, file mode or both.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Clear(): clears the file content.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-GetContent(): returns the file content.<br />
    <br />
GameObject: game object class.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-GameObject()[Constructor] and its overload: needed to determine the game object shape and size. The overload also requests an image ID (openGL manages textures with IDs such as: GL_TEXTURE_N where N is a number. Arguments: int shape (enum Shape), float x, float y, float z (also int imgID for the overload).<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Set() and its overload: same as the constructors.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Pos(): needed to set the object's position. Arguments: float x, float y, float z.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Render(): needed to render the actual object. This functions NEEDS to be called in 'Draw()'.<br />
<br />
Input: manages the engine's input.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-GetAxis(): (static) needed to get keyboard input and return a float between -1 and 1. Arguments: axis (enum Axis), float returnedAxis. Example: if the axis is 'Horizontal', the function will return the input if the keys 'a' or 'd' are pressed, meaning that 'a' is -1 and 'd' is 1, same for 'Vertical' axis.<br />
    <br />
Math: manages some of the engine's math.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-GetMagnitude2D(): (static) returns the magnitude of a 2D vector. Arguments: NumericType x, NumericType y.<br />
    
    Note: the math.hpp file also provides an implementation of Vector2 and Vector3, with operator overloads.
    
Physics: manages the engine's physics.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-AddForce(): adds forge to a gameobject with force and drag. Arguments: GameObject obj, Vector2 axis (the content of axis is returned by the input class), float force, float drag.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Rotate() and its overload: rotates a gameobject by a certain angle, around a certain axis. The first function only around one axis, the overload takes in three. Arguments: Gameobject obj, float angle, int axis (the overload takes a Vector3 for three axes).<br />
    <br />
Sprite: manages the engine's textures.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Sprite()[Constructor] and its overload: Needed to set the path of an image. In the case of multiple images (overloaded constructor function) it takes a number of textures (remember that openGL uses texture indexes such as GL_TEXTURE_0) and an array of image paths (this is the method used by the engine, given the fact that every gameobject takes in the image ID as the final argument (in the overload), so the images are managed in the 'SpriteList.hpp' file.<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Generate(): used to set all the textures to their IDs (GL_TEXTURE_0 + i where 'i' is an index).<br />
<br />
Shader: manages the engine's shaders.<br />
&nbsp;&nbsp;&nbsp;Methods:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;They are not meant to be accessible by the user.
