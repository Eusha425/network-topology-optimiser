import networkx as nx
import matplotlib.pyplot as plt

# Read input data from a text file
input_file = "input.txt"
with open(input_file, 'r') as file:
    num_vertices = int(file.readline().strip())
    G = nx.Graph()
    
    while True:
        edge_data = file.readline().strip().split()
        if edge_data[0] == "-1":
            break
        source, destination, weight, cost = map(int, edge_data)
        G.add_edge(source, destination, weight=weight, cost=cost)

# Visualize the graph
pos = nx.spring_layout(G)  # Layout algorithm
edge_labels = {(u, v): f"Weight: {d['weight']}, Cost: {d['cost']}" for u, v, d in G.edges(data=True)}

nx.draw(G, pos, with_labels=True, node_size=500, node_color="skyblue", font_size=10, font_color="black")
nx.draw_networkx_edges(G, pos, edgelist=G.edges(), edge_color="black", width=2)
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color="red")
plt.title("Graph Visualization")
plt.axis("off")  # Turn off axis labels
plt.show()
