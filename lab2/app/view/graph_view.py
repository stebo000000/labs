import math
import matplotlib


import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.patches import FancyArrowPatch

from app.model import Graph

matplotlib.use("agg")


def _circular_positions(n: int) -> list[tuple[float, float]]:
    """Вершины равномерно по окружности."""
    positions = []
    for i in range(n):
        angle = 2 * math.pi * i / n - math.pi / 2
        positions.append((math.cos(angle), math.sin(angle)))
    return positions


def draw_graph(
    graph: Graph,
    title: str = "Graph",
    highlight_path: list[int] | None = None,
    node_labels: list[str] | None = None,
    show: bool = True,
    ax: plt.Axes | None = None,
) -> plt.Figure | None:
    """
    Отрисовывает граф на основе матрицы смежности.

    :param graph:          объект Graph
    :param title:          заголовок графика
    :param highlight_path: список вершин пути, который нужно выделить
    :param node_labels:    подписи вершин (по умолчанию — номера)
    :param show:           вызывать plt.show() автоматически
    :param ax:             существующие Axes (если None — создаётся новый Figure)
    :return:               Figure
    """
    n = graph.vertices
    pos = _circular_positions(n)
    labels = node_labels or [str(i) for i in range(n)]
    path_edges: set[tuple[int, int]] = set()
    if highlight_path and len(highlight_path) > 1:
        for i in range(len(highlight_path) - 1):
            path_edges.add((highlight_path[i], highlight_path[i + 1]))
            if not graph.directed:
                path_edges.add((highlight_path[i + 1], highlight_path[i]))

    if ax is None:
        fig, ax = plt.subplots(figsize=(7, 7))
    else:
        fig = ax.get_figure()

    ax.set_title(title, fontsize=14, pad=12)
    ax.set_aspect("equal")
    ax.axis("off")

    node_radius = 0.08
    arrow_shrink = node_radius + 0.02

    # --- Рёбра ---
    drawn: set[frozenset] = set()
    for u in range(n):
        for v in range(n):
            w = graph.matrix[u][v]
            if w == 0:
                continue
            # для неориентированных не рисуем дубль
            key = frozenset((u, v))
            if not graph.directed and key in drawn:
                continue
            drawn.add(key)

            x1, y1 = pos[u]
            x2, y2 = pos[v]
            is_path_edge = (u, v) in path_edges

            edge_color = "#e74c3c" if is_path_edge else "#95a5a6"
            lw = 2.5 if is_path_edge else 1.2

            if graph.directed:
                arrow = FancyArrowPatch(
                    posA=(x1, y1),
                    posB=(x2, y2),
                    arrowstyle="-|>",
                    mutation_scale=15,
                    color=edge_color,
                    linewidth=lw,
                    shrinkA=arrow_shrink * 100,
                    shrinkB=arrow_shrink * 100,
                    zorder=1,
                )
                ax.add_patch(arrow)
            else:
                ax.plot(
                    [x1, x2],
                    [y1, y2],
                    color=edge_color,
                    linewidth=lw,
                    zorder=1,
                )

            # подпись веса (если > 1)
            if w != 1:
                mx, my = (x1 + x2) / 2, (y1 + y2) / 2
                ax.text(
                    mx,
                    my,
                    str(w),
                    ha="center",
                    va="center",
                    fontsize=8,
                    color="#555555",
                    bbox=dict(boxstyle="round,pad=0.15", fc="white", ec="none"),
                    zorder=3,
                )

    # --- Вершины ---
    path_set = set(highlight_path) if highlight_path else set()
    for i, (x, y) in enumerate(pos):
        is_path_node = i in path_set
        face_color = "#e74c3c" if is_path_node else "#3498db"
        circle = plt.Circle(
            (x, y),
            node_radius,
            color=face_color,
            zorder=4,
        )
        ax.add_patch(circle)
        ax.text(
            x,
            y,
            labels[i],
            ha="center",
            va="center",
            fontsize=10,
            fontweight="bold",
            color="white",
            zorder=5,
        )

    # --- Легенда ---
    legend_handles = [
        mpatches.Patch(color="#3498db", label="вершина"),
        mpatches.Patch(color="#95a5a6", label="ребро"),
    ]
    if highlight_path:
        legend_handles += [
            mpatches.Patch(color="#e74c3c", label="путь"),
        ]
    ax.legend(handles=legend_handles, loc="upper right", fontsize=9)

    margin = 0.25
    ax.set_xlim(-1 - margin, 1 + margin)
    ax.set_ylim(-1 - margin, 1 + margin)

    if show:
        plt.tight_layout()
        print(123)
        # plt.show()
        plt.savefig("qwe.png")

    return fig
