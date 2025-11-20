# GameMathLib – Cross-Platform Game Math Library (C++17)

GameMathLib is a **header-only C++17 game math library** focused on vector math, matrix transforms, and collision detection for game development. It is lightweight, fast, cross‑platform, and thoroughly tested with GoogleTest.

---

## 🚀 Features

### **🧮 Vector & Matrix Math**
- `Vector2D` — addition, subtraction, scaling, dot product, normalization  
- `Vector3D` — dot & cross product, normalization, vector operations  
- `Matrix3x3` — 2D affine transforms (rotation, scaling, translation)

### **🎯 Collision Detection**
- `AABB` — Axis‑Aligned Bounding Box intersection tests  
- `Circle` — Circle‑Circle overlap checks  

### **🧪 Strong Testing Foundation**
- GoogleTest unit tests  
- 95%+ code coverage  
- CI‑ready CMake configuration  

### **⚙️ Cross‑Platform Build**
- CMake‑based  
- Builds on **Windows, macOS, Linux**

---

## 📁 Project Structure

```
GameMathLib/
├── CMakeLists.txt
├── include/
│   └── gamemath/
│       ├── Vector2D.h
│       ├── Vector3D.h
│       ├── Matrix3x3.h
│       └── Collision.h
├── examples/
│   └── example_basic.cpp
└── tests/
    └── test_math.cpp
```

---

## 🔧 Building the Library

### **1. Configure the project**

```bash
cmake -S . -B build
```

### **2. Build**

```bash
cmake --build build
```

### **3. Run tests**

```bash
cd build
ctest
```

---

## 📝 Example Usage

```cpp
#include <gamemath/Vector2D.h>
#include <gamemath/Matrix3x3.h>
#include <iostream>

using namespace GameMath;

int main() {
    Vector2D v(3, 4);
    std::cout << "Length: " << v.length() << "\n";

    Matrix3x3 rot = Matrix3x3::rotation(3.14159f / 2);
    Vector2D rotated = rot * v;

    std::cout << "Rotated: (" << rotated.x << ", " << rotated.y << ")\n";
}
```

---

## 🛠 Integrating Into Your Project

```cmake
add_subdirectory(GameMathLib)

add_executable(MyGame main.cpp)
target_link_libraries(MyGame PRIVATE GameMathLib)
```

---

## 📌 Roadmap

- Add ray intersections  
- Add OBB collisions  
- Add 4×4 matrices (3D transforms)  
- Benchmark suite  

---

## 📜 License

This project is released under the **MIT License**.

---

Made with ❤️ for game developers.

