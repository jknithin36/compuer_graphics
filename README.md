# Advanced Computer Graphics - Project 1

## 📚 Overview

This project implements a basic ray tracer that utilizes local shading with **Phong shading** techniques to render a 3D virtual scene. The goal is to showcase smooth shading effects on multiple objects, such as spheres and walls, enhancing the visual realism of the scene.

## HOW TO EXECUTE

### Prerequisites

- Ensure you have the necessary libraries installed, including OpenGL and GLUT.

- As I am using macOS , you may need to install Homebrew and use it to install these libraries.

### Compilation Steps

1. Open your terminal and navigate to the project directory.
2. Use the following command to compile the code:

   ```bash
   g++ -DGL_SILENCE_DEPRECATION -o ray_tracer \
       main.cpp \
       Application.cpp \
       Ray_Tracer.cpp \
       Scene/Scene.cpp \
       Scene/View_plane.cpp \
       primitives/sphere.cpp \
       primitives/triangle.cpp \
       primitives/wall.cpp \
       common/Math3d.cpp \
       -Icommon/ -Iimageio/ -IScene/ -Iprimitives/ \
       -framework OpenGL -framework GLUT
   ```

3. After successful compilation, run the program with:

- ```bash
  ./ray_tracer
  ```

## Execution Screenshot:

![Execution_screenshot](./assets/execution_screenshot.png)

## Output_Image:

![Ray Tracer](./assets/p1_output.png)

## Thank You! 👋

- If you have any questions or issues, feel free to contact me.
