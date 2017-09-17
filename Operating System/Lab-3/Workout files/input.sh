echo "enter e year number: "
read year

echo "$year"


if [ $((year%4)) -eq 0 ]
then 
	echo "leap year"
else
	echo "not a leap year"
fi
