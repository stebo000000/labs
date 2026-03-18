class Graph:
    def __init__(self, vertices: int, directed: bool = False):
        self.vertices = vertices
        self.directed = directed
        self.matrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u: int, v: int, weight: int = 1) -> None:
        self._check_vertex(u)
        self._check_vertex(v)
        self.matrix[u][v] = weight
        if not self.directed:
            self.matrix[v][u] = weight

    def remove_edge(self, u: int, v: int) -> None:
        self._check_vertex(u)
        self._check_vertex(v)
        self.matrix[u][v] = 0
        if not self.directed:
            self.matrix[v][u] = 0

    def has_edge(self, u: int, v: int) -> bool:
        self._check_vertex(u)
        self._check_vertex(v)
        return self.matrix[u][v] != 0

    def neighbors(self, u: int) -> list[int]:
        self._check_vertex(u)
        return [v for v in range(self.vertices) if self.matrix[u][v] != 0]

    def _check_vertex(self, v: int) -> None:
        if not (0 <= v < self.vertices):
            raise ValueError(f"Vertex {v} is out of range [0, {self.vertices - 1}]")

    def __repr__(self) -> str:
        header = "  " + " ".join(str(v) for v in range(self.vertices))
        rows = [header]
        for i, row in enumerate(self.matrix):
            rows.append(f"{i} " + " ".join(str(w) for w in row))
        return "\n".join(rows)
