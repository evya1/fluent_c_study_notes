# Mastering C Code

This repository is dedicated to mastering C programming concepts. Most of the concepts learned here are from the book _Fluent C_ by O'Reilly.

## Table of Contents

-   [Aggregate Instance Pattern](doc/aggregate_instance.md)
-   [What is Makefile ?](doc/makefile.md)

### Makefile

A `Makefile` is a script that automates the compilation and building of a software project. It specifies how to compile source code files and create executable programs.

In this repository and in general, a `Makefile` is used to manage the build process of a project. It typically includes targets for tasks such as compiling source files, linking object files, running tests, and cleaning up build artifacts.

Using a `Makefile` simplifies the process of building and managing complex software projects, allowing developers to automate repetitive tasks and ensure consistent build configurations across different environments.

## Usage of Makefile

### Compiling the Program

To compile the program, navigate to the project directory and run:

```sh
make
```

### Running the Program

To run the compiled program, use:

```sh
make run
```

### Cleaning Up

To remove the compiled executable and clean up the `build` directory, use:

```sh
make clean
```

### Learning Resource

The primary resource for learning C programming concepts in this repository is the book _Fluent C_ by O'Reilly. This book provides in-depth coverage of C programming techniques and best practices.