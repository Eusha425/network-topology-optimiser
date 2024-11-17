# Contributing to Network Topology Optimiser

First off, thank you for considering contributing to Network Topology Optimiser! It's people like you that make this tool a brilliant resource for network planning and optimisation.

## Code of Conduct

By participating in this project, you are expected to uphold our Code of Conduct:

- Use welcoming and inclusive language
- Be respectful of differing viewpoints and experiences
- Gracefully accept constructive criticism
- Focus on what is best for the community
- Show empathy towards other community members

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the issue list as you might find out that you don't need to create one. When you are creating a bug report, please include as many details as possible:

* **Use a clear and descriptive title**
* **Describe the exact steps to reproduce the problem**
* **Provide specific examples to demonstrate the steps**
* **Describe the behaviour you observed after following the steps**
* **Explain which behaviour you expected to see instead and why**
* **Include screenshots if possible**

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

* **Use a clear and descriptive title**
* **Provide a step-by-step description of the suggested enhancement**
* **Provide specific examples to demonstrate the steps**
* **Describe the current behaviour and explain which behaviour you expected to see instead**
* **Explain why this enhancement would be useful**

### Pull Requests

1. Fork the repo and create your branch from `master`.
2. If you've added code that should be tested, add tests.
3. If you've changed APIs, update the documentation.
4. Ensure the test suite passes.
5. Make sure your code follows the existing coding style.

## Development Process

### Setting Up Development Environment

1. Install prerequisites:
   ```bash
   # For C development
   sudo apt-get install gcc make

   # For Python development
   pip install networkx matplotlib numpy pandas
   ```

2. Clone the repository:
   ```bash
   git clone https://github.com/Eusha425/network-topology-optimiser.git
   cd network-topology-optimiser
   ```

3. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```

### Coding Style

#### C Code Style

* Use 4 spaces for indentation
* Function names should be in snake_case
* Variable names should be descriptive and in snake_case
* Constants should be in UPPER_SNAKE_CASE
* Include comments for complex logic
* Example:
  ```c
  #define MAX_VERTICES 1000
  
  int calculate_network_cost(Graph* graph, int vertex_count) {
      int total_cost = 0;
      // Calculate total cost logic here
      return total_cost;
  }
  ```

#### Python Code Style

* Follow PEP 8 guidelines
* Use 4 spaces for indentation
* Use descriptive variable names
* Include docstrings for functions and classes
* Example:
  ```python
  def visualise_network(graph_data, output_path):
      """
      Visualise network topology using matplotlib.
      
      Args:
          graph_data (dict): Network topology data
          output_path (str): Path to save visualisation
      """
      # Visualisation logic here
      pass
  ```

### Testing

* Write unit tests for new features
* Ensure all tests pass before submitting PR
* Include both positive and negative test cases
* C tests using Unity framework
* Python tests using pytest

Example test structure:
```
tests/
├── c_tests/
│   ├── test_graph.c
│   └── test_algorithms.c
└── python_tests/
    ├── test_visualisation.py
    └── test_data_processing.py
```

### Documentation

* Update README.md if you change functionality
* Document new functions and classes
* Update API documentation if applicable
* Include examples for new features

### Commit Messages

* Use the present tense ("Add feature" not "Added feature")
* Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
* Limit the first line to 72 characters or less
* Reference issues and pull requests liberally after the first line
* Example:
  ```
  Add network density calculation feature
  
  - Implement density calculation algorithm
  - Add unit tests for density calculation
  - Update documentation with density metrics
  
  Fixes #123
  ```

## Release Process

1. Update version number in relevant files
2. Update CHANGELOG.md
3. Create a new release branch
4. Create and merge release PR
5. Tag the release
6. Update master branch

## Additional Notes

### Issue and Pull Request Labels

* `bug`: Something isn't working
* `enhancement`: New feature or request
* `documentation`: Documentation only changes
* `good first issue`: Good for newcomers
* `help wanted`: Extra attention is needed
* `performance`: Performance-related issues

## Recognition

Contributors who submit PRs that get merged will be added to the Contributors section in the README.md.

## Questions?

Feel free to contact the maintainers if you have any questions. We are here to help!
