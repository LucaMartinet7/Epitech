# Epitech — 3 years, 3 campuses, 164 projects

A local mirror of every project repository from my Epitech curriculum (Promo 2027), from the very first `my_putchar` to the End-of-Studies Innovative Project.

| | |
|---|---|
| **Projects** | 164 |
| **Years** | Tek1 → Tek3 (semesters 1–6) |
| **Campuses** | Paris 🇫🇷 → Barcelona 🇪🇸 → Berlin 🇩🇪 |
| **Modules** | 24 distinct (CPE, PSU, MAT, PDG, OOP, FUN, CPP, …) |
| **Languages** | C, C++, Haskell, Python, JS/TS, C#, x86 ASM, Dart, Shell |

---

## Layout

```
tek1/  sem1  sem2      Paris       — 95 projects
tek2/  sem3  sem4      Barcelona   — 50 projects
tek3/  sem5  sem6      Berlin      — 19 projects

<tek>/<sem>/<MODULE>-<project>/
```

Every project was mirrored from its `EpitechPromo2027` repository and then **flattened** into
this one — the per-project `.git` directories were stripped so the source is tracked here
directly and survives whatever happens to my access to that organisation. Individual project
history stays upstream; [`INDEX.md`](INDEX.md) links to each original repo.

125 of the 164 folders contain code. The other 39 are empty upstream — almost all of them
`bs*` bootstrap repos that were handed out but never filled in, so git doesn't track them.

Two generated indexes sit at the root:

- [`INDEX.md`](INDEX.md) — human-readable, grouped by year and semester, with a link back to
  each upstream `EpitechPromo2027/…` repository.
- [`manifest.csv`](manifest.csv) — the same data, machine-readable:
  `repo, path, tek, semester, module, project, campus, group_leader`.

Slice it however you like:

```bash
awk -F, '$5=="CPE"' manifest.csv
```

---

## The journey

### Tek1 — Paris · 95 projects

The C year. It opens with the Bootstrap (`BOO-phoenixd0*`) and the C pool — thirteen days
(`CPE-cpoolday01` … `13`) of building the standard library by hand, since libc is off-limits.
Then the classics: [`my_printf`](tek1/sem1/CPE-myprintf), [`BSQ`](tek1/sem1/CPE-BSQ),
[`push_swap`](tek1/sem1/CPE-pushswap), [`antman`](tek1/sem1/CPE-antman).

**PSU** moves into Unix system programming — [`my_ls`](tek1/sem1/PSU-myls),
[`minishell1`](tek1/sem2/PSU-minishell1) and [`minishell2`](tek1/sem2/PSU-minishell2) —
while **MUL** does graphics with CSFML ([`my_radar`](tek1/sem1/MUL-myradar),
[`my_hunter`](tek1/sem1/MUL-myhunter), [`my_rpg`](tek1/sem2/MUL-myrpg)) and **MAT** works
through applied maths in Python (`101pong` → `110borwein`).

Semester 2 adds the first real teamwork: [`corewar`](tek1/sem2/CPE-corewar) and
[`lem_in`](tek1/sem2/CPE-lemin), a DevOps module ([`popeye`](tek1/sem2/DOP-popeye),
[`chocolatine`](tek1/sem2/DOP-chocolatine)), a first web project
([`epytodo`](tek1/sem2/WEB-epytodo)) and a first taste of security
([`burp`](tek1/sem2/SEC-burp)). **SYN** closes the year with the synthesis projects
([`automakefile`](tek1/sem2/SYN-automakefile), [`sbmlparser`](tek1/sem2/SYN-sbmlparser),
[`FASTAtools`](tek1/sem2/SYN-FASTAtools) and friends), and there are ten solo stumpers on top,
because sleep is optional.

### Tek2 — Barcelona · 50 projects

Semester 3 is the **Haskell pool** — `PDG-PDGD01` through `D13` plus three rushes — which
rewires how you think about state, and the `EPI-hackathonweek`.

Semester 4 is where the language spread explodes:

- **FUN** — functional projects in Haskell: [`wolfram`](tek2/sem4/FUN-wolfram),
  [`compressor`](tek2/sem4/FUN-compressor), [`mypandoc`](tek2/sem4/FUN-mypandoc)
- **OOP** — C++ done properly: [`arcade`](tek2/sem4/OOP-arcade) (runtime-swappable game and
  graphics libraries), [`raytracer`](tek2/sem4/OOP-raytracer),
  [`tekspice`](tek2/sem4/OOP-tekspice)
- **NWP** — network programming: [`myftp`](tek2/sem4/NWP-myftp),
  [`myteams`](tek2/sem4/NWP-myteams)
- **ASM** — [`asm_minilibc`](tek2/sem4/ASM-asmminilibc) in x86-64 assembly
- **YEP** — [`zappy`](tek2/sem4/YEP-zappy), the multi-process, multi-language year-end project
- **MAT** — statistics and probability (`201yams` → `209poll`)

### Tek3 — Berlin · 19 projects

The big-build year. [`R-Type`](tek3/sem5/CPP-rtype) — a networked multiplayer engine in
modern C++ — [`AREA`](tek3/sem5/DEV-area), a full automation platform (web + mobile +
backend), [`survivor`](tek3/sem5/SVR-survivor), and AI/crypto work in **CNA** and **AIA**
([`gomoku`](tek3/sem5/AIA-gomoku), [`neuralnetwork`](tek3/sem5/CNA-neuralnetwork),
[`cryptography`](tek3/sem5/CNA-cryptography)).

Semester 6 is [`EIP`](tek3/sem6/EIP-eip) — the End-of-Studies Innovative Project — and the
Tek3 internship.

---

## Module legend

| Code | Module | Code | Module |
|---|---|---|---|
| `BOO` | Bootstrap | `NWP` | Network Programming |
| `CPE` | C Programming Elementary | `ASM` | Assembly |
| `PSU` | Programming System Unix | `FUN` | Functional Programming |
| `MAT` | Mathematics | `CNA` | Numerical & Applied Algorithmics |
| `MUL` | Multimedia / Graphics | `CPP` | C++ |
| `SYN` | Synthesis | `DEV` | Software Development |
| `AIA` | AI & Algorithmics | `SVR` | Server |
| `DOP` | DevOps | `SEC` | Cybersecurity |
| `WEB` | Web | `YEP` | Year-End Project |
| `PDG` | Paradigms (Haskell pool) | `EIP` | End-of-Studies Innovative Project |
| `OOP` | Object-Oriented Programming | `PRO` / `ENG` | Professional writing & English |

Prefix `bs` (e.g. `CPE-bsdante`) marks a **bootstrap** repo — the graded scaffold handed out
before the project itself.

---

## Working with the mirror

It's one ordinary repository, so normal git commands work from the root. Most C projects
build with a plain `make` inside their folder; the Haskell ones use `stack`/`cabal`, and the
Tek3 projects (`CPP-rtype`, `DEV-area`) ship their own `CMakeLists.txt` / `docker-compose.yml`.

Build output, `node_modules` and a couple of oversized generated test fixtures are
gitignored — expect to regenerate them.

Every project is filed under a **group leader**: 129 under my own login, the remaining 35 under a
teammate's — which is why some folder names map to a repo that isn't `-luca.martinet`. The
mapping is in [`manifest.csv`](manifest.csv).

---

## A note on copying

This is coursework, archived for my own reference and as a record of the path. Epitech runs
plagiarism detection on every submission, and both the copier and the source get sanctioned.
If you're a student here: read it, learn from it, then close the tab and write your own. You
will be a better engineer for it, and neither of us gets a `-42`.

No license is granted for reuse.
