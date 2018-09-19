if test ! -f 12
then
    echo 0 > 12
fi

if ln 12 12.lock
	then                                                                    
	for i in `seq 1 100`;
	do
		endnum=`tail -1 12`
		endnum=$((endnum+1))

		echo $endnum >> 12
	done
	rm 12.lock
fi
