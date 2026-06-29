Travian Planner Development Rulebook

> This document defines the engineering conventions and development workflow for Travian Planner.
>
> It is intended to keep the project consistent over time and serve as a reference whenever architectural or workflow decisions are made.

---

# Philosophy

The primary goal of this project is **code quality**, not implementation speed.

When making decisions, prefer:

* Clean architecture
* Separation of concerns
* Testability
* Maintainability
* Deterministic behaviour
* Readability over cleverness
* Composition over inheritance
* Value types where possible
* Modern C++23

Avoid unnecessary abstractions and premature optimization.

---

# Development Workflow

Development is **Issue Driven**.

Every implementation starts with an Issue.

The typical workflow is:

```
Issue
    ↓
Feature Branch
    ↓
Implementation
    ↓
Pull Request
    ↓
Self Review
    ↓
Merge
    ↓
Close Issue
```

Each Pull Request should solve **exactly one logical problem**.

---

# Issue Categories

All work items belong to one of three categories.

## TPF — Feature

Introduces new functionality.

Examples:

* Resource model
* Village model
* Event queue
* Merchant simulation

---

## TPB — Bug

Fixes incorrect behaviour.

A bug should reference the feature or issue where the problem originated whenever possible.

Examples:

* Incorrect crop production
* Overflow in resource calculation
* Incorrect ETA prediction

---

## TPR — Refactoring

Improves the internal implementation without intentionally changing observable behaviour.

Examples:

* Extract common code
* Rename classes
* Reduce coupling
* Improve compile times

Refactoring tasks should never intentionally introduce new functionality.

---

# Numbering

Each category has its own numbering sequence.

Examples:

```
TPF-001
TPF-002

TPB-001

TPR-001
TPR-002
```

The identifier remains stable throughout the lifetime of the task.

---

# Branch Naming

Branches mirror the issue category.

Format:

```
TPF/<number>-<short-description>

TPB/<number>-<short-description>

TPR/<number>-<short-description>
```

Examples:

```
TPF/001-project-structure

TPF/006-resource-model

TPB/003-fix-resource-overflow

TPR/002-split-simulation-module
```

Use lowercase and hyphens for the description.

---

# Commit Messages

Commits reference the issue identifier.

Format:

```
[TPF-001] Initialize project structure

[TPF-006] Add Resource type

[TPB-002] Fix warehouse capacity calculation

[TPR-001] Extract GameTime utilities
```

Commits should describe **what changed**, not how.

---

# Pull Requests

Every Pull Request should:

* correspond to exactly one Issue
* remain focused on a single logical change
* be self-reviewable
* leave the project in a buildable state

At the current stage of the project:

* feature branches are used
* direct commits to `main` are allowed if needed
* branch protection is intentionally disabled
* CI is optional until the project foundation is complete

These rules may evolve as the project grows.

---

# GitHub Workflow

The GitHub Project board is the primary backlog.

Issues should always belong to a milestone when applicable.

Labels are used to classify work, not to define workflow.

Issue dependencies should be expressed using GitHub's linking capabilities instead of relying on numbering conventions.

---

# Milestones

Only one milestone should be actively developed at a time.

Current strategy:

```
v0.1 Foundation
```

Future milestones are created only when the current one approaches completion.

---

# Architecture Documentation

Significant architectural decisions should be documented as ADRs.

Whenever an implementation introduces or changes an architectural decision, one of the following should happen:

* No ADR required
* Existing ADR updated
* New ADR created

Architecture documentation should always reflect the current state of the project.

---

# Testing Philosophy

Two levels of testing are planned.

## Module Tests

Located inside each module.

Purpose:

* verify module behaviour
* validate public interfaces
* remain fast and isolated

---

## Integration Tests

Located in the global `tests/` directory.

Purpose:

* validate collaboration between modules
* execute complete simulation scenarios
* prevent regressions

---

# Module Design

Each module is an independent CMake target.

Typical layout:

```
Module/
├── include/
├── src/
├── tests/
└── CMakeLists.txt
```

Public headers belong in `include/`.

Implementation details remain inside `src/`.

---

# General Principles

When implementing new functionality:

* Design interfaces before implementations.
* Prefer explicit ownership.
* Prefer RAII.
* Prefer `std::span`, `std::optional`, `std::expected` (when available), `std::chrono`, and strong types.
* Avoid raw owning pointers.
* Avoid unnecessary virtual interfaces.
* Avoid macros unless there is no reasonable alternative.
* Avoid introducing design patterns without a clear problem to solve.

---

# Long-Term Goal

Travian Planner should be a project that demonstrates:

* modern C++
* clean software architecture
* deterministic simulation
* professional engineering practices
* maintainable, extensible code suitable for long-term development

