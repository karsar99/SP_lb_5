FROM amazonlinux:latest
RUN yum update -y && yum install gcc-c++ -y
COPY ./prog1.cpp ./prog1.cpp
RUN g++ -pthread prog1.cpp -o program
CMD ./program


