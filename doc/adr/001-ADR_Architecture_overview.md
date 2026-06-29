# ADR-0001 — Travian Planner Architecture Overview

## Context

We are building an offline C++23 desktop application for Travian account simulation, planning, and analysis.

The system must support:
- deterministic simulation
- long-term maintainability
- extensibility for future game mechanics
- separation of UI and domain logic
- testability at multiple levels

---

## Decision

We adopt a modular architecture composed of the following components:

### Core Modules

- TPCore — generic reusable types and utilities
- TPRules — game definitions and mechanics
- TPAccount — player state model
- TPSimulation — event-driven deterministic simulation engine
- TPPlanning — optimization and decision-making layer
- TPPersistence — save/load and versioning
- TPImport — external data ingestion
- TPGUI — presentation layer (Dear ImGui)

---

## Key Architectural Rules

### 1. Separation of Concerns
UI, simulation, rules, and persistence must not be coupled.

**Why:** Prevents long-term architectural entanglement.

---

### 2. Event-Driven Simulation
TPSimulation is based on a deterministic event system.

**Why:** Enables reproducibility, forecasting, and scalable complexity.

---

### 3. Account as State Only
TPAccount represents immutable or versioned snapshots of game state.

**Why:** Avoids mixing computation with data storage.

---

### 4. Planning is Separate from Simulation
TPPlanning is not part of simulation execution.

**Why:** Simulation answers “what happens”, planning answers “what should I do”.

---

### 5. GUI is a Thin Layer
TPGUI must not contain business logic.

**Why:** Prevents framework coupling and improves testability.

---

### 6. Module-Based Design with CMake Targets
Each module is a separate library with explicit dependencies.

**Why:** Enforces boundaries at build time.

---

## Consequences

### Positive
- high modularity
- strong testability
- scalable architecture
- clear separation of concerns

### Negative
- slightly higher initial setup cost
- need discipline to avoid cross-module leakage

---

## Alternatives Considered

### Monolithic design
Rejected due to poor scalability and testability.

### UI-driven architecture
Rejected due to coupling risk and simulation complexity.

---

## Related Decisions
- ADR-0002 (Event System Design) — TBD
- ADR-0003 (Rules Data Model) — TBD
- ADR-0004 (Persistence Format) — TBD

---

## Date
2026-06-26
