# REngine-2.0

> ⚠️ **Notice**: This repository is a re-upload of an old, archived project. Most of the core functionality is currently unimplemented, and there are many known issues, bugs, and incomplete features that need fixing. It is provided "as-is" for archival and developmental purposes.

REngine-2.0 is a custom 2D game engine written in C++. It was designed with a component-based architecture to handle window management, rendering, physics, and input using standard C++ and OpenGL.

## 🛠️ Current State
* **Status**: Work in Progress / Archival
* The project has recently been updated to successfully compile in Visual Studio (Debug x64), but many internal systems lack full implementation.
* Circular dependencies and header linking issues have been resolved, but runtime stability is not guaranteed.

## 🧱 Architecture & Modules (Partial/Planned)
Based on the current source tree, the engine is split into several core subsystems:
* **Core & Application**: Window generation (Win32 API), Context management, and core types.
* **Input**: Mouse and Keyboard callbacks (`KeyCallback`, mouse position tracking).
* **Graphics**: OpenGL integration via Glad, Shader Programs, Vertex Arrays, Textures (via `stb_image`), and basic UI elements (Buttons, Panels).
* **Physics**: 2D Collision shapes and physics bounds.
* **Engine / Classes**: A component-based object system including `WorldObject`, `SpriteComponent`, and basic `Camera` setup.
* **Maths**: Custom math structures including `Vector2D` and `Transformation2D`.

## 📦 Dependencies
This project tries to keep external dependencies lightweight. Currently, it utilizes:
* **OpenGL** (via `opengl32.lib`)
* **GLAD** (OpenGL loading library)
* **stb_image** (Public domain image loader for textures)
* **Win32 API** (For native Windows window creation and input handling)

## 🚀 Building the Project

If you want to poke around or attempt to fix the engine, here is how to get it compiling:

1. **Environment**: You will need Visual Studio with C++ desktop development workloads installed.
2. **Open the Solution**: Open `REngine-2.0.sln` in Visual Studio.
3. **Configuration**: Set the build configuration to **Debug** and **x64**.
4. **Include Directories**: Ensure the root directory of the project is added to your compiler's include paths.
   * Go to `Project Properties -> C/C++ -> General -> Additional Include Directories`.
   * Add `$(ProjectDir)` (or the exact path to the project root).
5. **Linker Settings**: Ensure `opengl32.lib` is included in your linker dependencies.
6. **Build**: Go to `Build -> Build Solution`.

## 📝 To-Do / Known Issues
- [ ] Implement missing core runtime loops.
- [ ] Fix floating-point precision loss warnings across math structures.
- [ ] Complete the UI rendering pipeline (Buttons/Panels).
- [ ] Finish linking Physics calculations to World Objects.
- [ ] General cleanup of deprecated functions (e.g., POSIX `mkdir` updates).

-Gemini
