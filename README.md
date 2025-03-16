---

## 🏆 Project Score: **112/100** 🎉

I successfully completed the `get_next_line` project, including the bonus part handling multiple file descriptors, with an **exceptional score!**

## 📜 What is `get_next_line`?

The `get_next_line` function reads a file **line by line**, handling various file descriptors efficiently.

```c
char *line;
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
```

### 🌟 Key Features:

- **Reads one line at a time** (including `\n`)
- **Efficient buffer management**
- **Handles multiple file descriptors** (Bonus Part ✅)
- **Works on any file, including stdin**

---

## 🏗️ How It Works

1. Uses a **static buffer** to store leftover data between function calls.
2. Reads the file **chunk by chunk** (defined by `BUFFER_SIZE`).
3. Extracts and returns a **single line** on each call.
4. **Frees memory properly** to prevent leaks.

### 🛠️ Core Functions:

| Function                   | Description                               |
| -------------------------- | ----------------------------------------- |
| `get_next_line(int fd)`    | Reads and returns the next line from `fd` |
| `ft_strjoin(s1, s2)`       | Concatenates two strings                  |
| `ft_strchr(s, c)`          | Finds character `c` in string `s`         |
| `ft_strdup(s)`             | Duplicates a string                       |
| `ft_substr(s, start, len)` | Extracts a substring                      |

---

## 🚀 Bonus Part: Handling Multiple File Descriptors

The **bonus part** extends `get_next_line` to handle multiple file descriptors **simultaneously**, ensuring:

- **Independent reading** from different files
- **No data loss between function calls**
- **Smooth performance in multi-file environments**

---

## 🏗️ How to Use

This project includes a `Makefile` for easy compilation.

### 🔹 Compilation
Run the following command to compile:
```sh
make
```
This will generate `get_next_line.a` (static library).

### 🔹 Usage in Your Code
To use `get_next_line`, include the header and link the library:
```c
#include "get_next_line.h"
```
Compile your program with:
```sh
gcc main.c get_next_line.a -o my_program
```

### 🔹 Cleaning
To remove object files and binaries:
```sh
make clean   # Removes object files
make fclean  # Removes object files and library
make re      # Cleans and recompiles everything
```

---

## 📌 Useful Links

📚 **Documentation & References**

- [42 PDF: get\_next\_line Subject](https://cdn.intra.42.fr/pdf/pdf/96258/en.subject.pdf)
- [File Descriptors Explained](https://www.bottomupcs.com/file_descriptors.xhtml)
- [C Library: read()](https://man7.org/linux/man-pages/man2/read.2.html)
- [Memory Management in C](https://www.geeksforgeeks.org/memory-management-c/)

🛠 **Technical Articles & Discussions**

- [How ](https://stackoverflow.com/questions/252782/strtok-vs-strsep)[`get_next_line`](https://stackoverflow.com/questions/252782/strtok-vs-strsep)[ Works](https://stackoverflow.com/questions/252782/strtok-vs-strsep)
- [Handling Multiple FDs](https://medium.com/swlh/handling-multiple-file-descriptors-in-c-4fdf7f50d12)
- [Efficient Buffering Techniques](https://www.cs.tufts.edu/comp/15/resources/buffering.html)

Happy coding! 🚀

