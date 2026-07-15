# ImgView

A low-level image viewer written in C using SDL for rendering and displaying images.

## Features

- Lightweight C implementation.
- Supports PPM image files (more formats planned).

## Build

We will be building this project using CMake:

```bash
git clone --recursive https://github.com/cipherswami/imgview.git
cd imgview
cmake -S . -B build
cmake --build build
```

> The executable will be generated inside the build directory.

## Usage

Pass the path to an image file as a command-line argument:

```bash
build/imgview assets/image.ppm
```

## License

This project is licensed under MIT license. See [LICENSE](./LICENSE) file, for more details.

