from collections import deque

def bfs(graph, source, target, parent):
    visited = [False] * len(graph)
    queue = deque()
    queue.append(source)
    visited[source] = True

    while queue:
        u = queue.popleft()
        for v, capacity, flow in graph[u]:
            if not visited[v] and capacity > flow:
                queue.append(v)
                visited[v] = True
                parent[v] = u
                if v == target:
                    return True

    return False

def edmonds_karp(graph, source, target):
    parent = [-1] * len(graph)
    max_flow = 0

    while bfs(graph, source, target, parent):
        path_flow = float("inf")
        s = target
        while s != source:
            for v, capacity, flow in graph[parent[s]]:
                if v == s:
                    path_flow = min(path_flow, capacity - flow)
                    s = parent[s]
                    break

        s = target
        while s != source:
            for v, capacity, flow in graph[parent[s]]:
                if v == s:
                    graph[parent[s]].remove((v, capacity, flow))
                    graph[parent[s]].append((v, capacity, flow + path_flow))
                    for i, (vv, cc, ff) in enumerate(graph[v]):
                        if vv == parent[s]:
                            graph[v][i] = (vv, cc, ff - path_flow)
                            break
                    s = parent[s]
                    break

        max_flow += path_flow

    return max_flow

# Example graph represented as an adjacency list with capacities and flow
graph = [
    [(1, 10, 0), (2, 10, 0)],                  # Node 0: [(neighbor, capacity, flow), ...]
    [(2, 2, 0), (3, 4, 0)],                    # Node 1
    [(4, 9, 0)],                               # Node 2
    [(2, 6, 0), (5, 10, 0)],                    # Node 3
    [(3, 7, 0), (5, 10, 0)]                     # Node 4
]

source_node = 0
target_node = 5
max_flow = edmonds_karp(graph, source_node, target_node)
print("Maximum flow:", max_flow)
