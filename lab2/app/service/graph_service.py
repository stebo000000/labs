from app.model import Graph
from app.core.config import GraphConfig


class GraphService:
    def __init__(self, config: GraphConfig):
        self.config = config
        self.graph = Graph(config.vertices, config.directed)
        for edge in config.edges:
            if len(edge) == 3:
                u, v, w = edge
            else:
                u, v = edge
                w = config.default_weight
            self.graph.add_edge(u, v, w)

    # ------------------------------------------------------------------ #
    #  Обходы                                                              #
    # ------------------------------------------------------------------ #

    def bfs(self, start: int) -> list[int]:
        self.graph._check_vertex(start)
        visited = [False] * self.graph.vertices
        order = []
        queue = [start]
        visited[start] = True
        while queue:
            u = queue.pop(0)
            order.append(u)
            for v in self.graph.neighbors(u):
                if not visited[v]:
                    visited[v] = True
                    queue.append(v)
        return order

    def dfs(self, start: int) -> list[int]:
        self.graph._check_vertex(start)
        visited = [False] * self.graph.vertices
        order = []

        def _dfs(u: int) -> None:
            visited[u] = True
            order.append(u)
            for v in self.graph.neighbors(u):
                if not visited[v]:
                    _dfs(v)

        _dfs(start)
        return order

    # ------------------------------------------------------------------ #
    #  Кратчайший путь (алгоритм Дейкстры)                                #
    # ------------------------------------------------------------------ #

    def shortest_path(self, src: int, dst: int) -> tuple[list[int], int]:
        """Возвращает (path, total_weight). Если пути нет — ([], -1)."""
        n = self.graph.vertices
        self.graph._check_vertex(src)
        self.graph._check_vertex(dst)

        inf = float("inf")
        dist = [inf] * n
        prev = [-1] * n
        visited = [False] * n
        dist[src] = 0

        for _ in range(n):
            # выбираем непосещённую вершину с минимальным dist
            u = min(
                (v for v in range(n) if not visited[v]),
                key=lambda v: dist[v],
                default=None,
            )
            if u is None or dist[u] == inf:
                break
            visited[u] = True
            for v in range(n):
                w = self.graph.matrix[u][v]
                if w != 0 and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    prev[v] = u

        if dist[dst] == inf:
            return [], -1

        path = []
        cur = dst
        while cur != -1:
            path.append(cur)
            cur = prev[cur]
        path.reverse()
        return path, dist[dst]

    # ------------------------------------------------------------------ #
    #  Проверка связности                                                  #
    # ------------------------------------------------------------------ #

    def is_connected(self) -> bool:
        visited = self.bfs(0)
        return len(visited) == self.graph.vertices
