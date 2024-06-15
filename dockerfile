FROM ubuntu:20.04
ENV DEBIAN_FRONTEND noninteractiv
RUN apt update -y
RUN apt upgrade -y
RUN apt install build-essential cmake gdb -y
RUN mkdir source