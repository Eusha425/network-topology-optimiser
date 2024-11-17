<div align="center">

# Network Topology Optimiser

![Network Topology Optimiser](https://via.placeholder.com/800x400?text=Network+Topology+Visualisation)

[![Licence](https://img.shields.io/badge/Licence-MIT-blue.svg)](LICENCE)
[![C](https://img.shields.io/badge/C-74.0%25-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Python](https://img.shields.io/badge/Python-26.0%25-blue.svg)](https://www.python.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)

*A sophisticated network optimisation framework for cellular tower placement using advanced MST algorithms*

[Features](#-features) •
[Installation](#-installation) •
[Usage](#-usage) •
[Documentation](#-project-structure) •
[Contributing](#-contributing)

</div>

## 📋 Overview

Network Topology Optimiser is a high-performance tool designed to solve the complex challenge of optimising cellular tower networks. By implementing modified versions of Kruskal's and Prim's algorithms, it tackles real-world constraints such as signal interference and operational costs whilst maintaining optimal network coverage.

### Why Network Topology Optimiser?

- 🚀 **High Performance**: Optimised implementations of MST algorithms
- 🎯 **Dual Optimisation**: Simultaneously handles interference and cost constraints
- 📊 **Visual Analytics**: Built-in visualisation tools for network analysis
- 🔄 **Flexible Architecture**: Supports both sparse and dense network configurations
- 📈 **Scalable Design**: Efficiently handles networks of varying sizes

## 🌟 Features

### Core Functionality
- **Dual-Constraint Optimisation**: Simultaneously optimises for both interference and cost
- **Multiple MST Algorithms**:
  - Modified Kruskal's Algorithm (O(E log V)) for sparse networks
  - Modified Prim's Algorithm (O(V²)) for dense networks
- **Network Visualisation**: Python scripts for visualising network topologies
- **Performance Analysis**: Built-in tools for comparing algorithm performance
- **Flexible Input**: Support for both dense and sparse network configurations

### Optimisation Parameters
- **Interference Management**
  - Signal overlap detection and minimisation
  - Network coverage optimisation
  - Interference-based edge selection
- **Cost Optimisation**
  - Infrastructure cost analysis
  - Secondary cost-based optimisation
  - Efficient resource allocation

## 🚀 Installation

### Prerequisites

```bash
# C Compiler
gcc (or equivalent C compiler)

# Python Requirements (3.x)
pip install networkx matplotlib numpy pandas
```

### Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/network-topology-optimiser.git
cd network-topology-optimiser

# Compile the C code
gcc -O2 -o optimiser main.c graph.c archive.c

# Install Python dependencies
pip install -r requirements.txt
```

## 📊 Usage

### Basic Usage

1. Prepare your network data:
```
[number_of_vertices]
[source] [destination] [interference] [cost]
...
```

2. Run the optimiser:
```bash
# For dense networks
./optimiser input.txt

# For sparse networks
./optimiser input_sparse.txt
```

3. Visualise results:
```bash
python graph_visual.py    # General network visualisation
python kruskal_visual.py  # Kruskal's algorithm results
python prim_visual.py     # Prim's algorithm results
```

## 📁 Project Structure

```
network-topology-optimiser/
├── src/
│   ├── main.c              # Main programme implementation
│   ├── graph.c             # Graph implementation and algorithms
│   ├── graph.h             # Graph header file
│   └── archive.c           # Archive utility functions
├── visualisation/
│   ├── graph_visual.py     # Network visualisation script
│   ├── kruskal_visual.py   # Kruskal's algorithm visualisation
│   └── prim_visual.py      # Prim's algorithm visualisation
├── data/
│   ├── input.txt           # Dense graph dataset
│   └── input_sparse.txt    # Sparse graph dataset
└── docs/
    └── technical_report.pdf
```

## 📈 Performance Analysis

### Algorithm Comparison

| Network Type | Vertices | Kruskal (ms) | Prim (ms) |
|-------------|----------|--------------|------------|
| Sparse      | 1000     | 45          | 89         |
| Dense       | 1000     | 156         | 78         |

### Key Findings
- Kruskal's Algorithm excels in sparse networks
- Prim's Algorithm is optimal for dense networks
- Both algorithms maintain network coverage whilst minimising interference

## 🤝 Contributing

We welcome contributions! Please follow these steps:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📜 Licence

This project is licensed under the MIT Licence - see the [LICENCE](LICENCE) file for details.

## 📚 References

1. Brady, G. (2009). "Pseudocode for Prim's algorithm." Department of Computer Science.
2. "Network Optimisation Techniques in Modern Telecommunications"
3. Wilson, R. J. (2010). "Introduction to Graph Theory", 5th Edition.
4. Graph Theory Applications in Network Design

---
<div align="center">
Made with ❤️ for the network optimisation community
</div>
