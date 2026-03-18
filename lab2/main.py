from app.core.config import GraphConfig
from app.service.graph_service import GraphService
from app.view.graph_view import draw_graph


def main() -> None:
    config = GraphConfig(
        vertices=6,
        directed=False,
        default_weight=1,
        edges=[
            (0, 1),
            (0, 2),
            (1, 3),
            (2, 3),
            (3, 4),
            (4, 5),
        ],
    )

    service = GraphService(config)

    print("Матрица смежности:")
    print(service.graph)

    print("\nBFS от вершины 0:", service.bfs(0))
    print("DFS от вершины 0:", service.dfs(0))

    path, weight = service.shortest_path(0, 5)
    print(f"\nКратчайший путь 0 → 5: {path}, суммарный вес: {weight}")

    print("\nГраф связен:", service.is_connected())

    # --- Визуализация ---
    path, _ = service.shortest_path(0, 5)
    draw_graph(
        service.graph,
        title="Граф (матрица смежности)",
        highlight_path=path,
        show=True,
    )


if __name__ == "__main__":
    main()
