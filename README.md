# Pac-Man Game Project in Qt

## Project Description
This project is focused on developing a Pac-Man game using the Qt framework. The goal is to create a fully functional game that replicates the classic Pac-Man experience with modern programming techniques.

## Installation Instructions
To set up and run the game, follow these steps:
1. Clone the repository.
2. Install Qt and Qt Creator from [Qt's official website](https://www.qt.io/).
3. Open the project in Qt Creator and build it.
4. Run the executable to play the game.

## Task Distribution
- **Game Logic (Class `Game`)**: Managed by Person 1.
- **Player Mechanics (Class `Player`)**: Managed by Person 2.
- **Ghost Mechanics (Class `Ghost`)**: Managed by Person 3.
- **Map Generation (Class `Maze`)**: Managed by Person 4.
- **User Interface (Class `UIManager`)**: Managed by Person 5.
- **Audio Management (Class `AudioManager`)**: Managed by Person 6.
- **Score Management (Class `ScoreManager`)**: Managed by Person 7.
- **Configuration Management (Class `ConfigManager`)**: Managed by Person 8.


## Class Structure and TODOs
### Class `Game`
- Initialize and control the main game loop.
- Manage game states (start, pause, end).
- Integrate with the Qt event system.

### Class `Player`
- Implement movement and animations for Pac-Man.
- Handle collisions with ghosts and collect points.
- Implement special effects like power-ups.

### Class `Ghost`
- Implement movement and AI strategies for ghosts.
- Animate and diversify ghost behaviors.
- Handle collisions with Pac-Man.

### Class `Maze`
- Create and load the labyrinth structure.
- Place points and power-ups.
- Handle map collisions and boundaries.

### Class `UIManager`
- Create menus, pause, and end-game screens.
- Display scores and statistics.
- Integrate with the main game loop.

### Class `AudioManager`
- Add sound effects and music.
- Control volume and audio settings.
- Sync audio with in-game actions.

### Class `ScoreManager`
- Responsible for managing game scores, player rankings, and game progress.
- **Integration with SQLite**:
  - Create a SQLite database to store player scores and progress.
  - Implement functions to add, retrieve, and update scores in the database.
  - Ensure data integrity and handle potential database errors.
  - Provide methods for loading and saving game progress.

### Class `ConfigManager`
- Responsible for managing all configuration settings of the game.
- **Key Responsibilities**:
  - Implement a system to store and retrieve game settings (e.g., difficulty level, sound settings, control preferences).
  - Provide functionality to save settings to a file and load them at game startup.
  - Enable in-game customization of settings through a settings menu.
  - Adjust game mechanics and UI elements based on the user's configuration.
  - Offer an API for other game components to access and modify settings.

## Developer Instructions
- Follow the coding style guidelines defined in the project documentation.
- Regularly test your code and ensure it integrates smoothly with other components.
- Document your code thoroughly.

## Pre-commit

Pre-commit is a tool that helps maintain code quality by checking your code before each commit. To set up pre-commit in your project, follow these steps:

1. Install pre-commit. You can do this using pip:

```bash
pip install pre-commit
```
2. Add a .pre-commit-config.yaml file to the root directory of your project. You can configure various hooks in this file.

3. Install the pre-commit hooks:
```bash
pre-commit install
```

4. If you want to manually run all pre-commit hooks on all files, you can use the following command:
```bash
pre-commit run --all-files
```

## Continuous Integration
This project uses Continuous Integration (CI) to automatically build and test the code in this repository. Whenever a commit is made, the CI process triggers and runs the build and test processes.

To see the results of the CI process, check the Actions tab in this github repository.

## Docker

This application can be run using Docker. The Dockerfile in the root directory defines the Docker image.

### Dockerfile

The Dockerfile specifies how to build the Docker image for this application. Here's a brief overview of what it does:

1. `FROM`: This line specifies the base image that we're building from. This is usually an image that includes an operating system and some basic software.

2. `WORKDIR`: This line sets the working directory inside the Docker container. All subsequent commands (like `RUN`, `CMD`, `ENTRYPOINT`, `COPY`, and `ADD`) will be run from this directory.

3. `COPY`: This line copies files from the host machine to the Docker image.

4. `RUN`: This line runs a command in the Docker image. This is usually used to install software.

5. `CMD`: This line provides defaults for an executing container. This can include an executable, or they can omit the executable, in which case you must specify an `ENTRYPOINT` instruction.

### Building the Docker Image

To build the Docker image, navigate to the directory containing the Dockerfile and run the following command:

```bash
docker build -t my-application .
```

### Running the Docker Container

To run the application in a Docker container, use the following command:

```bash
docker run -it -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --name my_app --rm my-application
```

## License and Credits
- This project is licensed under [MIT License](https://opensource.org/licenses/MIT).
- Developed by the Pac-Man Qt Project Team.
