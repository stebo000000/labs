FROM gcc

# RUN pacman -S gcc

WORKDIR /

COPY ./lab1.cpp /main.cpp

RUN g++ -o myapp main.cpp

CMD ["./myapp"]