# docker build -t lab .
# docker run -it -v $PWD:/lab --name lab lab
# docker start -i lab
FROM debian

WORKDIR /SPLAB

RUN apt-get update

RUN apt-get install gdb gcc g++ make valgrind man -y

CMD ["bash"]