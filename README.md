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

## v0.2.0-alpha: Multi-Card Support & Potager System

### New Features
- **Multiple Card Types** — Support for 12 vegetable types:
  - Artichoke, Onion, Corn, Potato, Eggplant, Peas, Carrot, Broccoli, Leek, Rhubarb, Bell Pepper, Beetroot
- **Vegetable Type System** — Cards now carry a `VegetableType` enum for game logic and identification
- **Second Interactive Card** — Onion card prototype added alongside artichoke
- **Potager (Garden) System** — New class to manage the game board:
  - Slot-based garden layout for card placement
  - Support for multiple interactive elements
  - Rendering management for garden slots
- **Dynamic Positioning** — Cards can be positioned at specific coordinates on screen

### Architecture Updates
- **Card Class Enhancement** — Now tracks vegetable type in addition to visual state
- **Potager Class** — Manages collections of clickable elements and slot rendering
- **Improved Main Loop** — Handles multiple cards and potager rendering

### Assets
- New card texture: Onion (`card_onion`)
- Potager slot texture (`potager_slot`)
- Card image assets in `assets/images/cards/` directory

---

**Status:** Multi-card prototype with basic garden system. Demonstrates handling multiple interactive cards and the foundation for the game board layout where players can plant vegetables.
