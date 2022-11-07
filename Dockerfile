# docker build -t prac .
# docker run -it -v $PWD:/prac --name prac prac
# docker start -i prac
FROM debian

WORKDIR /prac

RUN apt-get update

RUN apt-get install gdb gcc g++ make valgrind man -y

CMD ["bash"]