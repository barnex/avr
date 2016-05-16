#! /bin/bash
for (( ;; )); do
	./build.sh;
	inotifywait -q *.c *.h;
	clear;
done;
