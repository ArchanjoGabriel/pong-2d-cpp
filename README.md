# Pong Game

A simple 2D Pong project built with C++ and SFML. The project is intended as a portfolio piece focused on game loop structure, real-time keyboard input, collision detection, scoring, audio feedback, and CMake-based dependency management.

## Overview

This project recreates the foundation of the classic Pong game using SFML for graphics, audio, and window management. The current version opens a fixed-size game window, renders two paddles, moves the ball across the screen, handles paddle and wall collisions, tracks both players' scores, and resets the ball after each point.

The codebase is intentionally small and easy to follow, making it a good starting point for demonstrating C++ fundamentals in a game development context.

## Features

- 800x600 SFML render window
- Two-player paddle controls
- Boundary checks to keep paddles inside the screen
- Ball entity rendered as a circle shape
- Ball movement with vertical wall bouncing
- Paddle collision detection
- Ball speed increase after each paddle hit
- Randomized vertical ball direction when a round starts
- Score display for Player 1 and Player 2
- Ball reset after each scored point
- Short waiting period before each round starts
- Sound effect when the ball hits a paddle
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
├── assets/
│   ├── fonts/
│   │   ├── OFL.txt
│   │   └── PressStart2P-Regular.ttf
│   └── sounds/
│       └── paddleSound.wav
├── include/
│   ├── Ball.h
│   └── variables.h
└── src/
    ├── ball.cpp
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

The project currently implements the core playable Pong loop: two-player paddle movement, ball movement, wall bouncing, paddle collision, score tracking, round reset behavior, and paddle hit sound effects.

## Roadmap

- Add a start screen or pause state
- Add a winning condition and match restart flow
- Improve collision response based on paddle hit position
- Improve game object organization
- Add more sound effects and visual polish
- Add configuration options for speed, score limit, and controls

## Portfolio Focus

This project demonstrates:

- Basic C++ game architecture
- Use of SFML shapes and render windows
- Use of SFML audio and font assets
- Real-time input handling
- Basic collision detection
- Score and round state management
- Frame-based update and render flow
- CMake dependency setup for a third-party library

## Credits

### Font
- Press Start 2P
- Licensed under the SIL Open Font License 1.1

### Sound Effects
- Generated using jsfxr
- https://sfxr.me/
