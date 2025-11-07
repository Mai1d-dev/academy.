# Paroot Library

A simple C library designed to help students learn C programming by providing easy-to-use input functions and utilities.

## Features

- Simple input functions for common data types (int, float, double, long, char, string)
- Array printing utilities
- Automatic input validation and retry prompts
- Easy-to-use Makefile for compiling projects

## Setup Instructions

### Unix/Linux/macOS

#### Prerequisites
- GCC compiler
- Make utility
- Git with SSH setup (required for cloning)

#### Installation Steps

1. Clone this repository:
```bash
git clone git@github.com:funky-bois/academy.git
cd academy
```

**Note:** This repository uses SSH authentication. If you haven't set up SSH keys with GitHub, follow the [GitHub SSH setup guide](https://docs.github.com/en/authentication/connecting-to-github-with-ssh).

2. Build the library:
```bash
make
```

This will create the static library `lib/libparoot.a`.

#### Compiling Your Programs

To compile any C program with the paroot library:

```bash
make path/to/yourfile
```

Examples:
```bash
make test                    # Compiles test.c -> test
make lecture1/hello          # Compiles lecture1/hello.c -> lecture1/hello
make 2025-26/lab1/program    # Compiles 2025-26/lab1/program.c -> 2025-26/lab1/program
```

Then run your program:
```bash
./test
./lecture1/hello
./2025-26/lab1/program
```

### Windows

#### Prerequisites
- MinGW-w64 or TDM-GCC (for GCC on Windows)
- Make utility (comes with MinGW)
- Git with SSH setup (required for cloning)

Or alternatively:
- Visual Studio with C/C++ development tools
- WSL (Windows Subsystem for Linux) - then follow Unix instructions

#### Option 1: Using MinGW/TDM-GCC

1. Install MinGW-w64 or TDM-GCC:
   - Download from [MinGW-w64](https://www.mingw-w64.org/) or [TDM-GCC](https://jmeubank.github.io/tdm-gcc/)
   - Add the `bin` directory to your PATH environment variable

2. Clone this repository:
```cmd
git clone git@github.com:funky-bois/academy.git
cd academy
```

**Note:** This repository uses SSH authentication. If you haven't set up SSH keys with GitHub, follow the [GitHub SSH setup guide](https://docs.github.com/en/authentication/connecting-to-github-with-ssh).

3. Build the library:
```cmd
make
```

4. Compile your programs:
```cmd
make test
test.exe
```

#### Option 2: Using WSL (Recommended)

1. Install WSL2 and a Linux distribution (Ubuntu recommended)
2. Open WSL terminal
3. Install build tools:
```bash
sudo apt update
sudo apt install build-essential
```
4. Clone the repository (requires SSH setup):
```bash
git clone git@github.com:funky-bois/academy.git
cd academy
```

**Note:** If you haven't set up SSH keys with GitHub, follow the [GitHub SSH setup guide](https://docs.github.com/en/authentication/connecting-to-github-with-ssh).

5. Follow the Unix/Linux instructions above

#### Option 3: Manual Compilation (Without Make)

If you don't have Make installed:

1. Compile the library:
```cmd
gcc -Wall -Wextra -std=c11 -pedantic -Ilib -c lib/paroot.c -o lib/paroot.o
ar rcs lib/libparoot.a lib/paroot.o
```

2. Compile your program:
```cmd
gcc -Wall -Wextra -std=c11 -pedantic -Ilib -o yourprogram.exe yourprogram.c -Llib -lparoot
```

3. Run your program:
```cmd
yourprogram.exe
```

## Usage Example

```c
#include <paroot.h>
#include <stdio.h>

int main(void) {
    // Get user input
    int age = get_int("Enter your age: ");
    string name = get_string("Enter your name: ");
    float height = get_float("Enter your height in meters: ");
    
    // Display information
    printf("Hello, %s!\n", name);
    printf("You are %d years old and %.2f meters tall.\n", age, height);
    
    // Array example
    int numbers[] = {1, 2, 3, 4, 5};
    print_array_int(numbers, 5);
    
    return 0;
}
```

Save this as `example.c` and compile:
```bash
make example
./example
```

## Available Functions

### Input Functions
- `char get_char(const char *prompt)` - Get a single character
- `int get_int(const char *prompt)` - Get an integer
- `long get_long(const char *prompt)` - Get a long integer
- `float get_float(const char *prompt)` - Get a float
- `double get_double(const char *prompt)` - Get a double
- `string get_string(const char *prompt)` - Get a string

### Utility Functions
- `void print_array_int(int arr[], size_t length)` - Print integer array
- `void print_array_float(float arr[], size_t length)` - Print float array
- `void print_array_double(double arr[], size_t length)` - Print double array

## Makefile Commands

- `make` - Build the paroot library
- `make <path/to/file>` - Compile any .c file with paroot library
- `make clean` - Remove all build artifacts
- `make help` - Show help message
- `make list-dynamic-targets` - List all compilable C files

## Cleaning Up

To remove all compiled files:
```bash
make clean
```

## Troubleshooting

### Unix/Linux/macOS
- If `make` command is not found, install build tools:
  - Ubuntu/Debian: `sudo apt install build-essential`
  - macOS: `xcode-select --install`
  - Fedora/RHEL: `sudo dnf install gcc make`

### Windows
- If you get "command not found" errors, ensure GCC and Make are in your PATH
- For WSL issues, ensure WSL2 is installed and updated
- If using MinGW, make sure you're using `mingw32-make` instead of `make` if that's the command provided

## License

This library is provided for educational purposes.
