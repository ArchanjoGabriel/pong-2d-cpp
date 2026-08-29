# Pong Game

A simple 2D Pong project built with C++ and SFML. The project is intended as a portfolio piece focused on game loop structure, real-time keyboard input, basic rendering, and CMake-based dependency management.

## Overview

This project recreates the foundation of the classic Pong game using SFML for graphics and window management. The current version opens a fixed-size game window, renders two paddles and a ball, and allows both paddles to be controlled from the keyboard.

The codebase is intentionally small and easy to follow, making it a good starting point for demonstrating C++ fundamentals in a game development context.

## Features

- 800x600 SFML render window
- Two-player paddle controls
- Boundary checks to keep paddles inside the screen
- Ball entity rendered as a circle shape
- 60 FPS frame limit
- CMake project setup with SFML fetched automatically through `FetchContent`

## Controls

| Player | Action | Key |
| --- | --- | --- |
| Player 1 | Move up | `W` |
| Player 1 | Move down | `S` |
| Player 2 | Move up | `Up Arrow` |
| Player 2 | Move down | `Down Arrow` |

## Tech Stack

- C++20
- SFML 3.1.0
- CMake 3.28+

## Project Structure

```text
pong-game/
├── CMakeLists.txt
├── include/
│   └── Ball.h
└── src/
    └── main.cpp
```

## Build and Run

### Requirements

- A C++20-compatible compiler
- CMake 3.28 or newer
- Git, required by CMake `FetchContent` to download SFML

### Linux/macOS

```bash
cmake -S . -B build
cmake --build build
./build/pong_game
```

### Windows

```powershell
cmake -S . -B build
cmake --build build
.\build\Debug\pong_game.exe
```

Depending on the selected CMake generator, the executable path may be different, for example `build/Release/pong_game.exe`.

## Current Status

The project currently implements the visual foundation and paddle movement. Gameplay systems such as ball movement, paddle collision, scoring, match reset, sound effects, and menus are natural next steps.

## Roadmap

- Add ball movement and wall bouncing
- Implement paddle collision detection
- Add score tracking
- Reset the ball after each point
- Add a start screen or pause state
- Improve game object organization
- Add sound effects and visual polish

## Portfolio Focus

This project demonstrates:

- Basic C++ game architecture
- Use of SFML shapes and render windows
- Real-time input handling
- Frame-based update and render flow
- CMake dependency setup for a third-party library

