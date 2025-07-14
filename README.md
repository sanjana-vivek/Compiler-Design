# Compiler-Design

**Self and university study material** for our compiler design lab course where we build the different stages over multiple thought-out experiments.

---

## Experiment 1: LEXICAL ANALYSER

### Introduction

A lexical analyser is described as the first phase of a compiler. It reads the source code character by character and groups them into meaningful sequences called tokens and this function is termed as tokenization. These tokens represent the fundamental building blocks of a programming language such as keywords, identifiers, operators, punctuation and special symbols. Post the lexical analyser, the token is passed to the next phase of the compiler called the parser.

---

### Aim of this Experiment
To develop a lexical analyzer in C++ that reads a C program and identifies various tokens including:

Keywords
Identifiers
Operators
Special symbols

---

### Source code walkthrough

I created a text file of all cpp keywords so that it's not clustered in the main program inside a single manually defined set. I later used a set and text file class to import the textfile contents into a set.

---

#### `readCppKeywords()`

- The function returns a **set of strings** with all cpp keywords.
- We define a set called **'keywords'** which is gonna store all of the available cpp keywords from the text file imported into the program for the lexer to cross-check and return the keyword count if match found from the source code.
- **`ifstream` or `fstream`** is a class used to read from a text file.
- Here **'file'** is an object of the `ifstream` class and it helps read contents of the text file.
- The **`>>` operator** is known as the stream extraction operator.
  - It reads into a string by skipping leading whitespace (tabs, spaces, newlines).
  - It reads characters one by one into the string **'word'** and stops when it hits the next whitespace.
- The **loop continues** until no more words are left in the file.
- `transform()` helps ensure certain **case-sensitive comparisons** such as `INT` and `int` are treated the same.
- The **lowercase word** is inserted into the set `'keywords'` and finally, the set is returned.
