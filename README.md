# SMC-Engine 🎮

A custom game engine built from scratch in C++, designed for Windows. This project is a personal deep-dive into game engine architecture — from application lifecycle management to core logging systems.

> ⚠️ **Status: In Development** — Core systems are being implemented incrementally.

---

## 🏗️ Architecture Overview

SMC-Engine follows a layered architecture separating the engine core from client applications:

```
SMC-Engine/
├── SMC/                  # Core engine (compiled as DLL)
│   └── src/SMC/
│       ├── Core.h        # Platform detection & DLL export macros
│       ├── Application.h/cpp  # Base application class & game loop
│       ├── EntryPoint.h  # Engine entry point (main)
│       ├── Log.h/cpp     # Logging system (spdlog)
│       └── SMC.h         # Public engine header
└── Sandbox/              # Client application (uses engine DLL)
    └── src/
        └── SandboxApp.cpp  # Example app inheriting SMC::Application
```

---

## ✅ Implemented Systems

### Application Layer
- Base `SMC::Application` class with a core game loop (`Run()`)
- Client-side `CreateApplication()` factory pattern for extending the engine
- Clean entry point via `EntryPoint.h` — clients never write `main()`

### Logging System
- Dual-logger setup via **spdlog**:
  - `CoreLogger` — internal engine logs (`[SMC]`)
  - `ClientLogger` — application-side logs (`[APP]`)
- Color-coded stdout output with timestamp formatting
- Trace-level logging enabled for full debug visibility

### Platform Layer
- Windows-only support with compile-time enforcement (`#error` on non-Windows)
- DLL build system with `SMC_API` macro (`__declspec(dllexport/dllimport)`)
- `SMC_PLATFORM_WINDOWS` and `SMC_BUILD_DLL` preprocessor flags

---

## 🛠️ Tech Stack

| Tool | Purpose |
|---|---|
| C++17 | Core language |
| spdlog | Logging library |
| Windows API | Platform layer |
| Visual Studio / Premake | Build system |

---

## 🚀 Getting Started

### Prerequisites
- Windows 10/11
- Visual Studio 2022
- C++17 or later

### Build
```bash
git clone https://github.com/LAZARUS-inq/SMC-Engine.git
cd SMC-Engine
# Open .sln in Visual Studio and build in Debug/Release x64
```

### Usage
Create a client app by inheriting `SMC::Application`:

```cpp
#include <SMC.h>

class MyApp : public SMC::Application {
public:
    MyApp() {}
    ~MyApp() {}
};

SMC::Application* SMC::CreateApplication() {
    return new MyApp();
}
```

---

## 🗺️ Roadmap

- [x] Application lifecycle (Init, Run, Shutdown)
- [x] Core logging system (spdlog)
- [x] DLL architecture (Engine / Client separation)
- [ ] Window abstraction layer
- [ ] Event system
- [ ] Input handling
- [ ] Renderer abstraction (OpenGL / DirectX)
- [ ] Layer stack
- [ ] ImGui integration

---

## 📚 Inspiration & References

This engine follows architectural patterns explored in:
- **Game Engine Architecture** — Jason Gregory
- **The Cherno's Hazel Engine** series (YouTube)

---

## 👤 Author

**LAZARUS-inq**
- GitHub: [@LAZARUS-inq](https://github.com/LAZARUS-inq)
- Learning path: Technical Artist → Game Engine Development

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
