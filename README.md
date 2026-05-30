# N64 Space MVP

A minimal 2D space shooter homebrew game for the Nintendo 64, developed in C using the modern libdragon toolchain and Docker.

The main objective of this project is educational: learning the basics of N64 programming while maintaining consistent progress, avoiding over-engineering, and delivering a functional Minimum Viable Product (MVP) in a short timeframe.

---

## Tech Stack & Tools
* **Language:** C
* **SDK:** libdragon (via Docker)
* **IDE:** VS Code
* **Recommended Emulator:** Ares, RMG (Rosalie's Mupen GUI), or CEN64

---

## MVP Objectives (Core Gameplay)
- [ ] Player ship (white square) controlled via controller (D-Pad/Analog stick).
- [ ] Screen boundary collision to keep the player within bounds.
- [ ] Firing system (A button) with a fixed maximum pool of active projectiles.
- [ ] Enemies (red squares) descending from the top of the screen in a straight line.
- [ ] Basic AABB collision detection (projectile vs enemy, enemy vs player).
- [ ] Game state management: Main Menu, Gameplay loop, Game Over screen.
