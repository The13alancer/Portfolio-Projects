
---

## `DynamicGroceryList/README.md`

```markdown
# Dynamic Grocery List with Undo – C++ Project

A command-pattern based grocery list tool with **full undo functionality**, implemented in C++ using inheritance and STL data structures. The application supports add, remove, swap, and undo commands with clean separation of state and action.

---

## Features
- Add, remove, and swap grocery items by position
- Undo any of the above operations
- Extensible command system using inheritance
- Vector for item storage + Stack for command history

---

## Design Highlights
- `UndoCommand` base class with `execute()` and `undo()` methods
- Concrete command classes: `InsertAtCommand`, `RemoveLastCommand`, `SwapCommand`
- `GroceryList` class as core data container
- Fully testable via `GroceryListTest.h`

---

## Technologies
- C++
- STL: `vector`, `stack`
- OOP (Inheritance + Composition)

---

## Usage

This is a header-based project. To test, include `GroceryListTest.h` in a main runner:

```cpp
#include "GroceryListTest.h"

int main() {
    runAllTests(); // or custom command simulation
    return 0;
}

