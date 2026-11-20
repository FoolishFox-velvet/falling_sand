# Falling Sand 2D Cellular Automata Simulation

---

## Features

- **2D Grid Space:** $90 \times 150$ cellular grid (`1500x900` window at `10px` cell size) with vertical and randomized diagonal falling rules.
- **Interactive Spawning:** Left-click and drag to emit sand particles directly into the simulation space.
- **Real-Time Controls:** Adjust brush spread range (`1`–`5`) on the fly using the left and right arrow keys.
- **Dynamic Visualization:** Color values shift continuously over time as particles are spawned and rendered per frame.

---

## Controls

| Input | Action |
| :--- | :--- |
| **Left Mouse (Hold)** | Spawn particles |
| **Left / Right Arrow** | Decrease / increase brush range (`1`–`5`) |
| **Esc / Close Window** | Exit simulation |
| **R** | Reset sand positions |

---

## Requirements

- **C++ Compiler:** Supporting C++11 or later.
- **Raylib:** Installed and linked in your development environment.

---

## Building and Running

Compile the code and link it against Raylib. For example, using `g++` on Linux:

```bash
g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o sand_sim
./sand_sim
```

*(Adjust linker flags as needed for your operating system and Raylib setup.)*

---

