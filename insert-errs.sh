#!/bin/sh

for i in $(seq -10 -1)
do
	echo -n "$i: "
	sudo insmod showerrs.ko errval=$i 2>&1
done

