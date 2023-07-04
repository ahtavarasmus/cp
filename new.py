from collections import deque

def bfs(graph, start):
    visited = set()  # To keep track of visited nodes
    queue = deque()  # Queue for BFS traversal
    queue.append(start)

    while queue:
        node = queue.popleft()
        if node not in visited:
            print(node)
            visited.add(node)
            neighbors = graph[node]
            for neighbor in neighbors:
                queue.append(neighbor)

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

start_node = 'A'
bfs(graph, start_node)

