FROM gcr.io/bazel-public/bazel:latest AS build

USER root
RUN apt-get update && apt-get install -y clang

USER ubuntu
WORKDIR /app
ADD . /app/
RUN CC=clang bazel build //web:trundle-web

FROM debian:stable-slim

WORKDIR /app
COPY --from=build /app/bazel-bin/web/trundle-web /

RUN ["chown", "-R", "9000:9000", "/app"]
USER 9000
EXPOSE 8080
ENTRYPOINT [ "/trundle-web" ]