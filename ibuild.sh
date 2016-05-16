#! /bin/bash
for (( ;; )); do
	./build.sh && echo OK;
	inotifywait -q *.c *.h;
	clear;
done;
