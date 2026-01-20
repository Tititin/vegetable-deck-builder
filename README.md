# vegetable-deck-builder
SFML/C++ fan adaptation of the game "La fin des artichauts", published by Gigamic

## Disclaimer

This project is an unofficial, non-commercial fan adaptation of the board game
"La fin des artichauts", published by Gigamic.

All rights related to the original game, including its name, rules, artwork,
and overall design, belong to their respective owners.

This repository is shared for educational and personal purposes only.
No copyright infringement is intended.

## v0.1.0-alpha: Initial SFML/C++ Foundation

### Core Features
- **Basic Application Framework** — Fullscreen SFML window (1920×1200) for game rendering
- **Card System** — Interactive card class with:
  - Front/back face display (card flipping)
  - Texture management for card artwork
  - Click handling and callbacks
- **Texture Manager** — Resource loading system for card images (back design, artichoke art, etc.)
- **Input Handling** — Event processing for card interactions and window close (ESC key)

### Architecture
- **Clickable Interface** — Base class for interactive game objects
- **Card Class** — Game card entity with SFML sprite rendering, face state management, and event callbacks
- **TextureManager** — Centralized texture caching and loading

### Assets
- Card image assets in `assets/images/cards/` directory

### Build System
- CMake-based build configuration
- SFML 3.x integration (vcpkg dependency management)
- Cross-platform support (Windows CI/CD pipeline included)

---

**Status:** Proof-of-concept playable foundation with a single interactive card that can be flipped on click. Establishes the core rendering pipeline, resource management, and event handling needed to build out the full deck-builder game.
