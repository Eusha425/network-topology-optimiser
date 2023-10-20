import random

def generate_random_input(V, max_edges, max_interference, max_cost, output_file):
    with open(output_file, 'w') as file:
        file.write(f"{V}\n")
        for _ in range(max_edges):
            source = random.randint(0, V - 1)
            destination = random.randint(0, V - 1)
            interference = random.randint(1, max_interference)
            cost = random.randint(1, max_cost)
            file.write(f"{source} {destination} {interference} {cost}\n")
        file.write(f"{-1} {-1} {-1} {-1}\n")
        max_interference = random.randint(1, max_interference)
        max_cost = random.randint(1, max_cost)
        file.write(f"{max_interference}\n")
        file.write(f"{max_cost}\n")

if __name__ == "__main__":
    """ V = int(input("Enter the number of vertices (tower locations): "))
    max_edges = int(input("Enter the maximum number of edges: "))
    max_interference = int(input("Enter the maximum allowed interference: "))
    max_cost = int(input("Enter the maximum allowed cost: "))
    output_file = input("Enter the output file name: ") """

    V = 10000
    max_edges = 1000
    max_interference = 100
    max_cost = 100
    output_file = "input.txt"

    generate_random_input(V, max_edges, max_interference, max_cost, output_file)
