# Pagmo-NSGA2-Improve-Test

# Initialisation

After cloning, initialize git submodules by:

```
git submodule update --init --recursive
```

# Running the test

- Run CMake target "main"
- The main function runs the NSGA II algorithm on these test suites:
  - ZDT
  - DTLZ

- Population size is 100, generation count is 3500, as set in nsga2Test.h

# NSGA II

NSGA2 has these following features:
- **Multi-objective**
  - Accepts problems with multiple objective functions
  - Searches for approximate "Pareto front" of optimal solutions, where improving one objective functions worsens another objective function

- **Unconstrained**
  - Algorithm designed for unconstrained problems
  - So for example having constraint expressions like: $e(x) < 0$, where $x$ is an individual of the population are not supported

- **Integer programming**
  - Supports problems where individual of the population consists of discrete integer values, instead of vectors of double

![img.png](docs/img.png)

# NSGA II Steps

1. **Initialize**  
   Generate population $P_0$ of size $N$ and evaluate objectives

2. **Non-dominated sorting**  
   Split $P_t$ into Pareto fronts $F_1, F_2, \dots$ by dominance rank

3. **Crowding distance**  
   Compute crowding distance within each front to preserve diversity

4. **Selection**  
   Binary tournament:
    - Prefer lower rank
    - If equal rank, prefer higher crowding distance

5. **Variation**  
   - Apply crossover and mutation to create offspring $Q_t$ (size $N$)
   - Evaluate $Q_t$

6. **Elitist merge**  
   - Form $R_t = P_t \cup Q_t$ (size $2N$)
   - Sort $R_t$ into fronts

7. **Next generation**  
   - Fill $P_{t+1}$ with best fronts
   - If a front overflows, select by descending crowding distance

8. **Repeat**  
   Stop when termination criterion is met
