# LSP Programs

Welcome to **LSP_Programs** — a collection of *Linux System Programming (LSP)* practice programs written in C.  
This repository contains sample implementations of various low-level system programming concepts including file operations, process management, threading, inter-process communication (IPC), and more.

## 📌 Table of Contents
- [About the Project](#about-the-project)
- [📁 Repository Structure](#repository-structure)
- [🧠 Concepts Covered](#concepts-covered)
- [🛠 Building & Running Programs](#building--running-programs)
- [📄 Example Commands](#example-commands)
- [📚 License](#license)
- [🚀 Contributing](#contributing)

---

## 🧾 About the Project

This repository is designed for students and beginners to explore and practice key *Linux System Programming* topics such as:
- Process creation and execution
- File handling and I/O
- Multithreading
- Error handling
- Basic utilities and command examples

Each C program demonstrates a specific concept or test case to enhance hands-on understanding.

---


*Note: Some compiled object files and temporary files may be present — consider adding `.gitignore` to avoid tracking binaries.* :contentReference[oaicite:0]{index=0}

---

## 🧠 Concepts Covered

Here’s a high-level view of topics you’ll find in this repo:

| File / Module | Topic |
|---------------|-------|
| `CapitalProcess.c` | Process manipulation |
| `CommandLine_*.c` | Command line argument parsing |
| `Dup_*.c` | File descriptor duplication |
| `Error_*.c` | Error testing and handling |
| `Multithreading_1.c` | Thread creation & synchronization |
| `Open_*.c` | File opening modes |
| `Read_*.c`, `Write_*.c` | File I/O operations |
| `List.c` | Utility program example |

*(Entire list and coverage can be extended with comments and documentation inside each file.)* :contentReference[oaicite:1]{index=1}

---

## 🛠 Building & Running Programs

To compile and run any C program, ensure you have **GCC** installed:

### Compile Example
```sh
gcc CapitalProcess.c -o CapitalProcess


