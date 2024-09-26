<h1 align="center">ft_Printf</h1>
<p align="center"> 
  <img src="https://img.shields.io/badge/grade-100%2F125-green?style=for-the-badge&logo=42&labelColor=gray"/>
</p>

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#01-ft_Printf">
    <img src="https://img.shields.io/badge/Variadic-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Format-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Limitations-blue?style=for-the-badge"/>
  </a>
</p>

<h3>
  <p align="center"> 
    <a href="#introduction">Introduction</a> • 
    <a href="#structure">Structure</a> • 
    <a href="#docs">Docs</a> • 
    <a href="#cloning">Cloning</a> • 
    <a href="#usage">Usage</a> • 
    <a href="#norms">Norms</a> • 
    <a href="#theoretical">Theoretical</a>   
  </p>
</h3>


## 🗣️ Introduction <a id="introduction"></a>

This repository contains the implementation of a custom **printf** function, part of a coding project for the **42 School** program.

The goal of the **ft_printf** project is to recreate the functionality of the standard C **printf** function. This involves handling strings, type conversions, and output formatting in a versatile manner, allowing for a deeper understanding of the internal workings of this common function.

This implementation supports various format specifiers and data types, making it useful for future projects that cannot rely on the standard C library.

## 🧬 Project Structure <a id="structure"></a>

The structure of the project focuses on creating a main function, **ft_printf**, which can handle different data types and formatting, such as **strings**, **integers**, **characters**, and **hexadecimals**. The project is composed of several auxiliary functions that manipulate and format these data types as needed.

<!-- The main components include:
- **Type conversion**: Handling different data types, such as integers and strings.
- **Format specifiers**: Support for various formatting options like `%d`, `%s`, `%x`, among others.
- **Formatted output**: Precise control over data display in standard output. -->

## 🗃️ Documentation <a id="docs"></a>

For detailed documentation, including usage examples, please visit the link below:

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Printf/wiki">
    <img src="https://img.shields.io/badge/ft_Printf_Docs-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 🫥 Cloning the Repository <a id="cloning"></a>

To clone this repository and compile the project, run the following commands:

```bash
git clone https://github.com/pin3dev/42_ft_Printf.git
cd 42_ft_Printf/printf
```
This will download the project from GitHub into your local machine in current directory. Once inside the `printf` directory, you must run make to compile the library.  

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

A `Makefile` is provided to automate the compilation process. It includes the following rules:

- `all`: Compiles the library and generates the `libftprintf.a` file.
- `clean`: Removes object files.
- `fclean`: Removes object files and the library.
- `re`: Recompiles the entire project.
- `test`: Compiles the project and runs the test stored in `test/main.c`

To compile the library, simply run:
```bash
make
```

This will generate the `libftprintf.a` library, which can be linked in other projects to use the **ft_printf** function.

### Basic Usage

To use the **ft_printf** library in your C code, follow the steps below:

1. Include the header in your code:
    ```c
    #include "printf/inc/ft_printf.h"
    ```

2. Compile your code with the library:
    ```bash
    gcc -Wall -Wextra -Werror my_program.c printf/libftprintf.a -o exe_my_program
    ```

3. You can now use the `ft_printf` function in your program as follows:
    ```c
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    ```

<!-- ## 🔠 Format Specifiers

The **ft_printf** project supports the following format specifiers:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a pointer in hexadecimal format.
- `%d`/`%i`: Prints a decimal integer.
- `%u`: Prints an unsigned decimal number.
- `%x`/`%X`: Prints a hexadecimal number (lowercase/uppercase letters).
- `%%`: Prints the percentage symbol. -->

## ⚠️ Norms and Guidelines Disclaimer <a id="norms"></a>

This project strictly follows the [**42 School Norm**](https://github.com/pin3dev/42_Cursus/blob/b9cd0fe844ddb441d0b3efb98abcee92aee49535/assets/General/norme.en.pdf) coding guidelines, which significantly influenced certain decisions in its implementation. These rules may sometimes lead to seemingly inefficient or unusual solutions, but they were necessary to meet the strict requirements of the school.

## 📖 Theoretical Background  <a id="theoretical"></a>

All the theoretical material used to develop this project is organized and can be accessed directly via the link below:

<p align="center"> 
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/library/#01-ft_Printf">
    <img src="https://img.shields.io/badge/ft_Printf_Library-gray?style=for-the-badge"/>
  </a>
</p>
