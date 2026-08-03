# Physics Toolkit

A modular physics calculator written in C that solves common kinematics problems.

## Features

### Projectile Motion

- Ground Launch
- Elevated Launch
- Horizontal Launch

Calculates:

- Flight Time
- Maximum Height
- Range
- Horizontal Velocity
- Vertical Velocity

### Free Fall

- Released From Rest
- Initial Downward Velocity
- Initial Upward Velocity
- Ground Level
- Elevated Position

Calculates:

- Time of Fall
- Maximum Height
- Impact Velocity
- Total Flight Time

### Uniform Linear Motion (ULM)

Calculates:

- Distance
- Time
- Velocity

### Uniformly Accelerated Motion (UAM)

Calculates:

- Distance
- Final Velocity
- Acceleration
- Time

## Project Structure

```text
Physics Toolkit v2
│
├── include
│   ├── constants.h
│   ├── free_fall.h
│   ├── input_utils.h
│   ├── linear_motion.h
│   └── projectile_motion.h
│
├── src
│   ├── free_fall.c
│   ├── input_utils.c
│   ├── linear_motion.c
│   ├── main.c
│   └── projectile_motion.c
```

## Concepts Used

This project was developed to practice:

- C Programming
- Functions
- Structures (struct)
- Header Files
- Modular Programming
- Input Validation
- Mathematical Computation
- Git and GitHub Workflow

## Input Validation

Input validation was centralized into a reusable utility module.

Available functions:

```c
double read_positive_double(const char *message);
int read_menu_option(const char *message, int min, int max);
```

These functions improve robustness and reduce duplicated code throughout the project.

## Compilation

Compile the project using GCC:

```bash
gcc main.c projectile_motion.c free_fall.c linear_motion.c input_utils.c -I../include -o physics_toolkit -lm
```

Run:

```bash
./physics_toolkit
```

## Example

```text
Welcome to the Physics Toolkit

(1) Projectile Motion
(2) Free Fall
(3) Uniform Linear Motion
(4) Uniformly Accelerated Motion
(0) Exit
```

## Project Goal

The purpose of this project was to strengthen fundamental C programming skills through the implementation of classical kinematics problems while applying modular software design, input validation, and version control practices.

## Author

Samuel David Medina Contreras

Electronic Engineering Student
Universidad del Magdalena
``