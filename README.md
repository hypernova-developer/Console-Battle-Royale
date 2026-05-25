# Console Battle Royale

A simple, turn-based console tactical combat game developed in C++. Players take turns choosing between attacking, defending, or unleashing their ultimate abilities to deplete their opponent's health pool and win the battle.

## Features

- **Turn-Based System:** Dynamic gameplay mechanics driven by calculated structural rounds.
- **Strategic Actions:** Choose between standard Attack, defensive Mitigation, or high-damage Ultimate abilities.
- **Safe Integer Handling:** Complete validation on unsigned boundaries preventing health point overflow.
- **Asynchronous Delays:** Clean frame-pacing utilizing standard library threading models.

## Architecture & Code Style

The codebase is engineered strictly around the **Allman indentation style** (broken brackets) to ensure clear scope boundaries and maximum code readability. 

- **Language:** C++11 or higher
- **Namespace:** `std`
- **Indentation:** Allman style

## Installation & Compilation

You can easily compile this project using any modern C++ compiler (`g++`, `clang`).

1. Open your favorite terminal (e.g., Zsh / Bash).
2. Run the following compilation command:
   ```bash
   g++ -std=c++11 main.cpp -o ConsoleBattleRoyale
```

