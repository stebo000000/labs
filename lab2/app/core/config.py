from dataclasses import dataclass, field


@dataclass
class GraphConfig:
    vertices: int = 6
    directed: bool = False
    default_weight: int = 1
    # Рёбра задаются как список кортежей (u, v) или (u, v, weight)
    edges: list = field(
        default_factory=lambda: [
            (0, 1),
            (0, 2),
            (1, 3),
            (2, 3),
            (3, 4),
            (4, 5),
        ]
    )
