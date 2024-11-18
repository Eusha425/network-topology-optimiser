<div align="center">

# Network Topology Optimiser

![Network Topology Optimiser](https://github.com/Eusha425/network-topology-optimiser/blob/master/assets/comparison.png)

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C](https://img.shields.io/badge/C-74.0%25-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Python](https://img.shields.io/badge/Python-26.0%25-blue.svg)](https://www.python.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)

*An advanced network optimisation framework implementing modified MST algorithms for cellular tower placement*

[Features](#-features) •
[Installation](#-installation) •
[Usage](#-usage) •
[Documentation](#-project-structure) •
[Contributing](#-contributing)

</div>

## 📋 Overview

Network Topology Optimiser is a high-performance tool that implements modified versions of Kruskal's and Prim's algorithms to optimise cellular tower networks. The project focuses on handling real-world constraints such as signal interference and operational costs while maintaining optimal network coverage.

### Key Features

- 🚀 **Efficient Implementation**: Optimised MST algorithms for network analysis
- 🎯 **Dual Optimisation**: Handles both interference and cost constraints
- 📊 **Visualization Tools**: Python scripts for network topology analysis
- 🔄 **Flexible Input**: Supports both sparse and dense network configurations

## 🛠️ Prerequisites

- C Compiler (gcc recommended)
- Python 3.x
- Python packages:
  ```bash
  pip install networkx matplotlib numpy pandas
  ```

## 🚀 Installation & Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/Eusha425/network-topology-optimiser.git
   cd network-topology-optimiser
   ```

2. **Compile the C code**
   ```bash
   gcc -O2 -o optimiser main.c graph.c archive.c
   ```

3. **Install required Python packages**
   ```bash
   pip install networkx matplotlib numpy pandas
   ```

## 📊 Usage

### Input Format
The program expects input in the following format:
```
[number_of_vertices]
[source] [destination] [interference] [cost]
...
```

### Running the Program

#### Using Input Redirection (Default Method)
```bash
# For dense networks
./optimiser < input.txt

# For sparse networks
./optimiser < input_sparse.txt
```

#### Alternative Method (File Reading)
If you prefer direct file reading instead of input redirection, you'll need to modify the C code to implement file reading functionality. The main sections that would need modification are:
- `main.c`: Add file handling logic
- `graph.c`: Modify input processing functions

### Generating Test Data
```bash
python main_generator.py
```

### Visualizing Results
```bash
python graph_visual.py    # General network visualization
python kruskal_visual.py  # Kruskal's algorithm results
python prim_visual.py     # Prim's algorithm results
```

## 📁 Project Structure

```
network-topology-optimiser/
├── src/
│   ├── main.c              # Main program implementation
│   ├── graph.c             # Graph implementation and algorithms
│   ├── graph.h             # Graph header file
│   └── archive.c           # Archive utility functions
├── visualization/
│   ├── graph_visual.py     # Network visualization script
│   ├── kruskal_visual.py   # Kruskal's algorithm visualization
│   └── prim_visual.py      # Prim's algorithm visualization
├── data/
│   ├── input.txt           # Dense graph dataset
│   └── input_sparse.txt    # Sparse graph dataset
└── main_generator.py       # Test data generator
```

## 📈 Performance Analysis

### Algorithm Comparison

| Network Type | Vertices | Kruskal (ms) | Prim (ms) |
|-------------|----------|--------------|------------|
| Sparse      | 1000     | 45          | 89         |
| Dense       | 1000     | 156         | 78         |

## 🤝 Contributing

We love your input! We want to make contributing to Network Topology Optimiser as easy and transparent as possible, whether it's:

- Reporting a bug
- Discussing the current state of the code
- Submitting a fix
- Proposing new features
- Becoming a maintainer

Check out our [Contributing Guidelines](CONTRIBUTING.md) for ways to get started.

Please refer to our [Code of Conduct](CONTRIBUTING.md#code-of-conduct) for details on our code of conduct.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
<div align="center">
Made with ❤️ by <a href="https://github.com/Eusha425">Eusha425</a>
</div>
