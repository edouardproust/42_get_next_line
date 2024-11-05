clear# 42 school / get_next_line

## Description
- Location: 42 School Barcelona
- Validation: November 2024

The "get_next_line" project at 42 School requires implementing a function that reads a single line from a file descriptor. It must manage multiple calls, handle dynamic memory allocation, and support files of any length. The project tests skills in file handling, memory management, and edge case considerations.

Subject: [ENGLISH](./docs/en.subject.pdf) / [FRENCH](./docs/fr.subject.pdf) / [SPANISH](./docs/es.subject.pdf)

## How to use

1. Clone repo
2. Rename `..gitignore` into `.gitignore`
3. Push to you own repo

=> Only the files requested by the subject will be pushed to the repo.

## Run tests

### Output
```bash
cd test
make test
```
![42 get_next_line make output](https://github.com/user-attachments/assets/0897266a-9390-4e7f-a377-a79399602392)

### Memory leaks check
Tool used: [Valgrind](https://valgrind.org/)
```bash
sudo apt update
sudo apt install valgrind
```
```bash
valgrind --leak-check=full ./gnl
```
![42 get_next_line leaks test valgrind](https://github.com/user-attachments/assets/5c926eca-ff3f-4f0e-b764-d8a1ce38a0fa)

### Moulinette test
Tool used: [Francinette](https://github.com/xicodomingues/francinette)
```bash
paco
```
![42 get_next_line francinette test](https://github.com/user-attachments/assets/a0819972-1505-47db-9c18-b3bffbd2aa1d)
