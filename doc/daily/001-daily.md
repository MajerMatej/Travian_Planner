# Travian Planner — Initial Architecture Decisions & Next Steps
## 26/6/26

## 1. Project Goal

We are building an offline C++23 desktop application that helps Travian players simulate, analyze, and optimize account progression without interacting with game servers.

**Why:** Ensures the project is strictly a planning/simulation tool and avoids automation or ToS violations.

---

## 2. Core Architectural Philosophy

We prioritize:
- clean architecture
- separation of domain logic and UI
- testability
- deterministic simulation
- low coupling, high cohesion
- composition over inheritance

**Why:** The project is simulation-heavy and long-lived; maintainability and correctness matter more than short-term implementation speed.

---

## 3. High-Level Module Structure

Proposed modules:

- TPCore
- TPRules
- TPAccount
- TPSimulation
- TPPlanning
- TPPersistence
- TPImport
- TPGUI

**Why:** Separating concerns early prevents simulation logic, game rules, and UI from becoming tightly coupled.

---

## 4. Core vs Rules Separation

- TPCore contains generic reusable types (resources, time, math, utilities).
- TPRules contains Travian-specific data and mechanics.

**Why:** Game rules change frequently, while core abstractions should remain stable and reusable.

---

## 5. Account Model (TPAccount)

Represents immutable snapshots of player state:
- villages
- army
- resources
- queues
- progression state

**Why:** Keeps state management separate from simulation logic and avoids mixing computation with data storage.

---

## 6. Simulation Design Direction

TPSimulation will be event-driven:
- actions produce events
- events are processed chronologically
- system is deterministic and reproducible

**Why:** Event-driven simulation scales well with complexity and naturally supports future features like forecasting and planning.

---

## 7. Planning Layer

TPPlanning is separate from simulation and focuses on:
- optimization
- decision making
- strategy evaluation

**Why:** Simulation answers “what happens”, planning answers “what should I do”, which are fundamentally different concerns.

---

## 8. GUI Architecture

TPGUI is a thin layer built on Dear ImGui:
- no business logic
- no simulation logic
- only presentation and user interaction

**Why:** Prevents UI framework from leaking into core domain logic.

---

## 9. Persistence Layer

TPPersistence will handle:
- saving/loading project state
- serialization
- version migration

**Why:** Keeps I/O concerns isolated from domain logic.

---

## 10. Import Layer

TPImport will support future inputs:
- manual entry
- CSV
- OCR
- screenshots (future)

**Why:** Import formats evolve independently of core simulation and must not pollute domain logic.

---

## 11. Directory Structure Strategy

Each module will contain:
- src/
- include/
- tests/

Integration tests will be placed in a global /tests directory.

**Why:** Keeps module-level unit tests close to code while allowing system-level integration tests.

---

## 12. Test Strategy

Two-level testing approach:
- Module tests: fast, isolated, close to code
- Integration tests: cross-module simulation scenarios

**Why:** Simulation correctness requires both local correctness and full-system validation.

---

## 13. CMake Strategy

Each module is a separate library target with explicit dependencies.

**Why:** Makes dependency boundaries enforceable at build level and improves scalability.

---

## 14. Executable Structure

The application entry point is a minimal app module that initializes the system and launches the GUI.

**Why:** Prevents UI logic from becoming the root of the application architecture.

---

## 15. Current Principle for Issue Creation

Each GitHub issue must produce a tangible, demonstrable outcome.

**Why:** Prevents vague tasks and ensures measurable progress.

---

## Next Steps (Tomorrow)

### 1. GitHub Setup
- Create milestones (v0.1 Foundation, v0.2 Simulation, etc.)
- Create labels (core, simulation, rules, gui, etc.)
- Create GitHub Project board (Kanban)

### 2. Initial Backlog
Create first issues:
- repository structure
- CMake skeleton
- module scaffolding
- CI setup
- logging setup
- first ADR

### 3. Architecture Bootstrap
- define module boundaries in code
- create empty library targets
- verify build system works cross-platform

### 4. First Technical Decision
- define initial Resource model (core abstraction)

---

## End of document
