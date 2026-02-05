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

## v0.3.0-alpha: Card Dragging & Random Generation

### New Features
- **Card Dragging** — Interactive cards can now be dragged around the screen with mouse:
  - Click and hold to drag a card
  - Release to drop at the new position
  - Smooth movement following cursor position
- **Random Card Generation** — New Random utility class for procedural card creation:
  - Seeded random number generator (MT19937)
  - Support for distributed random vegetable selection
- **Multiple Dynamic Cards** — Main application now generates 5 random vegetable cards:
  - Cards automatically positioned in a row on startup
  - Each card has a unique randomly-selected vegetable type
  - Proper initialization and memory management
- **Click State Management** — Enhanced click event handling:
  - Separate tracking of press and release events
  - Click state callbacks for card interactions
  - Proper state cleanup on mouse release

### Architecture Updates
- **Random Utility Class** — Static thread-safe random engine for consistent seeding
- **Card Click Callbacks** — Refactored to use lambda-based callbacks for flexibility
- **Improved Event Handling** — Enhanced mouse event processing with state transitions
- **Potager Card Management** — Support for dynamic card addition with indexed positioning

### Visual Improvements
- **Semi-Transparent Garden Slots** — Slot sprites now render with 25% opacity (alpha=64)
- **Better Visual Feedback** — Click and drag states provide clear interaction feedback

### Bug Fixes
- Proper sprite center alignment during drag operations
- Correct memory cleanup in Potager destructor

### Known Issues
- **Card Sticking on Overlap** — When two cards partially or fully overlap and are clicked simultaneously or in quick succession, they can "snap" together and become difficult or impossible to separate. This occurs due to both cards competing for the mouse position during drag operations. Workaround: Click and drag one card completely away from others before attempting to separate.

---

**Status:** Fully interactive multi-card deck builder with draggable cards and procedural generation. Core gameplay interaction model established, though card overlap collision handling needs refinement in next release to prevent cards from sticking together.

## v0.4.0-alpha: Centralized Input Management & Double-Click Support

### New Features
- **Centralized Input Manager** — New InputManager class for unified event handling:
  - Single point of control for all mouse interactions across clickable objects
  - Automatic registration of interactive elements (cards, deck, etc.)
  - Proper event delegation to appropriate callbacks
- **Double-Click Detection** — Advanced click handling with double-click support:
  - Time-based detection (300ms threshold) for rapid successive clicks on same element
  - Separate callbacks for single-click and double-click actions
  - Prevents accidental multi-clicks and improves user interaction precision
- **Dynamic Card Drawing** — Enhanced Deck system for on-demand card creation:
  - `drawCard()` now instantiates new Card objects dynamically
  - Automatic registration with InputManager for immediate interactivity
  - Proper memory management with deck-owned card lifecycle
  - Visual positioning of drawn cards on screen

### Architecture Updates
- **Clickable Base Class Refinement** — Consolidated sprite management:
  - Moved `sf::Sprite` to base `Clickable` class for inheritance
  - Constructor-based texture initialization for all derived classes
  - Unified interface for position, bounds, and event handling
- **Event Handling Overhaul** — Complete rewrite of input processing:
  - Eliminated individual `handleEvent` implementations in favor of centralized management
  - Callback-based system with support for click, release, and double-click events
  - Improved state management for click states across multiple elements
- **Deck Class Enhancement** — Expanded functionality for card management:
  - Access to InputManager and TextureManager for dynamic operations
  - Container for tracking drawn cards with proper cleanup
  - Integration with input system for seamless card interactions

### Technical Improvements
- **Memory Management** — Robust lifecycle handling:
  - Automatic cleanup of dynamically allocated cards in Deck destructor
  - Prevention of memory leaks from unregistered interactive elements
- **Callback System Expansion** — Flexible event binding:
  - Lambda-based callbacks for all interaction types
  - Support for custom actions on single and double-clicks
  - Easy extensibility for future interaction patterns

### Bug Fixes
- **Input State Conflicts** — Resolved click state synchronization issues:
  - Proper reset of click states when switching between elements
  - Elimination of stuck "pressed" states causing interaction glitches
- **Event Propagation** — Fixed multiple element response problems:
  - Only one element responds to click events at a time
  - Correct release handling for non-targeted elements

---

**Status:** Advanced input system with double-click capabilities and dynamic card instantiation. Foundation laid for complex user interactions and procedural gameplay elements, with robust event management ensuring smooth user experience.