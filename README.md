<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Advanced Computer Graphics - Project 1</title>
    <link href="https://fonts.googleapis.com/css2?family=Roboto+Mono:wght@400;700&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Roboto Mono', monospace;
            line-height: 1.6;
            padding: 20px;
            background-color: #f9f9f9;
            color: #333;
        }
        h1, h2, h3 {
            color: #2c3e50;
        }
        code {
            background-color: #eef;
            padding: 2px 4px;
            border-radius: 3px;
        }
        pre {
            background-color: #eef;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
        img {
            max-width: 100%;
            height: auto;
            display: block;
            margin: 10px 0;
        }
    </style>
</head>
<body>

<h1>Advanced Computer Graphics - Project 1</h1>

<h2>📚 Overview</h2>

<p>This project implements a basic ray tracer that utilizes local shading with <strong>Phong shading</strong> techniques to render a 3D virtual scene. The goal is to showcase smooth shading effects on multiple objects, such as spheres and walls, enhancing the visual realism of the scene.</p>

<h2>HOW TO EXECUTE</h2>

<h3>Prerequisites</h3>
<ul>
    <li>Ensure you have the necessary libraries installed, including OpenGL and GLUT.</li>
    <li>As I am using macOS, you may need to install Homebrew and use it to install these libraries.</li>
</ul>

<h3>Compilation Steps</h3>
<ol>
    <li>Open your terminal and navigate to the project directory.</li>
    <li>Use the following command to compile the code:</li>
    <pre><code>g++ -DGL_SILENCE_DEPRECATION -o ray_tracer \
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
    </code></pre>
    <li>After successful compilation, run the program with:</li>
    <pre><code>./ray_tracer</code></pre>
</ol>

<h2>Execution Screenshot:</h2>
<img src="./assets/execution_screenshot.png" alt="Execution Screenshot">

<h2>Output Image:</h2>
<img src="./assets/p1_output.png" alt="Ray Tracer Output">

</body>
</html>
