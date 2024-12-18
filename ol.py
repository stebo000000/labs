class Road:
    def __init__(self):
        self.lenght = int(input())
        self.ball_size = int(input())
        self.block_count = int(input())

        self.blocks_cube_to_delete = []

        self.ignore_space = [0, 0]
        self.is_ignore = False

    def update_by_cube(self, pos: int) -> None:
        if self.is_ignore:
            if pos > self.ignore_space[0] and pos < self.ignore_space[1]:
                pass
            else:
                self.blocks_cube_to_delete.append(pos)
                self.is_ignore = False
        else:
            self.blocks_cube_to_delete.append(pos)

    def update_by_tunnel(self, pos: int, width: int, rad: int) -> None:
        if width < self.ball_size:
            pass
        else:
            self.ignore_space[0] = pos + rad*2
            self.ignore_space[1] = int(pos + rad*4 - width/2)
            self.is_ignore = True

    def print_delete_blocks(self) -> None:
        print()
        print()
        print(len(self.blocks_cube_to_delete))
        for i in self.blocks_cube_to_delete:
            print(i)


road = Road()


for block in range(road.block_count):
    string = input().split(';')
    if len(string) == 2:
        road.update_by_cube(int(string[1]))
    else:
        road.update_by_tunnel(int(string[1]), int(string[2]), int(string[3]))


road.print_delete_blocks()
